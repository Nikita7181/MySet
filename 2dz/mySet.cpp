#include "mySet.h"
#include "iostream"
#include "string"


template <typename T, typename C >
void mySet<T, C>::print()
{
    for (int i = 0; i < data_size; i++)
    {std::cout << data[i] << "  ";}
    
} 


template <typename T, typename C>
mySet<T, C>::mySet() :data_size(0), data(nullptr)
{}

template <typename T, typename C>
mySet<T, C>::~mySet()
{
    if (data != nullptr)
        {
            delete [] data;
            data = nullptr;
        }
}

template <typename T, typename C>
typename mySet<T, C>::iterator mySet<T, C>::end() const
{
    return mySetIterator(&data[data_size]);
}

template <typename T, typename C>
typename mySet<T, C>::iterator mySet<T, C>::begin() const
{
    //if (data == nullptr)
    //    return nullptr;
    return mySetIterator(&data[0]);
}

template <typename T, typename C>
const typename mySet<T, C>::iterator mySet<T, C>::cend() const
{
    return mySetIterator(&data[data_size]);
}

template <typename T, typename C>
const typename mySet<T, C>::iterator mySet<T, C>::cbegin() const
{
    return mySetIterator(&data[0]);
}

template <typename T, typename C>
bool mySet<T, C>::empty() const
{
    return begin()==end();
}

template <typename T, typename C>
void mySet<T, C>::clear()
{
    if (data != nullptr )
    {
        delete [] data;
        data = nullptr;
        data_size = 0;
    }
}

template<typename T, typename C>
void mySet<T,C>::swap(mySet<T, C>& ob)
{
    //mySet<T, C> temp;
    //temp.data_size = size();
    //temp.data = data;

    //data = ob.data;
    //data_size = ob.size();

    //ob.data_size = temp.size();
    //ob.data = temp.data;

    T *temp = new T[data_size];
    T *temp_2 = new T[ob.data_size];
    for (int i = 0; i < data_size; i++)
    {
        temp[i] = data[i];
    }
    for (int i = 0; i < ob.data_size; i++)
    {
        temp_2[i] = ob.data[i];
    }
    int t_s = data_size;
    data_size = ob.data_size;
    ob.data_size = t_s;

    //resize(ob_len);
    //ob.resize(it);
    data = temp_2;
    ob.data = temp;
    //delete [] temp;
    //delete [] temp_2;
    //begin();


}

template<typename T, typename C>
void mySet<T,C>::insert(T value)
{
    data_size++; 
    T * temp = new T [data_size];
    for (int i = 0; i < data_size - 1; i++)
    {
        temp[i] = data[i];
    }
    temp[data_size-1]=value;

    data = temp;
    std::sort(begin(), end(), C());

    
}

template class mySet<int, myComparator<int>>;
template class mySet<float, myComparator<float>>;
template class mySet<std::string, myComparator<std::string>>;