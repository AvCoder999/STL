#include "headers/functions.hpp"
#include <algorithm>
#include <cassert>

namespace my {

template <typename InputIterator, typename Predicate>
typename std::iterator_traits<InputIterator>::difference_type
count_if(InputIterator first, InputIterator last, Predicate pred)
{
    typename std::iterator_traits<InputIterator>::difference_type count = 0;
    for ( ; first != last; ++first) {
        if (pred(*first)) { ++count; }
    }
    return count;
}

template <typename InputIterator, typename Predicate, typename Size>
void 
count_if(InputIterator first, InputIterator last, Predicate pred, Size& n)
{
    for ( ; first != last; ++first) {
        if (pred(*first)) { ++n; }
    }
}

template <typename InputIterator1, typename InputIterator2>
std::pair<InputIterator1, InputIterator2> 
mismatch(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
{
    for ( ; first1 != last1; ++first1) {
        if (*first1 != *first2) { return std::make_pair(first1, first2); }
        ++first2;
    }
    return std::make_pair(last1, first2);
}

template <typename InputIterator1, typename InputIterator2, 
          typename BinaryPredicate>
std::pair<InputIterator1, InputIterator2> 
mismatch(InputIterator1 first1, InputIterator1 last1, 
         InputIterator2 first2, BinaryPredicate binary_pred)
{
    for ( ; first1 != last1; ++first1) {
        if (!binary_pred(*first1, *first2)) { return std::make_pair(first1, first2); }
        ++first2;
    }
    return std::make_pair(last1, first2);
}

template <typename InputIterator1, typename InputIterator2>
bool 
equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
{
    return my::mismatch(first1, last1, first2).first == last1;
    /*
    for ( ; first1 != last1; ++first1) {
        if (*first1 != *first2) { return false; }
    }
    return true;
    */
}

template <typename InputIterator1, typename InputIterator2, 
          typename BinaryPredicate>
bool 
equal(InputIterator1 first1, InputIterator1 last1,
      InputIterator2 first2, BinaryPredicate binary_pred)
{
    return my::mismatch(first1, last1, first2, binary_pred).first == last1;
    /*
    for ( ; first1 != last1; ++first1) {
        if (!binary_pred(*first1, *first2)) { return false; }
    }
    return true;
    */
}


template <typename ForwardIterator1, typename ForwardIterator2>
ForwardIterator1 
search(ForwardIterator1 first1, ForwardIterator1 last1,
       ForwardIterator2 first2, ForwardIterator2 last2)
{
    for ( ; first1 != last1; ++first1) {
        ForwardIterator1 it = first1;
        ForwardIterator2 jt = first2;
        while (it != last1 && jt != last2) {
            if (*it != *jt) { break;}
            ++it;
            ++jt;
        }
        if (jt == last2) { return first1; }
    }
    return last1;
}

template <typename ForwardIterator1, typename ForwardIterator2, typename BinaryPredicate>
ForwardIterator1 
search(ForwardIterator1 first1, ForwardIterator1 last1,
       ForwardIterator2 first2, ForwardIterator2 last2, BinaryPredicate binary_pred)
{
    for ( ; first1 != last1; ++first1) {
        ForwardIterator1 it = first1;
        ForwardIterator2 jt = first2;
        while (it != last1 && jt != last2) {
            if (!binary_pred(*it, *jt)) { break;}
            ++it;
            ++jt;
        }
        if (jt == last2) { return first1; }
    }
    return last1;
}


template <typename ForwardIterator, typename Integer, typename T>
ForwardIterator 
search_n(ForwardIterator first, ForwardIterator last, Integer count, const T& value)
{
    for ( ; first != last; ++first) {
        ForwardIterator it = first;
        Integer j = 0;
        while (it != last && j != count) {
            if (*it != value) { break;}
            ++it;
            ++j;
        }
        if (j == count) { return first; }
    }
    return last;

}

template <typename ForwardIterator, typename Integer, 
          typename T, typename BinaryPredicate>
ForwardIterator 
search_n(ForwardIterator first, ForwardIterator last,
         Integer count, const T& value, BinaryPredicate binary_pred)
{
    for ( ; first != last; ++first) {
        ForwardIterator it = first;
        Integer j = 0;
        while (it != last && j != count) {
            if (!binary_pred(*it, value)) { break;}
            ++it;
            ++j;
        }
        if (j == count) { return first; }
    }
    return last;

}

template <typename ForwardIterator1, typename ForwardIterator2>
ForwardIterator1 
find_end(ForwardIterator1 first1, ForwardIterator1 last1, 
         ForwardIterator2 first2, ForwardIterator2 last2)
{
    ForwardIterator1 res = last1;
    for ( ; first1 != last1; ++first1) {
        ForwardIterator1 it = first1;
        ForwardIterator2 jt = first2;
        while (it != last1 && jt != last2) {
            if (*it != *jt) { break;}
            ++it;
            ++jt;
        }
        if (jt == last2) { res = first1; }
    }
    return res;

}

template <typename ForwardIterator1, typename ForwardIterator2, 
          typename BinaryPredicate>
ForwardIterator1 
find_end(ForwardIterator1 first1, ForwardIterator1 last1, 
         ForwardIterator2 first2, ForwardIterator2 last2,
         BinaryPredicate comp)
{
    ForwardIterator1 res = last1;
    for ( ; first1 != last1; ++first1) {
        ForwardIterator1 it = first1;
        ForwardIterator2 jt = first2;
        while (it != last1 && jt != last2) {
            if (!comp(*it, *jt)) { break;}
            ++it;
            ++jt;
        }
        if (jt == last2) { res = first1; }
    }
    return res;

}


template <typename InputIterator, typename OutputIterator, typename UnaryFunction>
OutputIterator 
transform(InputIterator first, InputIterator last,
          OutputIterator result, UnaryFunction op)
{
    for ( ; first != last; ++first) {
        *result++ = op(*first);
    }
    return result;
    
}


template <typename InputIterator1, typename InputIterator2, 
          typename OutputIterator, typename BinaryFunction>
OutputIterator 
transform(InputIterator1 first1, InputIterator1 last1,
          InputIterator2 first2, OutputIterator result, BinaryFunction binary_op)
{
    for ( ; first1 != last1; ++first1, ++first2) {
        *result++ = binary_op(*first1, *first2);
    }
    return result;
}

template <typename ForwardIterator, typename Predicate, typename T>
void 
replace_if(ForwardIterator first, ForwardIterator last, Predicate pred, const T& new_value)
{
    for ( ; first != last; ++first) {
        if (pred(*first)) { *first = new_value; }
    }
}

template <typename InputIterator, typename OutputIterator, 
          typename Predicate, typename T>
OutputIterator 
replace_copy_if(InputIterator first, InputIterator last,
                OutputIterator result, Predicate pred, const T& new_value)
{
    for ( ; first != last; ++first) {
        *result++ = (pred(*first) ? new_value : *first);
    }
    return result;
}


template <typename ForwardIterator, typename Generator>
void 
generate(ForwardIterator first, ForwardIterator last, Generator gen)
{
    for ( ; first != last; ++first) {
        *first = gen();
    }
}

template <typename OutputIterator, typename Size, typename Generator>
OutputIterator 
generate_n(OutputIterator first, Size n, Generator gen)
{
    for (Size i = 0; i < n; ++i) {
        *first++ = gen();
    }
    return first;
}

template <typename ForwardIterator, typename Predicate>
ForwardIterator 
remove_if(ForwardIterator first, ForwardIterator last, Predicate pred)
{
    ForwardIterator it = first;
    while (it != last) {
        if (pred(*it)) {
            ++it;
            continue;
        }
        *first++ = *it++;
    }
    return first;
}

template <typename InputIterator, typename OutputIterator, typename Predicate>
OutputIterator 
remove_copy_if(InputIterator first, InputIterator last,
               OutputIterator result, Predicate pred)
{
    for ( ; first != last; ++first) {
        if (!pred(*first)) {
            *result++ = *first;
        }
    }
    return result;
}

template <typename ForwardIterator>
ForwardIterator 
unique(ForwardIterator first, ForwardIterator last)
{
    if (first == last) { return last; }
    ForwardIterator next = first;
    ++next;
    for ( ; next != last; ) {
        if (*next == *first) { ++next; continue; }
        ++first;
        *first = *next;
    }
    return ++first;
}

template <typename ForwardIterator, typename BinaryPredicate>
ForwardIterator 
unique(ForwardIterator first, ForwardIterator last, BinaryPredicate binary_pred)
{
    if (first == last) { return last; }
    ForwardIterator next = first;
    ++next;
    for ( ; next != last; ) {
        if (binary_pred(*next, *first)) { ++next; continue; }
        ++first;
        *first = *next;
    }
    return ++first;

}

template <typename InputIterator, typename OutputIterator>
OutputIterator 
unique_copy(InputIterator first, InputIterator last, OutputIterator result)
{
    if (first == last) { return result; }
    *result = *first++;
    for ( ; first != last; ++first) {
        if (*first == *result) { continue; }
        *(++result) = *first;
    }
    return ++result;
}

template <typename InputIterator, typename OutputIterator, typename BinaryPredicate>
OutputIterator 
unique_copy(InputIterator first, InputIterator last, OutputIterator result, BinaryPredicate binary_pred)
{
    if (first == last) { return result; }
    *result = *first++;
    for ( ; first != last; ++first) {
        if (!binary_pred(*first, *result)) {
            *(++result) = *first;
        }
    }
    return ++result;

}


template <typename RandomAccessIterator>
void 
random_shuffle(RandomAccessIterator first, RandomAccessIterator last)
{
    typename std::iterator_traits<RandomAccessIterator>::difference_type size = last - first;
    for (RandomAccessIterator it = first; it != last; ++it) {
         RandomAccessIterator jt = first + ::rand() % size;
         std::iter_swap(it, jt);
    } 
}

template <typename RandomAccessIterator, typename RandomNumberGenerator>
void 
random_shuffle(RandomAccessIterator first, RandomAccessIterator last,
               RandomNumberGenerator& randFunctor)
{
    typename std::iterator_traits<RandomAccessIterator>::difference_type size = last - first;
    for (RandomAccessIterator it = first; it != last; ++it) {
         RandomAccessIterator jt = first + randFunctor(size);
         std::iter_swap(it, jt);
    } 
}

template <typename InputIterator, typename RandomAccessIterator>
RandomAccessIterator 
random_sample(InputIterator first, InputIterator last,
              RandomAccessIterator ofirst, RandomAccessIterator olast)
{
    RandomAccessIterator it = ofirst;
    for ( ; first != last && it < olast; ++it, ++first) {
        *it = *first;        
        if (it != ofirst) {
            RandomAccessIterator jt = ofirst + ::rand() % (it - ofirst);
            std::iter_swap(it, jt);
        }
    }
    return it;
}

template <typename InputIterator, typename RandomAccessIterator,
	      typename RandomNumberGenerator>
RandomAccessIterator 
random_sample(InputIterator first, InputIterator last,
              RandomAccessIterator ofirst, RandomAccessIterator olast,
              RandomNumberGenerator& randFunctor)
{
    RandomAccessIterator it = ofirst;
    for ( ; first != last && it < olast; ++it, ++first) {
        *it = *first;        
        if (it != ofirst) {
            RandomAccessIterator jt = ofirst + randFunctor(it - ofirst);
            std::iter_swap(it, jt);
        }
    }
    return it;
}

template <typename ForwardIterator, typename OutputIterator, typename Distance>
OutputIterator 
random_sample_n(ForwardIterator first, ForwardIterator last,
                OutputIterator out, Distance n)
{
    OutputIterator begin = out;
    for (Distance i = 0; first != last && i < n; ++i, ++first, ++out) {
        *out = *first;        
        if (out != begin) {
            OutputIterator jt = begin;
            std::advance(jt, ::rand() % i);
            std::iter_swap(out, jt);
        }
    }
    return out;
}

template <typename ForwardIterator, typename OutputIterator, 
          typename Distance, typename RandomNumberGenerator>
OutputIterator 
random_sample_n(ForwardIterator first, ForwardIterator last,
                OutputIterator out, Distance n, RandomNumberGenerator& randFunctor)
{
    OutputIterator begin = out;
    for (Distance i = 0; first != last && i < n; ++i, ++first, ++out) {
        *out = *first;        
        if (out != begin) {
            OutputIterator jt = begin;
            std::advance(jt, randFunctor(i));
            std::iter_swap(out, jt);
        }
    }
    return out;
}


template <typename ForwardIterator, typename Predicate>
ForwardIterator 
partition(ForwardIterator first, ForwardIterator last, Predicate pred)
{
    ForwardIterator left = first;
    ForwardIterator right = first;

    while (right != last) {
        if (!pred(*right)) {
            ++right;
            continue;
        } 
        if (left != right) {
            std::iter_swap(left, right);
        }
        ++left; 
        ++right;
    }
    return left; 
}

template <typename ForwardIterator, typename Predicate>
ForwardIterator 
stable_partition(ForwardIterator first, ForwardIterator last, Predicate pred)
{
    ForwardIterator left = first;
    ForwardIterator right = first;
    typedef typename std::iterator_traits<ForwardIterator>::value_type Type;
                          
    while (right != last) {
        if (!pred(*right)) {
            ++right;
            continue;
        } 
        if (left != right) {
            ForwardIterator it = left;
            ForwardIterator next = it;
            ++next;
            Type value = *left;
            Type nextValue = *next;
            *left = *right;
            while (next != right) {
               nextValue = *next;
               *next = value;
               value = nextValue;
               ++it; ++next;
            }
            *right = value;
        }
        ++left; 
        ++right;
    }
    return left; 
}


template <typename ForwardIterator, typename LessThanComparable>
ForwardIterator 
lower_bound(ForwardIterator first, ForwardIterator last, const LessThanComparable& value)
{
    for ( ; first != last; ++first) {
        if (*first >= value) { return first; }
    }
    return last;
}

template <typename ForwardIterator, typename T, typename StrictWeakOrdering>
ForwardIterator 
lower_bound(ForwardIterator first, ForwardIterator last,
            const T& value, StrictWeakOrdering comp)
{
    for ( ; first != last; ++first) {
        if (!comp(*first, value)) { return first; }
    }
    return last;
}

template <typename ForwardIterator, typename LessThanComparable>
ForwardIterator 
upper_bound(ForwardIterator first, ForwardIterator last, const LessThanComparable& value)
{
    for ( ; first != last; ++first) {
        if (*first > value) { return first; }
    }
    return last;
}

template <typename ForwardIterator, typename T, typename StrictWeakOrdering>
ForwardIterator 
upper_bound(ForwardIterator first, ForwardIterator last, const T& value, StrictWeakOrdering comp)
{
    for ( ; first != last; ++first) {
        if (comp(value, *first)) { return first; }
    }
    return last;
}

template <typename ForwardIterator, typename LessThanComparable>
std::pair<ForwardIterator, ForwardIterator>
equal_range(ForwardIterator first, ForwardIterator last, const LessThanComparable& value)
{
    return std::make_pair(my::lower_bound(first, last, value), my::upper_bound(first, last, value));
}

template <typename ForwardIterator, typename T, typename StrictWeakOrdering>
std::pair<ForwardIterator, ForwardIterator>
equal_range(ForwardIterator first, ForwardIterator last, const T& value, StrictWeakOrdering comp)
{
    return std::make_pair(my::lower_bound(first, last, value, comp), my::upper_bound(first, last, value, comp));
}

template <typename InputIterator1, typename InputIterator2, typename OutputIterator>
OutputIterator 
merge(InputIterator1 first1, InputIterator1 last1,
      InputIterator2 first2, InputIterator2 last2, OutputIterator result)
{
    while (first1 != last1 && first2 != last2) {
        if (*first1 < *first2) { *result++ = *first1++; continue; }
        if (*first2 < *first1) { *result++ = *first2++; continue; }
        *result++ = *first1++;
        *result++ = *first2++;
    }
    while (first1 != last1) { *result++ = *first1++; }
    while (first2 != last2) { *result++ = *first2++; }
    return result;
}

template <typename InputIterator1, typename InputIterator2, 
          typename OutputIterator, typename StrictWeakOrdering>
OutputIterator 
merge(InputIterator1 first1, InputIterator1 last1,
      InputIterator2 first2, InputIterator2 last2,
      OutputIterator result, StrictWeakOrdering comp)
{
    while (first1 != last1 && first2 != last2) {
        if (comp(*first1, *first2)) { *result++ = *first1++; continue; }
        if (comp(*first2, *first1)) { *result++ = *first2++; continue; }
        *result++ = *first1++;
        *result++ = *first2++;
    }
    while (first1 != last1) { *result++ = *first1++; }
    while (first2 != last2) { *result++ = *first2++; }
    return result;
}

template <typename BidirectionalIterator>
inline void 
inplace_merge(BidirectionalIterator first, BidirectionalIterator middle, BidirectionalIterator last)
{
    typedef typename std::iterator_traits<BidirectionalIterator>::value_type Type;
    while (first != middle && middle != last) {
        if (*first <= *middle) {
            ++first; 
            continue;
        }
        Type value = *middle;
        BidirectionalIterator counter = middle;
        BidirectionalIterator prev = counter;
        --prev;
        
        while (counter != first) {
            *counter = *prev;
            --counter;
            --prev;
        }
        *first = value;

        ++first;
        ++middle;
    }
}

template <typename BidirectionalIterator, typename StrictWeakOrdering>
inline void 
inplace_merge(BidirectionalIterator first, BidirectionalIterator middle,
              BidirectionalIterator last, StrictWeakOrdering comp)
{
    typedef typename std::iterator_traits<BidirectionalIterator>::value_type Type;
    while (first != middle && middle != last) {
        if (comp(*first, *middle)) {
            ++first; 
            continue;
        }
        Type value = *middle;
        BidirectionalIterator counter = middle;
        BidirectionalIterator prev = counter;
        --prev;
        
        while (counter != first) {
            *counter = *prev;
            --counter;
            --prev;
        }
        *first = value;

        ++first;
        ++middle;
    }
}


template <typename inputiterator1, typename inputiterator2>
bool 
includes(inputiterator1 first1, inputiterator1 last1, inputiterator2 first2, inputiterator2 last2)
{
    while (first1 != last1 && first2 != last2) {
        if (*first1 == *first2) { ++first2; }
        ++first1;
    }
    return first2 == last2;
}

template <typename InputIterator1, typename InputIterator2, typename StrictWeakOrdering>
bool 
includes(InputIterator1 first1, InputIterator1 last1,
         InputIterator2 first2, InputIterator2 last2, StrictWeakOrdering comp)
{
    while (first1 != last1 && first2 != last2) {
        if (comp(*first1, *first2)) { ++first2; }
        ++first1;
    }
    return first2 == last2;
}

template <typename InputIterator1, typename InputIterator2, typename OutputIterator>
OutputIterator 
set_union(InputIterator1 first1, InputIterator1 last1,
          InputIterator2 first2, InputIterator2 last2, OutputIterator result)
{
    while (first1 != last1 && first2 != last2) {
        if (*first1 < *first2) { *result++ = *first1++; continue; }
        if (*first2 < *first1) { *result++ = *first2++; continue; }
        *result++ = *first1;
        ++first1;
        ++first2;
    }
    while (first1 != last1) { *result++ = *first1++; }
    while (first2 != last2) { *result++ = *first2++; }
    return result;
}


template <typename InputIterator1, typename InputIterator2, 
          typename OutputIterator, typename StrictWeakOrdering>
OutputIterator set_union(InputIterator1 first1, InputIterator1 last1,
                         InputIterator2 first2, InputIterator2 last2,
                         OutputIterator result, StrictWeakOrdering comp)
{
    while (first1 != last1 && first2 != last2) {
        if (comp(*first1, *first2)) { *result++ = *first1++; continue; }
        if (comp(*first1, *first2)) { *result++ = *first2++; continue; }
        *result++ = *first1;
        ++first1;
        ++first2;
    }
    while (first1 != last1) { *result++ = *first1++; }
    while (first2 != last2) { *result++ = *first2++; }
    return result;
}

template <typename InputIterator1, typename InputIterator2, typename OutputIterator>
OutputIterator 
set_intersection(InputIterator1 first1, InputIterator1 last1,
                 InputIterator2 first2, InputIterator2 last2, OutputIterator result)
{
    while (first1 != last1 && first2 != last2) {
        if (*first1 < *first2) { ++first1; continue; }
        if (*first2 < *first1) { ++first2; continue; }
        *result++ = *first1;
        ++first1;
        ++first2;
    }
    return result;
}

template <typename InputIterator1, typename InputIterator2, 
          typename OutputIterator, typename StrictWeakOrdering>
OutputIterator 
set_intersection(InputIterator1 first1, InputIterator1 last1,
                 InputIterator2 first2, InputIterator2 last2,
                 OutputIterator result, StrictWeakOrdering comp)
{
    while (first1 != last1 && first2 != last2) {
        if (comp(*first1, *first2)) { ++first1; continue; }
        if (comp(*first2, *first1)) { ++first2; continue; }
        *result++ = *first1;
        ++first1;
        ++first2;
    }
    return result;
}

template <typename InputIterator1, typename InputIterator2, typename OutputIterator>
OutputIterator 
set_difference(InputIterator1 first1, InputIterator1 last1,
               InputIterator2 first2, InputIterator2 last2, OutputIterator result)
{
    while (first1 != last1 && first2 != last2) {
        if (*first1 < *first2) { *result++ = *first1++; continue; }
        if (*first2 == *first1) { ++first1; }
        ++first2;
    }
    while (first1 != last1) { *result++ = *first1++; }
    return result;
}


template <typename InputIterator1, typename InputIterator2, 
          typename OutputIterator, typename StrictWeakOrdering>
OutputIterator 
set_difference(InputIterator1 first1, InputIterator1 last1,
               InputIterator2 first2, InputIterator2 last2, 
               OutputIterator result, StrictWeakOrdering comp)
{
    while (first1 != last1 && first2 != last2) {
        if (*first1 < *first2) { *result++ = *first1++; continue; }
        if (comp(*first2, *first1)) { ++first1; } 
        ++first2;
    }
    while (first1 != last1) { *result++ = *first1++; }
    return result;
}

template <typename InputIterator1, typename InputIterator2, typename OutputIterator>
OutputIterator 
set_symmetric_difference(InputIterator1 first1, InputIterator1 last1,
                         InputIterator2 first2, InputIterator2 last2, OutputIterator result)
{
    while (first1 != last1 && first2 != last2) {
        if (*first1 < *first2) { *result++ = *first1++; continue; }
        if (*first2 < *first1) { *result++ = *first2++; continue; }
        ++first1; 
        ++first2;
    }
    while (first1 != last1) { *result++ = *first1++; }
    while (first2 != last2) { *result++ = *first2++; }
    return result;
}

template <typename InputIterator1, typename InputIterator2, 
          typename OutputIterator, typename StrictWeakOrdering>
OutputIterator 
set_symmetric_difference(InputIterator1 first1, InputIterator1 last1,
                         InputIterator2 first2, InputIterator2 last2,
                         OutputIterator result, StrictWeakOrdering comp)
{
    while (first1 != last1 && first2 != last2) {
        if (comp(*first1, *first2)) { *result++ = *first1++; continue; }
        if (comp(*first2, *first1)) { *result++ = *first2++; continue; }
        ++first1; 
        ++first2;
    }
    while (first1 != last1) { *result++ = *first1++; }
    while (first2 != last2) { *result++ = *first2++; }
    return result;
}


template <typename T> 
const T&
min(const T& a, const T& b)
{
    return a < b ? a : b;
}

template <typename T, typename BinaryPredicate>
const T& 
min(const T& a, const T& b, BinaryPredicate comp)
{
    return comp(a, b) ? a : b;
}

template <typename T> 
const T& 
max(const T& a, const T& b)
{
    return a > b ? a : b;
}

template <typename T, typename BinaryPredicate>
const T& 
max(const T& a, const T& b, BinaryPredicate comp)
{
    return comp(a, b) ? a : b;
}

template <typename ForwardIterator>
ForwardIterator 
min_element(ForwardIterator first, ForwardIterator last)
{
    ForwardIterator min = first++;
    for ( ; first != last; ++first) {
        if (*first < *min) { min = first; }
    }
    return min;
}

template <typename ForwardIterator, typename BinaryPredicate>
ForwardIterator 
min_element(ForwardIterator first, ForwardIterator last, BinaryPredicate comp)
{
    ForwardIterator min = first++;
    for ( ; first != last; ++first) {
        if (comp(*first, *min)) { min = first; }
    }
    return min;
}

template <typename ForwardIterator>
ForwardIterator 
max_element(ForwardIterator first, ForwardIterator last)
{
    ForwardIterator max = first++;
    for ( ; first != last; ++first) {
        if (*max < *first) { max = first; }
    }
    return max;
}

template <typename ForwardIterator, typename BinaryPredicate>
ForwardIterator 
max_element(ForwardIterator first, ForwardIterator last, BinaryPredicate comp)
{
    ForwardIterator max = first++;
    for ( ; first != last; ++first) {
        if (comp(*max, *first)) { max = first; }
    }
    return max;
}


template <typename InputIterator1, typename InputIterator2>
bool 
lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
                        InputIterator2 first2, InputIterator2 last2)
{
    while (first1 != last1 && first2 != last2) {
        if (*first1 != *first2) { return *first1 < *first2; }
        ++first1;
        ++first2; 
    }
    return first1 == last1 && first2 != last2;
}

template <typename InputIterator1, typename InputIterator2, typename BinaryPredicate>
bool 
lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
                        InputIterator2 first2, InputIterator2 last2, BinaryPredicate comp)
{
    while (first1 != last1 && first2 != last2) {
        if (*first1 != *first2) { return comp(*first1, *first2); }
        ++first1;
        ++first2; 
    }
    return first1 == last1 && first2 != last2;
}

