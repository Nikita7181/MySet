#include "mySet.h"
#include "iostream"
#include "string"


template <typename T, typename C >
void mySet<T, C>::print()
{
    for (int i = 1; i < data_size+1; i++)
    {std::cout << data[i] << "  ";}
    
} 

template <typename T, typename C >
void mySet<T, C>::r_print()
{
    auto it = rbegin();
    it++;
    for (auto i = it; i != rend(); i++)
    {std::cout << *i << "  ";}
    
} 

template <typename T, typename C >
mySet<T, C>& mySet<T, C>::operator=(mySet<T, C>const& ob)
{
    if(this != &ob)
    {
            delete[] data;
            data_size = ob.data_size;
            data = new T[ob.data_size+2];
            for(int i =1; i < data_size+1; i++)
            data[i] = ob.data[i];
    }
    return *this;
}

template <typename T, typename C>
mySet<T, C>::mySet(mySet<T,C>& ob) :data_size(ob.data_size)
{
    data = new T[ob.size()+2];
    for (int i = 1; i < data_size+1; i++)
    {
        data[i] = ob.data[i];
    }
}

template <typename T, typename C>
mySet<T, C>::mySet() :data_size(0), data(0)
{
    data = new T[data_size+2];
}

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
    return mySetIterator(&data[data_size+1]);
}

template <typename T, typename C>
typename mySet<T, C>::iterator mySet<T, C>::begin() const
{
    return mySetIterator(&data[1]);
}

template <typename T, typename C>
const typename mySet<T, C>::iterator mySet<T, C>::cend() const
{
    return mySetIterator(&data[data_size+1]);
}

template <typename T, typename C>
const typename mySet<T, C>::iterator mySet<T, C>::cbegin() const
{
    return mySetIterator(&data[1]);
}

/*reverse*/

template <typename T, typename C>
 typename mySet<T, C>::reverse_iterator mySet<T, C>::rend() const
{
    return mySetReverseIterator(&data[0]);
}

template <typename T, typename C>
typename mySet<T, C>::reverse_iterator mySet<T, C>::rbegin() const
{
    return mySetReverseIterator(&data[data_size]);
}

template <typename T, typename C>
const typename mySet<T, C>::reverse_iterator mySet<T, C>::rcend() const
{
    return mySetReverseIterator(&data[0]);
}

template <typename T, typename C>
const typename mySet<T, C>::reverse_iterator mySet<T, C>::rcbegin() const
{
    return mySetReverseIterator(&data[data_size]);
}

/*reverse*/

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
    mySet<T,C> temp = *this;
    *this = ob;
    ob = temp;
    temp.clear();

}

template<typename T, typename C>
bool mySet<T,C>::insert(T value)
{
    T * temp = new T [data_size + 2];
    C comp;
    int i = 1, j = 1;
    bool flag = false;

    if (data_size == 0)
    {
        temp[j] = value;
        data_size++;
        data = temp;
        return true;
    }

    while (i < data_size+1)
    {
        if (data[i] == value) return false;

        temp[j] = data[i];
        if (i == data_size)
        {
            temp[j+1] = value;
            break;
        }
        else
        {
            if ((i == 1) && comp(value,data[i]))
            {
                temp[j] = value;
                j++;
                temp[j]= data[i];

            }
            else
            if (!comp(value,data[i]) && comp(value,data[i+1]))
            {
                temp[j+1] = value;
                j++;
                temp[j+1] = data[i+1];
                i++; j++;
            }
        }
        j++; i++;

    }

    data_size++;
    delete [] data;
    data=temp;
    return true;
}

template<typename T, typename C>
int mySet<T,C>::count (T value) const
{
    for(int i = 1; i < data_size+1; i++)
    {
        if (data[i] == value)
            return 1;
    }
    return 0;
}

template<typename T, typename C>
typename mySet<T, C>::iterator mySet<T,C>::find(T value)
{
    iterator temp = begin();
    for(int i = 1; i < data_size+1; i++)
    {
        if (data[i] == value)
            return temp;
        temp++;    
    }
    return end();
}

template<typename T, typename C>
void mySet<T,C>::erase(T value)
{
        if (data == nullptr)
        {
            return;
        } else
        {
            for (int i = 1; i < data_size+1; i++)
            {
                if (data[i] == value)
                {
                    data[i] = data[data_size];
                    for (int j = i; j < data_size - 1; j++)
                    {
                        data[j] = data[j + 1];
                    }
                    data_size--;
                    return;
                } 
            }
        }
}

template<typename T, typename C>
void mySet<T,C>::erase(const iterator &position)
{
        if(position == end())
        {
            throw std::out_of_range("Out of range");
        }

        int d = std::distance(begin(), position);
        *position = data[size ()];
        for (int j = d + 1; j < data_size+1; j++)
        {
            data[j] = data[j + 1];
        }
        data_size--;
}

template<typename T, typename C>
void mySet<T,C>::erase(const iterator &first_position, const iterator &last_position )
{
        if((first_position == end()) || (first_position == last_position))
        {
            throw std::out_of_range("Out of range");
        }
        else
        {
            int distance = std::distance(first_position, last_position);
            int k = std::distance(begin(), last_position);
                for (int i = std::distance(begin(), first_position)+2; i < std::distance(begin(), last_position); i++)
                {
                    data[i] = data[k];
                    k++;
                }
            data_size = data_size - distance+1;
       }
}

template<typename T, typename C>
void mySet<T,C>::merge(mySet<T, C>& ob)
{
    for (auto i = ob.begin (); i != ob.end (); ++i) {

        if (insert (*i))
        {
            ob.erase (*i);
            i--;
        }
    }
}

template<typename T, typename C>
T mySet<T,C>::extract(T value)
{
        if (data == nullptr)
        {
            throw std::invalid_argument("Empty data");
        }
        else if(count(value) == 1)
        {
            for (int i = 1; i < data_size; i++)
            {
                if (data[i] == value)
                {
                    T result = data[i];
                    data[i] = data[data_size];
                    for (int j = i; j < data_size; j++)
                    {
                        data[j] = data[j + 1];
                    }
                    data_size--;
                    return result;
                }
            }
        }
        else
        {
            return *end();
        }
}

template<typename T, typename C>
T mySet<T,C>::extract(const iterator &position)
{
    if (position == end ())
    {
        throw std::out_of_range ("Out of range");
    }
    else if(count(*position) == 1)
    {
        int d = std::distance (begin (), position);
        T result = *position;
        *position = data[data_size];
        for (int j = d; j < data_size+1; j++) {
            data[j] = data[j + 1];
        }
        data_size--;
        return result;
    }
    else
    {
        return *end();
    }
}

template class mySet<int, myComparator<int>>;
template class mySet<float, myComparator<float>>;
template class mySet<std::string, myComparator<std::string>>;
