#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
#include <stdlib.h>
#include <initializer_list>
#include <cstdint>
template<typename type>
class array
{
public:
    array();
    array(uint32_t size, type initialValue);
    array(std::initializer_list<type> list);
    uint32_t size() const;
    size_t cap() const;
    bool isEmpty() const;
    type& at(uint32_t index) const;
    void push(type item);
    void insert(uint32_t index, type item);
    void prepend(type item);
    type& pop();
    void del(uint32_t index);
    uint32_t remove(type item);
    uint32_t find(type item);
    void resize(uint32_t newSize);
    void print() const;
    ~array();
private:
    type* arr;
    uint32_t length;
    size_t capacity;
};


template<typename type>
void array<type>::print() const
{
    for(int i = 0; i < length - 1; i++)
    {
        std::cout << arr[i] << ", ";
    }
    std::cout << arr[length - 1] << std::endl;
}


template<typename type>
array<type>::~array()
{
    free(arr);
}

template<typename type>
array<type>::array()
    :
    length(0),
    capacity(10)
{
    arr = (type*) calloc(size_t(capacity), sizeof(type));
}

template<typename type>
array<type>::array(uint32_t size, type initialValue)
    :
    length(size),
    capacity(2 * size)
{
    arr = (type*) calloc(size_t(capacity), sizeof(type));
    for(int i = 0; i < length; i++)
    {
        arr[i] = initialValue;
    }
}

template<typename type>
array<type>::array(std::initializer_list<type> list)
    :
    length(list.size()),
    capacity(2 * length)
{
    arr = (type*)calloc(size_t(capacity), sizeof(type));
    int i = 0;
    for(auto elem : list)
    {
        arr[i] = elem;
        i++;
    }
}

template<typename type>
uint32_t array<type>::size() const
{
    return length;
}

template<typename type>
size_t array<type>::cap() const
{
    return capacity;
}

template<typename type>
bool array<type>::isEmpty() const
{
    return length == 0;
}

template<typename type>
type& array<type>::at(uint32_t index) const
{
    if(index < 0 || index >= length)
        throw "out of bound";

    return arr[index];
}

template<typename type>
void array<type>:: push(type item)
{
    if(length >= capacity)
    {
        capacity *= 2;
        type* ptr = (type*) realloc(arr,capacity*sizeof(type));
        if(ptr)
            arr = ptr;
    }
    arr[length++] = item;
}


template<typename type>
void array<type>::insert(uint32_t index, type item)
{
    if(length + 1 >= capacity)
    {
        capacity *= 2;
        type* ptr = (type*) realloc(arr,capacity*sizeof(type));
        if(ptr)
            arr = ptr;
    }
    int i = length;
    while(i > index)
    {
        arr[i] = arr[i - 1];
        i--;
    }
    arr[i] = item;
    length++;
}


template<typename type>
void array<type>::prepend(type item)
{
    insert(0, item);
}


template<typename type>
type& array<type>::pop()
{
    return arr[--length];
}


template<typename type>
void array<type>::del(uint32_t index)
{
    if(index < 0 || index >= length)
        throw "out of bound";
    int i = index;
    while(i < length - 1)
    {
        arr[i] = arr[i + 1];
        i++;
    }
    length--;
}


template<typename type>
uint32_t array<type>::remove(type item)
{
    uint32_t counter = 0;
    for(uint32_t i = 0; i < length; i++)
    {
        if(arr[i] == item)
        {
            del(i);
            i--;
            counter++;
        }
    }
    return counter;
}


template<typename type>
uint32_t array<type>::find(type item)
{
    for(uint32_t i = 0; i < length; i++)
    {
        if(arr[i] == item)
            return i;
    }
    return -1;
}


template<typename type>
void array<type>::resize(uint32_t newSize)
{
    type* ptr = (type*) realloc(arr,size_t(newSize)*sizeof(type));
    if(ptr)
        arr = ptr;
    length = newSize;
}
#endif
