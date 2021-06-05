#pragma once
#include <algorithm>
#include <iterator>
#include "mySetIterator.h"

template<typename T>
class mySetReverseIterator
{
    mySetIterator<T> pos;
public:
    using iterator_category = std::bidirectional_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = T*;
    using reference = T&;

    mySetReverseIterator(T* pos) : pos(pos) {}

    bool operator==(const mySetReverseIterator& ob) const
    {return pos == ob.pos;};

    bool operator!=(const mySetReverseIterator& ob) const
    {return pos != ob.pos;};

    reference operator*() const
    {return *pos;};

    pointer operator->() const
    {return pos;};

    mySetReverseIterator& operator++()
    {
        --pos;
        return *this;
    }

    mySetReverseIterator& operator++(int)
    {
        mySetReverseIterator temp = *this;
        --pos;
        return temp;
    }

    mySetReverseIterator& operator--()
    {
        ++pos;
        return *this;
    }

    mySetReverseIterator& operator--(int)
    {
        mySetReverseIterator temp = *this;
        ++pos;
        return temp;
    }
};