template <typename InputIterator1, typename InputIterator2>
int 
lexicographical_compare_3way(InputIterator1 first1, InputIterator1 last1,
                             InputIterator2 first2, InputIterator2 last2)
{
    while (first1 != last1 && first2 != last2) {
        if (*first1 != *first2) { return *first1 - *first2; }
        ++first1;
        ++first2; 
    }
    
    if (first1 == last1) {
        return first2 != last2 ? -1 : 0;
    } 
    return 1;
}

template <typename BidirectionalIterator>
bool 
next_permutation(BidirectionalIterator first, BidirectionalIterator last)
{
    BidirectionalIterator it = last; --it;
    BidirectionalIterator prev = it; --prev;
    while (it != first && *prev >= *it) {
        --prev;
        --it;
    }
    if (it != first) {
        BidirectionalIterator end = last; --end; 
        while (*end <= *prev) { --end; }
        std::iter_swap(prev, end);
    }
    std::reverse(it, last);
    return it != first;
}

template <typename BidirectionalIterator, typename StrictWeakOrdering>
bool 
next_permutation(BidirectionalIterator first, BidirectionalIterator last,
                      StrictWeakOrdering comp)
{
    BidirectionalIterator it = last; --it;
    BidirectionalIterator prev = it; --prev;
    while (it != first && !comp(*prev, *it)) {
        --prev;
        --it;
    }
    if (it != first) {
        BidirectionalIterator end = last; --end; 
        while (comp(*end, *prev)) { --end; }
        std::iter_swap(prev, end);
    }
    std::reverse(it, last);
    return it != first;
}

