#ifndef __FUNCTIONS_HPP__
#define __FUNCTIONS_HPP__

#include <utility>
#include <iterator>
#include <cstdlib>

namespace my {

template <typename InputIterator, typename Predicate>
typename std::iterator_traits<InputIterator>::difference_type
count_if(InputIterator first, InputIterator last, Predicate pred);

template <typename InputIterator, typename Predicate, typename Size>
void count_if(InputIterator first, InputIterator last, 
              Predicate pred, Size& n);

template <typename InputIterator1, typename InputIterator2>
std::pair<InputIterator1, InputIterator2> 
mismatch(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2);

template <typename InputIterator1, typename InputIterator2, 
          typename BinaryPredicate>
std::pair<InputIterator1, InputIterator2> 
mismatch(InputIterator1 first1, InputIterator1 last1, 
         InputIterator2 first2, BinaryPredicate binary_pred);

template <typename InputIterator1, typename InputIterator2>
bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2);

template <typename InputIterator1, typename InputIterator2, 
          typename BinaryPredicate>
bool equal(InputIterator1 first1, InputIterator1 last1,
      InputIterator2 first2, BinaryPredicate binary_pred);

template <typename ForwardIterator1, typename ForwardIterator2>
ForwardIterator1 search(ForwardIterator1 first1, ForwardIterator1 last1,
                        ForwardIterator2 first2, ForwardIterator2 last2);

template <typename ForwardIterator1, typename ForwardIterator2, typename BinaryPredicate>
ForwardIterator1 search(ForwardIterator1 first1, ForwardIterator1 last1,
                        ForwardIterator2 first2, ForwardIterator2 last2,
                        BinaryPredicate binary_pred);

template <typename ForwardIterator, typename Integer, typename T>
ForwardIterator search_n(ForwardIterator first, ForwardIterator last,
                         Integer count, const T& value);

template <typename ForwardIterator, typename Integer, 
          typename T, typename BinaryPredicate>
ForwardIterator search_n(ForwardIterator first, ForwardIterator last,
                         Integer count, const T& value,
                         BinaryPredicate binary_pred);

template <typename ForwardIterator1, typename ForwardIterator2>
ForwardIterator1 
find_end(ForwardIterator1 first1, ForwardIterator1 last1, 
         ForwardIterator2 first2, ForwardIterator2 last2);

template <typename ForwardIterator1, typename ForwardIterator2, 
          typename BinaryPredicate>
ForwardIterator1 
find_end(ForwardIterator1 first1, ForwardIterator1 last1, 
         ForwardIterator2 first2, ForwardIterator2 last2,
         BinaryPredicate comp);


template <typename InputIterator, typename OutputIterator, typename UnaryFunction>
OutputIterator transform(InputIterator first, InputIterator last,
                         OutputIterator result, UnaryFunction op);


template <typename InputIterator1, typename InputIterator2, typename OutputIterator,
          typename BinaryFunction>
OutputIterator transform(InputIterator1 first1, InputIterator1 last1,
                         InputIterator2 first2, OutputIterator result,
                         BinaryFunction binary_op);

template <typename ForwardIterator, typename Predicate, typename T>
void replace_if(ForwardIterator first, ForwardIterator last, Predicate pred,
                const T& new_value);

template <typename InputIterator, typename OutputIterator, typename Predicate, typename T>
OutputIterator replace_copy_if(InputIterator first, InputIterator last,
                               OutputIterator result, Predicate pred,
                               const T& new_value); 



template <typename ForwardIterator, typename Generator>
void generate(ForwardIterator first, ForwardIterator last, Generator gen);

template <typename OutputIterator, typename Size, typename Generator>
OutputIterator generate_n(OutputIterator first, Size n, Generator gen);

template <typename ForwardIterator, typename Predicate>
ForwardIterator remove_if(ForwardIterator first, ForwardIterator last,
                          Predicate pred);

template <typename InputIterator, typename OutputIterator, typename Predicate>
OutputIterator remove_copy_if(InputIterator first, InputIterator last,
                              OutputIterator result, Predicate pred);

template <typename ForwardIterator>
ForwardIterator unique(ForwardIterator first, ForwardIterator last);

template <typename ForwardIterator, typename BinaryPredicate>
ForwardIterator unique(ForwardIterator first, ForwardIterator last,
                       BinaryPredicate binary_pred);

template <typename InputIterator, typename OutputIterator>
OutputIterator unique_copy(InputIterator first, InputIterator last,
                           OutputIterator result);

template <typename InputIterator, typename OutputIterator, typename BinaryPredicate>
OutputIterator unique_copy(InputIterator first, InputIterator last,
                           OutputIterator result,
                           BinaryPredicate binary_pred);

template <typename RandomAccessIterator>
void random_shuffle(RandomAccessIterator first, RandomAccessIterator last);

template <typename RandomAccessIterator, typename RandomNumberGenerator>
void random_shuffle(RandomAccessIterator first, RandomAccessIterator last,
                    RandomNumberGenerator& rand);

