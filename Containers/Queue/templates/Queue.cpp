#include "headers/Queue.hpp"
#include <cassert>

template <typename T, typename Container>
std::istream& 
operator>>(std::istream& in, Queue<T, Container>& rhv)
{
    T element;
    while (in >> element) {
        rhv.push(element);
    }
    return in;
}

template <typename T, typename Container>
std::ostream& 
operator<<(std::ostream& out, Queue<T, Container> rhv)
{
    out << "{ ";
    while (!rhv.empty()) {
        out << rhv.front() << ' ';
        rhv.pop();
    }
    out << "}";
    return out;
}

template <typename T, typename Container>
Queue<T, Container>::Queue()
{}

template <typename T, typename Container>
Queue<T, Container>::Queue(const Queue<T, Container>& rhv)
    : Container(rhv)
{}

template <typename T, typename Container>
const Queue<T, Container>& 
Queue<T, Container>::operator=(const Queue<T, Container>& rhv)
{
    Container::operator=(rhv);
    return *this;
}

template <typename T, typename Container>
void 
Queue<T, Container>::push(const T& element)
{
    Container::push_back(element);
}

template <typename T, typename Container>
void 
Queue<T, Container>::pop()
{
    assert(!empty());
    Container::erase(Container::begin());
}

template <typename T, typename Container>
typename Queue<T, Container>::reference
Queue<T, Container>::front() 
{
    assert(!empty());
    return Container::front();
}

template <typename T, typename Container>
typename Queue<T, Container>::const_reference
Queue<T, Container>::front() const
{
    assert(!empty());
    return Container::front();
}

template <typename T, typename Container>
typename Queue<T, Container>::reference
Queue<T, Container>::back() 
{
    assert(!empty());
    return Container::back();
}

template <typename T, typename Container>
typename Queue<T, Container>::const_reference
Queue<T, Container>::back() const
{
    assert(!empty());
    return Container::back();
}

template <typename T, typename Container>
bool
Queue<T, Container>::empty() const
{
    return Container::empty();
}

template <typename T, typename Container>
typename Queue<T, Container>::size_type
Queue<T, Container>::size() const
{
    return Container::size();
}

template <typename T, typename Container>
bool 
Queue<T, Container>::operator==(const Queue<T, Container>& rhv) const
{
    return Container(*this) == rhv;
}

template <typename T, typename Container>
bool 
Queue<T, Container>::operator!=(const Queue<T, Container>& rhv) const
{
    return !(*this == rhv);
}

template <typename T, typename Container>
bool 
Queue<T, Container>::operator<(const Queue<T, Container>& rhv) const
{
    return static_cast<const Container& >(*this) < static_cast<const Container& >(rhv);
}

template <typename T, typename Container>
bool 
Queue<T, Container>::operator>(const Queue<T, Container>& rhv) const
{
    return rhv < *this;
}

template <typename T, typename Container>
bool 
Queue<T, Container>::operator>=(const Queue<T, Container>& rhv) const
{
    return !(*this < rhv); 
}

template <typename T, typename Container>
bool 
Queue<T, Container>::operator<=(const Queue<T, Container>& rhv) const
{
    return !(rhv < *this);
}

template <typename T, typename Container>
Queue<T, Container>::operator Container&()
{
    return *this;
}

template <typename T, typename Container>
Queue<T, Container>::operator const Container&() const
{
    return *this;
}