template <typename BidirectionalIterator>
bool 
prev_permutation(BidirectionalIterator first, BidirectionalIterator last)
{
    BidirectionalIterator it = last; --it;
    BidirectionalIterator prev = it; --prev;
    while (it != first && *prev <= *it) {
        --prev;
        --it;
    }
    if (it != first) {
        BidirectionalIterator end = last; --end; 
        while (*end >= *prev) { --end; }
        std::iter_swap(prev, end);
    }
    std::reverse(it, last);
    return it != first;
}

template <typename BidirectionalIterator, typename StrictWeakOrdering>
bool 
prev_permutation(BidirectionalIterator first, BidirectionalIterator last,
                      StrictWeakOrdering comp)
{
    BidirectionalIterator it = last; --it;
    BidirectionalIterator prev = it; --prev;
    while (it != first && comp(*prev, *it)) {
        --prev;
        --it;
    }
    if (it != first) {
        BidirectionalIterator end = last; --end; 
        while (!comp(*end, *prev)) { --end; }
        std::iter_swap(prev, end);
    }
    std::reverse(it, last);
    return it != first;
}

template <typename InputIterator, typename T>
T 
accumulate(InputIterator first, InputIterator last, T init)
{
    while (first != last) {
        init += *first++;
    }
    return init;
}

