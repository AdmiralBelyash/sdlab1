#include <iostream>

#include "DynamicArray.h"


using namespace std;

int DynamicArray::GetLenght()
{
    return _length;
}

int DynamicArray::GetCapacity()
{
    return _capacity;
}

void DynamicArray::PushBack(int value)
{
    if (_length >= _capacity)
    {
        ReSize();
    }

    _array[_length] = value;
    ++_length;
    _sorted = false;
}

DynamicArray::DynamicArray(unsigned int capacity)
{
    _capacity = capacity;
    _array = new int[_capacity];
}

int DynamicArray::InsertElement(unsigned int index, int value)
{
    if (index > _length)
    {
        cerr << "Index does not exist" << endl;
        return -1;
    }

    if (_length >= _capacity)
    {
        ReSize();
    }
    
    for (unsigned int i = _length; i > index; --i) 
    {
        _array[i] = _array[i - 1];
    }

    ++_length;
    _array[index] = value;

    _sorted = false;
    return 0;
}

void DynamicArray::ShowArray()
{
    cout << "Array: ";
    for (unsigned int i = 0; i < _length; ++i)
    {
        cout << _array[i] << ' ';
    }
    cout << endl;
}

int DynamicArray::RemoveElement(int index)
{
    if (index >= _length)
    {
        cerr << "Index does not exist" << endl;
        return -1;
    }

    for (int i = index + 1; i < _length; ++i)
    {
        _array[i - 1] = _array[i];
    }
    --_length;

    return 0;
}

void DynamicArray::Sort()
{
    for (int i = 1; i < _length; ++i)
    {
        for (int j = i; j > 0 && _array[j - 1] > _array[j]; --j)
        {
            int tmp = _array[j - 1];
            _array[j - 1] = _array[j];
            _array[j] = tmp;
        }
    }

    _sorted = true;
}

unsigned int DynamicArray::LinearSearch(unsigned int start, unsigned int end, int value)
{
    int count = 0;

    for (unsigned int i = start; i < end; ++i)
    {
        if (value == _array[i])
        {
            return i;
        }
    }

    return _length;
}

unsigned int DynamicArray::BinarySearch(int value)
{
    if (_sorted)
    {
        Sort();
    }

    int low = 0;
    int high = _length - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (value == _array[mid])
        {
            return mid;
        }
        else if (value > _array[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    cout << "Not found" << endl;
    return _length;
}



bool DynamicArray::IsSorted()
{
    return _sorted;
    
    int count = 0;

    for (int i = 0; i < _length - 1; ++i)
    {
        if (_array[i] < _array[i + 1])
        {
            ++count;
        }
    }

    return count == _length - 1;
}

DynamicArray::~DynamicArray()
{
    delete[] _array;
}


void DynamicArray::ReSize()
{
    int* newArray = new int[_capacity * _growthFactor];

    for (int i = 0; i < _capacity; ++i)
    {
        newArray[i] = _array[i];
    }

    _capacity *= _growthFactor;
    delete[] _array;
    _array = newArray;
}