template <typename InputIterator, typename RandomAccessIterator>
RandomAccessIterator 
random_sample(InputIterator first, InputIterator last,
              RandomAccessIterator ofirst, RandomAccessIterator olast); 

template <typename InputIterator, typename RandomAccessIterator,
	  typename RandomNumberGenerator>
RandomAccessIterator random_sample(InputIterator first, InputIterator last,
                                   RandomAccessIterator ofirst, RandomAccessIterator olast,
                                   RandomNumberGenerator& rand);

template <typename ForwardIterator, typename OutputIterator, typename Distance>
OutputIterator random_sample_n(ForwardIterator first, ForwardIterator last,
                               OutputIterator out, Distance n);

template <typename ForwardIterator, typename OutputIterator, 
          typename Distance, typename RandomNumberGenerator>
OutputIterator random_sample_n(ForwardIterator first, ForwardIterator last,
                               OutputIterator out, Distance n, RandomNumberGenerator& rand);



template <typename ForwardIterator, typename Predicate>
ForwardIterator partition(ForwardIterator first,
                          ForwardIterator last, Predicate pred);

template <typename ForwardIterator, typename Predicate>
ForwardIterator stable_partition(ForwardIterator first, ForwardIterator last, 
                                 Predicate pred);

template <typename ForwardIterator, typename LessThanComparable>
ForwardIterator lower_bound(ForwardIterator first, ForwardIterator last,
                            const LessThanComparable& value);

template <typename ForwardIterator, typename T, typename StrictWeakOrdering>
ForwardIterator lower_bound(ForwardIterator first, ForwardIterator last,
                            const T& value, StrictWeakOrdering comp);

template <typename ForwardIterator, typename LessThanComparable>
ForwardIterator upper_bound(ForwardIterator first, ForwardIterator last,
                            const LessThanComparable& value);

template <typename ForwardIterator, typename T, typename StrictWeakOrdering>
ForwardIterator upper_bound(ForwardIterator first, ForwardIterator last,
                            const T& value, StrictWeakOrdering comp);

template <typename ForwardIterator, typename LessThanComparable>
std::pair<ForwardIterator, ForwardIterator>
equal_range(ForwardIterator first, ForwardIterator last,
            const LessThanComparable& value);

template <typename ForwardIterator, typename T, typename StrictWeakOrdering>
std::pair<ForwardIterator, ForwardIterator>
equal_range(ForwardIterator first, ForwardIterator last, const T& value,
            StrictWeakOrdering comp);

template <typename InputIterator1, typename InputIterator2, typename OutputIterator>
OutputIterator merge(InputIterator1 first1, InputIterator1 last1,
                     InputIterator2 first2, InputIterator2 last2,
                     OutputIterator result);

template <typename InputIterator1, typename InputIterator2, typename OutputIterator,
          typename StrictWeakOrdering>
OutputIterator merge(InputIterator1 first1, InputIterator1 last1,
                     InputIterator2 first2, InputIterator2 last2,
                     OutputIterator result, StrictWeakOrdering comp);

template <typename BidirectionalIterator>
inline void inplace_merge(BidirectionalIterator first,
                          BidirectionalIterator middle,
                          BidirectionalIterator last);

template <typename BidirectionalIterator, typename StrictWeakOrdering>
inline void inplace_merge(BidirectionalIterator first,
                          BidirectionalIterator middle,
                          BidirectionalIterator last, StrictWeakOrdering comp);



template <typename inputiterator1, typename inputiterator2>
bool includes(inputiterator1 f1, inputiterator1 l1, inputiterator2 f2, inputiterator2 l2);

template <typename InputIterator1, typename InputIterator2, typename StrictWeakOrdering>
bool includes(InputIterator1 first1, InputIterator1 last1,
              InputIterator2 first2, InputIterator2 last2, StrictWeakOrdering comp);

template <typename InputIterator1, typename InputIterator2, typename OutputIterator>
OutputIterator set_union(InputIterator1 f1, InputIterator1 l1,
                         InputIterator2 f2, InputIterator2 l2, 
                         OutputIterator result);

template <typename InputIterator1, typename InputIterator2, typename OutputIterator,
          typename StrictWeakOrdering>
OutputIterator set_union(InputIterator1 first1, InputIterator1 last1,
                         InputIterator2 first2, InputIterator2 last2,
                         OutputIterator result, StrictWeakOrdering comp);

template <typename InputIterator1, typename InputIterator2, typename OutputIterator>
OutputIterator set_intersection(InputIterator1 first1, InputIterator1 last1,
                                InputIterator2 first2, InputIterator2 last2, 
                                OutputIterator result);

template <typename InputIterator1, typename InputIterator2, typename OutputIterator,
          typename StrictWeakOrdering>
OutputIterator set_intersection(InputIterator1 first1, InputIterator1 last1,
                                InputIterator2 first2, InputIterator2 last2,
                                OutputIterator result, StrictWeakOrdering comp);

