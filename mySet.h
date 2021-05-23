#pragma once
#include "mySetIterator.h"
#include "mySetReverseIterator.h"
#include "func.cpp"
#include <algorithm>
#include "iostream"
#include "string"

template <typename T, typename C = std::less<T>>
class mySet
{
    T * data;
    int data_size;

public:
    using iterator = mySetIterator<T>;
    using reverse_iterator = mySetReverseIterator<T>;
    mySet ();
    ~mySet();
    void print();
    void r_print();

    iterator begin() const;
    iterator end() const;
    const iterator cbegin() const;
    const iterator cend() const;

    reverse_iterator rbegin() const;
    reverse_iterator rend() const;
    const reverse_iterator rcbegin() const;
    const reverse_iterator rcend() const;

    int size() const {return data_size;}

    void sort(C comp);
    void clear();
    bool empty() const;
    void swap(mySet<T, C>& ob);
    void insert(T value);
    iterator find(T value);
    int count (T value) const;
    void erase(T value);
    void erase(const iterator &position);
    void erase(const iterator &first_position, const iterator &last_position );
    void merge(mySet<T, C>& ob);
    T extract(T value);
    T extract(const iterator &position);
};