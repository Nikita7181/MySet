#pragma once
#include "mySetIterator.h"
#include "func.cpp"
#include <algorithm>
#include "string"
#include <stdexcept>

template <typename T, typename C = std::less<T>>
class mySet
{
    T * data;
    int data_size;

public:
    using iterator = mySetIterator<T>;
    mySet ();
    ~mySet();
    void print();
    iterator begin() const;
    iterator end() const;

    const iterator cbegin() const;
    const iterator cend() const;

    int size() const
    {return data_size;}

    void sort(C comp);
    void clear();
    bool empty() const;
    void swap(mySet<T, C>& ob);
    void insert(T value);
    void merge (mySet<T, C>& ob);
    void erase(T value);
    void erase(const iterator &position);
    void erase (const iterator &first_position, const iterator &last_position);
    void

};