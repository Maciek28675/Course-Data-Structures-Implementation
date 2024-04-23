#ifndef DYNAMICARRAY_HPP
#define DYNAMICARRAY_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "DataStructure.hpp"

template <typename T>
class DynamicArray : public DataStructure<T>
{
private:
    T* array;
    int capacity;
    int size;
    void resize();

public:
    DynamicArray();
    ~DynamicArray();

    void pushBack(const T& value) override;
    void pushFront(const T& value) override;
    void insert(const T& value, const int& index) override;

    void popFront() override;
    void popBack() override;
    void remove(const int& index) override;

    void show() const override;
    int find(const T& value) const override;

};

//double the capacity of array
template <typename T>
void DynamicArray<T>::resize()
{
    //creating new array the size of new doubled capacity
    capacity *= 2;
    T* newArray = new T[capacity];  

    //copying elements from old array to new
    for (int i = 0; i < size; i++)
    {   
        newArray[i] = array[i];
    }

    // Free memory and assign new array to the pointer
    delete[] array;
    array = newArray;
}

template <typename T>
DynamicArray<T>::DynamicArray() : size(0), capacity(1) { array = new T[capacity]; }

template <typename T>
DynamicArray<T>::~DynamicArray() { delete[] array; }

//adding element at the end of array
template <typename T>
void DynamicArray<T>::pushBack(const T& value)
{
    //we double size of the array, if we dont have enough space to add a new value
    if (size == capacity) 
    {
        resize();
    }

    array[size++] = value;
}

//adding element at the beginnig of the array
template <typename T>
void DynamicArray<T>::pushFront(const T& value)
{
    //we double size of the array, if we dont have enough space to add a new value
    if (size == capacity) {
        resize();   
    }

    //copy right half of array from index on i+1 place
    for (int i = size; i > 0; i--)
        array[i] = array[i - 1];

    array[0] = value;
    size++;
}

//adding element at index specified by user
template <typename T>
void DynamicArray<T>::insert(const T& value, const int& index)
{
    // Handle index out of range
    if (index < 0 || index >= size)
    {
        std::cerr << "error: index out of range\n";
        this->success_ = 0;
        return;
    }

    //we double size of the array, if we dont have enough space to add a new value
    if (size == capacity)
    {
        resize();
    }

    for (int i = size; i > index; i--)
        array[i] = array[i - 1];

    array[index] = value;
    size++;
}

//remove element from beginning of array
template <typename T>
void DynamicArray<T>::popFront()
{
    if (size == 0)
    {
        this->success_ = 0;
        std::cerr << "error: list is empty\n";
        return;
    }

    for (int i = 0; i < size - 1; i++)
        array[i] = array[i + 1];

    size--;
}

//remove element form the end of array
template <typename T>
void DynamicArray<T>::popBack()
{
    if (size > 0)
        size--;
    else
    {
        this->success_ = 0;
        std::cerr << "error: array is empty\n";
        return;
    }
}

//remove element from index place
template <typename T>
void DynamicArray<T>::remove(const int& index)
{
    if (index < 0 || index >= size)
    {
        std::cerr << "error: index out of range\n";
        this->success_ = 0;
        return;
    }

    for (int i = index; i < size - 1; i++)
        array[i] = array[i + 1];

    size--;
}

template <typename T>
void DynamicArray<T>::show() const
{
    for (int i = 0; i < size; i++)
        std::cout << array[i] << " ";

    std::cout << '\n';
}

template <typename T>
int DynamicArray<T>::find(const T& value) const
{
    for (int i = 0; i < size; i++) 
    {
        // found value, return index
        if (array[i] == value) 
        {
            return i;
        }
    }
    return -1;
}

#endif