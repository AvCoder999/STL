#include "headers/PriorityQueue.hpp"
#include <cassert>

template <typename T, typename Sequence, typename Compare>
PriorityQueue<T, Sequence, Compare>::PriorityQueue()
{}

template <typename T, typename Sequence, typename Compare>
template <typename InputIterator>
PriorityQueue<T, Sequence, Compare>::PriorityQueue(InputIterator first, const InputIterator last)
{
    while (first != last) {
        Sequence::push_back(*first);
        ++first;
    }
    my::make_heap(Sequence::begin(), Sequence::end(), Compare());
}

template <typename T, typename Sequence, typename Compare>
void
PriorityQueue<T, Sequence, Compare>::push(const T& value)
{
    Sequence::push_back(value);
    my::push_heap(Sequence::begin(), Sequence::end(), Compare());
}

template <typename T, typename Sequence, typename Compare>
void
PriorityQueue<T, Sequence, Compare>::pop()
{
    assert(!empty());
    my::pop_heap(Sequence::begin(), Sequence::end(), Compare());
    Sequence::pop_back();
}

template <typename T, typename Sequence, typename Compare>
bool 
PriorityQueue<T, Sequence, Compare>::empty() const
{
    return Sequence::empty();
}

template <typename T, typename Sequence, typename Compare>
int 
PriorityQueue<T, Sequence, Compare>::size() const
{
    return Sequence::size();
}

