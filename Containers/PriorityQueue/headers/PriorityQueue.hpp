#ifndef __PRIORITY_QUEUE__
#define __PRIORITY_QUEUE__

#include "headers/HeapFunctions.hpp"
#include <cstddef>
#include <vector>

template <typename T, typename Sequence = std::vector<T>, typename Compare = std::less<typename Sequence::value_type> >
class PriorityQueue: private Sequence 
{
public:
    typedef T value_type;
    typedef size_t size_type;
public:
    PriorityQueue();
    template <typename InputIterator>
    PriorityQueue(InputIterator first, const InputIterator last);
    void push(const value_type& value);
    void pop();
    const value_type& top() const { return *Sequence::begin(); }
    bool empty() const;
    int size() const;
};

#include <templates/PriorityQueue.cpp>
#endif /// __PRIORITY_QUEUE__

