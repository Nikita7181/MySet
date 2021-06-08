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

    // mySetIterator operator+(const difference_type& diff) const noexcept
    // {return mySetIterator(pos + diff);}

    // friend inline mySetIterator operator+(const difference_type& diff, const mySetIterator& ob)
    // {return mySetIterator(ob.pos + diff);}

    // mySetIterator operator-(const difference_type& diff) const noexcept
    // {return mySetIterator(pos - diff);}

    // difference_type operator-(const mySetIterator& ob) const
    // {return std::distance(ob.pos, pos);}

    // bool operator>(const mySetIterator& ob) const
    // {return pos > ob.pos;};

    // bool operator<(const mySetIterator& ob) const
    // {return pos < ob.pos;};
};