template <typename InputIterator, typename T, typename BinaryFunction>
T 
accumulate(InputIterator first, InputIterator last, T init,
             BinaryFunction binary_op)
{
    while (first != last) {
        init += binary_op(init, *first++);
    }
    return init;
}


template <typename InputIterator1, typename InputIterator2, typename T>
T 
inner_product(InputIterator1 first1, InputIterator1 last1,
              InputIterator2 first2, T init)
{
    for ( ; first1 != last1; ++first1, ++first2) {
        init += (*first1 * *first2);
    }
    return init;
}

template <typename InputIterator1,  typename InputIterator2, typename T,
          typename BinaryFunction1, typename BinaryFunction2>
T 
inner_product(InputIterator1 first1, InputIterator1 last1,
              InputIterator2 first2, T init, 
              BinaryFunction1 binary_op1, BinaryFunction2 binary_op2)
{
    for ( ; first1 != last1; ++first1, ++first2) {
        init = binary_op1(init, binary_op2(*first1, *first2));
    }
    return init;
}

template <typename InputIterator, typename OutputIterator>
OutputIterator 
partial_sum(InputIterator first, InputIterator last, OutputIterator result)
{
    if (first == last) { return result; } 
    typename std::iterator_traits<InputIterator>::value_type sum = *first;
    *result++ = *first++;
    for ( ; first != last; ++first) {
        sum += *first;
        *result = sum;
        ++result;
    }
    return result;
}

