#include "headers/Stack.hpp"
#include <cassert>

template <typename T, typename Container>
std::istream& 
operator>>(std::istream& in, Stack<T, Container>& rhv)
{
    T element;
    while (in >> element) {
        rhv.push(element);
    }
    return in;
}

template <typename T, typename Container>
std::ostream& 
operator<<(std::ostream& out, Stack<T, Container> rhv)
{
    out << "{ ";
    while (!rhv.empty()) {
        out << rhv.top() << ' ';
        rhv.pop();
    }
    out << "}";
    return out;
}

template <typename T, typename Container>
Stack<T, Container>::Stack()
{}

template <typename T, typename Container>
Stack<T, Container>::Stack(const Stack<T, Container>& rhv)
    : Container(rhv)
{
}

template <typename T, typename Container>
const Stack<T, Container>& 
Stack<T, Container>::operator=(const Stack<T, Container>& rhv)
{
    Container::operator=(rhv);
    return *this;
}

template <typename T, typename Container>
void 
Stack<T, Container>::push(const T& element)
{
    Container::push_back(element);
}

template <typename T, typename Container>
void 
Stack<T, Container>::pop()
{
    assert(!empty());
    Container::pop_back();
}

template <typename T, typename Container>
typename Stack<T, Container>::reference
Stack<T, Container>::top() 
{
    assert(!empty());
    return Container::back();
}

template <typename T, typename Container>
typename Stack<T, Container>::const_reference
Stack<T, Container>::top() const
{
    assert(!empty());
    return Container::back();
}

template <typename T, typename Container>
bool
Stack<T, Container>::empty() const
{
    return Container::size() == 0;
}

template <typename T, typename Container>
typename Stack<T, Container>::size_type
Stack<T, Container>::size() const
{
    return Container::size();
}

template <typename T, typename Container>
bool 
Stack<T, Container>::operator==(const Stack<T, Container>& rhv) const
{
    return Container(*this) == rhv;
}

template <typename T, typename Container>
bool 
Stack<T, Container>::operator!=(const Stack<T, Container>& rhv) const
{
    return !(*this == rhv);
}

template <typename T, typename Container>
bool 
Stack<T, Container>::operator<(const Stack<T, Container>& rhv) const
{
    return static_cast<const Container& >(*this) < static_cast<const Container& >(rhv);
}

template <typename T, typename Container>
bool 
Stack<T, Container>::operator>(const Stack<T, Container>& rhv) const
{
    return rhv < *this;
}

template <typename T, typename Container>
bool 
Stack<T, Container>::operator>=(const Stack<T, Container>& rhv) const
{
    return !(*this < rhv); 
}

template <typename T, typename Container>
bool 
Stack<T, Container>::operator<=(const Stack<T, Container>& rhv) const
{
    return !(rhv < *this);
}

template <typename T, typename Container>
Stack<T, Container>::operator Container&()
{
    return *this;
}

template <typename T, typename Container>
Stack<T, Container>::operator const Container&() const
{
    return *this;
}

