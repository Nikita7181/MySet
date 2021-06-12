#pragma once
#include <algorithm>
#include <iterator>

template<typename T>
class mySetIterator
{
    T* pos;
public:
    using iterator_category = std::bidirectional_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = T*;
    using reference = T&;

    mySetIterator(T* pos) : pos(pos) {}

    bool operator==(const mySetIterator& ob) const
    {return pos == ob.pos;};

    bool operator!=(const mySetIterator& ob) const
    {return pos != ob.pos;};

    reference operator*() const
    {return *pos;};

    pointer operator->() const
    {return pos;};

    mySetIterator& operator++()
    {
        ++pos;
        return *this;
    }

    mySetIterator& operator++(int)
    {
        mySetIterator temp = *this;
        ++pos;
        return temp;
    }

    mySetIterator& operator--()
    {
        --pos;
        return *this;
    }

    mySetIterator& operator--(int)
    {
        mySetIterator temp = *this;
        --pos;
        return temp;
    }
};