template <typename InputIterator1, typename InputIterator2, typename OutputIterator>
OutputIterator set_difference(InputIterator1 first1, InputIterator1 last1,
                              InputIterator2 first2, InputIterator2 last2,
                              OutputIterator result);

template <typename InputIterator1, typename InputIterator2, typename OutputIterator, 
          typename StrictWeakOrdering>
OutputIterator set_difference(InputIterator1 first1, InputIterator1 last1,
                              InputIterator2 first2, InputIterator2 last2, 
                              OutputIterator result, StrictWeakOrdering comp);


template <typename InputIterator1, typename InputIterator2, typename OutputIterator>
OutputIterator set_symmetric_difference(InputIterator1 first1, InputIterator1 last1,
                                        InputIterator2 first2, InputIterator2 last2,
                                        OutputIterator result);

template <typename InputIterator1, typename InputIterator2, typename OutputIterator,
          typename StrictWeakOrdering>
OutputIterator set_symmetric_difference(InputIterator1 first1, InputIterator1 last1,
                                        InputIterator2 first2, InputIterator2 last2,
                                        OutputIterator result, StrictWeakOrdering comp);

    
template <typename T> const T& min(const T& a, const T& b);

template <typename T, typename BinaryPredicate>
const T& min(const T& a, const T& b, BinaryPredicate comp);

template <typename T> const T& max(const T& a, const T& b);

template <typename T, typename BinaryPredicate>
const T& max(const T& a, const T& b, BinaryPredicate comp);

template <typename ForwardIterator>
ForwardIterator min_element(ForwardIterator first, ForwardIterator last);

template <typename ForwardIterator, typename BinaryPredicate>
ForwardIterator min_element(ForwardIterator first, ForwardIterator last,
                            BinaryPredicate comp);
template <typename ForwardIterator>
ForwardIterator max_element(ForwardIterator first, ForwardIterator last);

template <typename ForwardIterator, typename BinaryPredicate>
ForwardIterator max_element(ForwardIterator first, ForwardIterator last,
                            BinaryPredicate comp);


template <typename InputIterator1, typename InputIterator2>
bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
                             InputIterator2 first2, InputIterator2 last2);

template <typename InputIterator1, typename InputIterator2, typename BinaryPredicate>
bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
                             InputIterator2 first2, InputIterator2 last2,
                             BinaryPredicate comp);

template <typename InputIterator1, typename InputIterator2>
int lexicographical_compare_3way(InputIterator1 first1, InputIterator1 last1,
                                 InputIterator2 first2, InputIterator2 last2);

template <typename BidirectionalIterator>
bool next_permutation(BidirectionalIterator first,
                      BidirectionalIterator last);

template <typename BidirectionalIterator, typename StrictWeakOrdering>
bool next_permutation(BidirectionalIterator first, BidirectionalIterator last,
                      StrictWeakOrdering comp);

template <typename BidirectionalIterator>
bool prev_permutation(BidirectionalIterator first,
                      BidirectionalIterator last);

template <typename BidirectionalIterator, typename StrictWeakOrdering>
bool prev_permutation(BidirectionalIterator first, BidirectionalIterator last,
                      StrictWeakOrdering comp);

template <typename InputIterator, typename T>
T accumulate(InputIterator first, InputIterator last, T init);

template <typename InputIterator, typename T, typename BinaryFunction>
T accumulate(InputIterator first, InputIterator last, T init,
             BinaryFunction binary_op);

template <typename InputIterator1, typename InputIterator2, typename T>
T inner_product(InputIterator1 first1, InputIterator1 last1,
                InputIterator2 first2, T init);

template <typename InputIterator1, typename InputIterator2, typename T,
          typename BinaryFunction1, typename BinaryFunction2>
T inner_product(InputIterator1 first1, InputIterator1 last1,
                InputIterator2 first2, T init, BinaryFunction1 binary_op1,
                BinaryFunction2 binary_op2);
template <typename InputIterator, typename OutputIterator>
OutputIterator partial_sum(InputIterator first, InputIterator last,
                           OutputIterator result);

template <typename InputIterator, typename OutputIterator, typename BinaryOperation>
OutputIterator partial_sum(InputIterator first, InputIterator last,
                           OutputIterator result, BinaryOperation binary_op);
template <typename InputIterator, typename OutputIterator>
OutputIterator adjacent_difference(InputIterator first, InputIterator last, 
                                   OutputIterator result);

template <typename InputIterator, typename OutputIterator, typename BinaryFunction>
OutputIterator adjacent_difference(InputIterator first, InputIterator last,
                                   OutputIterator result,
                                   BinaryFunction binary_op);

template <typename T, typename Integer>
inline T power(T x, Integer n);

template <typename T, typename Integer, typename MonoidOperation>
T power(T x, Integer n, MonoidOperation op);


} /// end of namespace my

#include "templates/functions.cpp"
#endif /// __FUNCTIONS_HPP__

