#ifndef __FUNCTIONS_HPP__
#define __FUNCTIONS_HPP__

#include <iterator>
         
namespace my {

template <typename RandIt, typename Compare>
void make_heap(RandIt first, RandIt last, Compare compare);

template <typename RandIt, typename Compare>
void push_heap(RandIt first, RandIt last, Compare compare);

template <typename RandIt, typename Compare>
void pop_heap(RandIt first, RandIt last, Compare compare);

template <typename RandIt, typename Compare>
bool is_heap(RandIt first, RandIt last, Compare compare);

template <typename RandIt, typename Compare>
void sort_heap(RandIt first, RandIt last, Compare compare);

template <typename RandIt, typename Compare>
void heapify(const RandIt first, const RandIt last, RandIt root, Compare compare);

int left(const int rootIndex);
int right(const int rootIndex);
int parent(const int child);

/// Just in case, In -std=C++03 it is not allowed to pass default arguments to function template parameters

template <typename RandIt>
void make_heap(RandIt first, RandIt last) 
{ 
    return my::make_heap(first, last, std::less<typename std::iterator_traits<RandIt>::value_type>()); 
}

template <typename RandIt>
void push_heap(RandIt first, RandIt last) 
{ 
    return my::push_heap(first, last, std::less<typename std::iterator_traits<RandIt>::value_type>()); 
}

template <typename RandIt>
void pop_heap(RandIt first, RandIt last)  
{ 
    return my::pop_heap(first, last, std::less<typename std::iterator_traits<RandIt>::value_type>());  
}

template <typename RandIt>
bool is_heap(RandIt first, RandIt last)   
{ 
    return my::is_heap(first, last, std::less<typename std::iterator_traits<RandIt>::value_type>());   
}

template <typename RandIt>
void sort_heap(RandIt first, RandIt last) 
{ 
    return my::sort_heap(first, last, std::less<typename std::iterator_traits<RandIt>::value_type>()); 
}

} /// namespace my

#include "templates/HeapFunctions.cpp"
#endif /// __FUNCTIONS_HPP__