template <typename InputIterator, typename OutputIterator, typename BinaryOperation>
OutputIterator 
partial_sum(InputIterator first, InputIterator last,
            OutputIterator result, BinaryOperation binary_op)
{
    if (first == last) { return result; } 
    typename std::iterator_traits<InputIterator>::value_type sum = *first;
    *result++ = *first++;
    for ( ; first != last; ++first) {
        sum = binary_op(sum, *first);
        *result = sum;
        ++result;
    }
    return result;
}

template <typename InputIterator, typename OutputIterator>
OutputIterator 
adjacent_difference(InputIterator first, InputIterator last, OutputIterator result)
{
    if (first == last) { return result; } 
    *result++ = *first;
    InputIterator next = first;
    ++next;
    for ( ; next != last; ++first, ++next) {
        *result = *next - *first;
        ++result;
    }
    return result;
}

template <typename InputIterator, typename OutputIterator, typename BinaryFunction>
OutputIterator
adjacent_difference(InputIterator first, InputIterator last,
                    OutputIterator result, BinaryFunction binary_op)
{
    if (first == last) { return result; } 
    *result++ = *first;
    InputIterator next = first;
    ++next;
    for ( ; next != last; ++first, ++next) {
        *result = binary_op(*next, *first);
        ++result;
    }
    return result;
}

template <typename T, typename Integer>
inline T 
power(T base, Integer exponent)
{
    assert(exponent >= 0);
    T answer = 1.0;
    while (0 != exponent) {
        if (0 != exponent % 2) {
            answer *= base;
        }
        base *= base;
        exponent /= 2;
    }
    return answer;
}

template <typename T, typename Integer, typename MonoidOperation>
T 
power(T base, Integer exponent, MonoidOperation op)
{
    assert(exponent >= 0);
    T answer = 1.0;
    while (0 != exponent) {
        if (0 != exponent % 2) {
            answer = op(answer, base);
        }
        base  = op(base, base);
        exponent /= 2;
    }
    return answer;
}


} /// end of namespace my

