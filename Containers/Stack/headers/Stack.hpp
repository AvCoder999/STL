#ifndef __STACK_T_HPP__
#define __STACK_T_HPP__

#include <iostream>
#include <vector>

template <typename T, typename Container> class Stack;
template <typename T, typename Container> std::istream& operator>>(std::istream& in, Stack<T, Container>& rhv);
template <typename T, typename Container> std::ostream& operator<<(std::ostream& out, Stack<T, Container> rhv);

template <typename T, typename Container = std::vector<T> >
class Stack : private Container
{
    template <typename T1, typename StackContainer> friend std::istream& operator>>(std::istream& in,  Stack<T1, StackContainer>& rhv);
    template <typename T1, typename StackContainer> friend std::ostream& operator<<(std::ostream& out, Stack<T1, StackContainer> rhv);
public:
    typedef T value_type;
    typedef value_type& reference;
    typedef const value_type& const_reference;
    typedef size_t size_type;
public:
    Stack();
    Stack(const Stack<T, Container>& rhv);
    const Stack<T, Container>& operator=(const Stack<T, Container>& rhv);
    void push(const_reference element);
    void pop();
    reference top();
    const_reference top() const;
    size_type size() const;
    bool empty() const;
    bool operator==(const Stack<T, Container>& rhv) const;
    bool operator!=(const Stack<T, Container>& rhv) const;
    bool operator< (const Stack<T, Container>& rhv) const;
    bool operator> (const Stack<T, Container>& rhv) const;
    bool operator>=(const Stack<T, Container>& rhv) const;
    bool operator<=(const Stack<T, Container>& rhv) const;
private:
    operator Container&();
    operator const Container&() const; 
};

#include "templates/Stack.cpp"
#endif /// __STACK_T_HPP__

