#ifndef __STACK_T_HPP__
#define __STACK_T_HPP__

#include <iostream>
#include <list>

template <typename T, typename Container> class Queue;
template <typename T, typename Container> std::istream& operator>>(std::istream& in, Queue<T, Container>& rhv);
template <typename T, typename Container> std::ostream& operator<<(std::ostream& out, Queue<T, Container> rhv);

template <typename T, typename Container = std::list<T> >
class Queue : private Container
{
    template <typename T1, typename QueueContainer> friend std::istream& operator>>(std::istream& in,  Queue<T1, QueueContainer>& rhv);
    template <typename T1, typename QueueContainer> friend std::ostream& operator<<(std::ostream& out, Queue<T1, QueueContainer> rhv);
public:
    typedef T value_type;
    typedef value_type& reference;
    typedef const value_type& const_reference;
    typedef size_t size_type;
public:
    Queue();
    Queue(const Queue& rhv);
    const Queue<T, Container>& operator=(const Queue<T, Container>& rhv);
    void push(const_reference element);
    void pop();
    reference back();
    const_reference back() const;
    reference front();
    const_reference front() const;
    size_type size() const;
    bool empty() const;
    bool operator==(const Queue<T, Container>& rhv) const;
    bool operator!=(const Queue<T, Container>& rhv) const;
    bool operator< (const Queue<T, Container>& rhv) const;
    bool operator> (const Queue<T, Container>& rhv) const;
    bool operator>=(const Queue<T, Container>& rhv) const;
    bool operator<=(const Queue<T, Container>& rhv) const;
private:
    operator Container&();
    operator const Container&() const;
};

#include "templates/Queue.cpp"
#endif /// __STACK_T_HPP__

