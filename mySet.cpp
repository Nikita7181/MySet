#include "mySet.h"

template <typename T, typename C >
void mySet<T, C>::print()
{
    for (int i = 0; i < data_size; i++)
    {std::cout << data[i] << "  ";}
    
}

template <typename T, typename C >
mySet<T, C>& mySet<T, C>::operator=(mySet<T, C>const& ob)
{
    if(this != &ob)
    {
        if(data_size != ob.data_size)
        {
            delete[] data;
            data_size = ob.data_size;
            data = new T[ob.data_size];
        }
        for(int i =0; i < data_size; i++)
            data[i] = ob.data[i];
    }
    return *this;
}

template <typename T, typename C >
void mySet<T, C>::r_print()
{
    for (auto i = rbegin(); i != rend(); i++)
    {std::cout << *i << "  ";}
    
} 


template <typename T, typename C>
mySet<T, C>::mySet() :data_size(0), data(nullptr){}

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

/*reverse*/

template <typename T, typename C>
typename mySet<T, C>::reverse_iterator mySet<T, C>::rend() const
{
    return mySetReverseIterator(&data[-1]);
}

template <typename T, typename C>
typename mySet<T, C>::reverse_iterator mySet<T, C>::rbegin() const
{
    return mySetReverseIterator(&data[data_size-1]);
}

template <typename T, typename C>
const typename mySet<T, C>::reverse_iterator mySet<T, C>::rcend() const
{
    return mySetReverseIterator(&data[-1]);
}

template <typename T, typename C>
const typename mySet<T, C>::reverse_iterator mySet<T, C>::rcbegin() const
{
    return mySetReverseIterator(&data[data_size-1]);
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

    data = temp_2;
    ob.data = temp;

}

template<typename T, typename C>
void mySet<T,C>::insert(T value)
{
    if (count(value) == 1) return;
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

template<typename T, typename C>
int mySet<T,C>::count (T value) const
{
    for(int i = 0; i < data_size; i++)
    {
        if (data[i] == value)
            return 1;
    }
    return 0;
}

template<typename T, typename C>
typename mySet<T, C>::iterator mySet<T,C>::find(T value)
{
    for(int i = 0; i < data_size; i++)
    {
        iterator temp = begin()++;
        if (data[i] == value)
            return begin();
    }
    return end();
}

template<typename T, typename C>
void mySet<T,C>::erase(T value)
{
    try {
        if (data == nullptr)
        {
            return;
        } else
        {
            for (int i = 0; i < data_size; i++)
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
            throw std::invalid_argument("Value not found");
        }
    }
    catch (std::invalid_argument &e)
    {
        std::cout << e.what() << std::endl;
    }
}

template<typename T, typename C>
void mySet<T,C>::erase(const iterator &position)
{
    try
    {
        if(position == end())
        {
            throw std::out_of_range("Out of range");
        }
        for (int i = 0; i < data_size; i++)
        {
            iterator temp1 = begin()++;
            if(temp1 == position)
            {
                data[i] = data[data_size];
                for(int j = i; j < data_size; j++)
                {
                    data[j]=data[j+1];
                }
                data_size--;
            }
        }
    }
    catch (std::out_of_range &e)
    {
        std::cout << e.what() << std::endl;
    }
}

template<typename T, typename C>
void mySet<T,C>::erase(const iterator &first_position, const iterator &last_position )
{
    try
    {
        if((first_position == end()) || (first_position == last_position))
        {
            throw std::out_of_range("Out of range");
        }
        else
        {
            int distance = std::distance(first_position, last_position);
            for (int i = 0; i < data_size; i++)
            {
                iterator temp = begin()++;
                if(temp == first_position)
                {
                    for (int j = 1; j < distance; j++)
                    {
                        temp++;
                         erase (temp);
                        temp--;
                    }
                    break;
                }
            }
        }
    }
    catch(std::out_of_range &e)
    {
        std::cout << e.what() << std::endl;
    }

}

template<typename T, typename C>
void mySet<T,C>::merge(mySet<T, C>& ob)
{
    for (auto i = ob.begin(); i != ob.end(); ++i)
    {
        if (count (*i) == 0)
        {
            insert(*i);
            ob.erase(*i);
            --i;
        }
        
    }

}

template<typename T, typename C>
T mySet<T,C>::extract(T value)
{
    try {
        if (data == nullptr)
        {
            throw std::invalid_argument("Empty data");
        } else
        {
            for (int i = 0; i < data_size; i++)
            {
                if (data[i] == value)
                {
                    T result = data[i];
                    data[i] = data[data_size];
                    for (int j = i; j < data_size - 1; j++)
                    {
                        data[j] = data[j + 1];
                    }
                    data_size--;
                    return result;
                }
            }
            throw std::invalid_argument("Value not found");
        }
    }
    catch (std::invalid_argument &e)
    {
        std::cout << e.what() << std::endl;
    }
}

template<typename T, typename C>
T mySet<T,C>::extract(const iterator &position)
{
    try
    {
        if(position == end())
        {
            throw std::out_of_range("Out of range");
        }
        for (int i = 0; i < data_size; i++)
        {
            iterator temp = begin()++;
            if(temp == position)
            {
                T result = data[i];
                data[i] = data[data_size];
                for(int j = i; j < data_size; j++)
                {
                    data[j]=data[j+1];
                }
                data_size--;
                return result;
            }
        }
    }
    catch (std::out_of_range &e)
    {
        std::cout << e.what() << std::endl;
    }
}
template class mySet<int, myComparator<int>>;
template class mySet<float, myComparator<float>>;
template class mySet<std::string, myComparator<std::string>>;