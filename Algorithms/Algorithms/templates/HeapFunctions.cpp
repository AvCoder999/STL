#include "headers/HeapFunctions.hpp"
#include <cassert>

namespace my {

template <typename RandIt, typename Compare>
void 
make_heap(RandIt first, RandIt last, Compare compare)
{
    const int size = last - first;
    RandIt lastInternal = (first + size / 2 - 1);
    for (RandIt it = lastInternal; it >= first; --it) {
        heapify(first, last, it, compare);
    } 
}

template <typename RandIt, typename Compare>
void 
push_heap(RandIt first, RandIt last, Compare compare)
{
    assert(my::is_heap(first, last - 1, compare));
    int index = last - first - 1;
    while (compare(*(first + parent(index)), *(first + index)) && index > 0) {
	const int parentIndex = parent(index);
        std::swap(*(first + parentIndex), *(first + index));
        index = parentIndex;
    }
}

template <typename RandIt, typename Compare>
void 
pop_heap(RandIt first, RandIt last, Compare compare)
{
    if (first >= last) { return; }
    std::swap(*first, *(last - 1));
    heapify(first, last - 1, first, compare);
}

template <typename RandIt, typename Compare>
bool 
is_heap(RandIt first, RandIt last, Compare compare)
{
    const int size = last - first;
    for (int index = 0; index < size / 2; ++index) {
        const int leftIndex = left(index);
        const int rightIndex = right(index);
        if (leftIndex  < size && !compare(*(first + leftIndex), *(first + index)))  { return false; }
        if (rightIndex < size && !compare(*(first + rightIndex), *(first + index))) { return false; }
    } 
    return true;
}

template <typename RandIt, typename Compare>
void 
sort_heap(RandIt first, RandIt last, Compare compare)
{
    assert(my::is_heap(first ,last, compare));
    while (first < last) {
        my::pop_heap(first, last--, compare);
    }
}

template <typename RandIt, typename Compare>
void
heapify(const RandIt first, const RandIt last, RandIt root, Compare compare)
{
    const int rootIndex = root - first;
    if (rootIndex >= (last - first) / 2) { return; }
    RandIt largest = root;
    
    if (first + left(rootIndex) < last && !compare(*(first + left(rootIndex)), *largest)) {
        largest = first + left(rootIndex);
    }
    if (first + right(rootIndex) < last && !compare(*(first + right(rootIndex)), *largest)) {
        largest = first + right(rootIndex);
    }
    if (root != largest) {
        std::swap(*root, *largest);
        heapify(first, last, largest, compare);
    }
}

int
left(const int rootIndex)
{
    return 2 * rootIndex + 1;
}

int 
right(const int rootIndex)
{
    return 2 * rootIndex + 2;
}

int 
parent(const int child)
{
    return (child - 1) / 2;
}

} /// end of namespace my

