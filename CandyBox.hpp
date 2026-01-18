#pragma once
#include <iostream>

template <class T>
class CandyBox
{
private:
    T *items;
    int capacity;
    int count;

public:
    CandyBox(int size) : capacity(size), count(0)
    {
        items = new T[capacity];
        for (int i = 0; i < capacity; i++)
        {
            items[i] = T();
        }
    }
    ~CandyBox()
    {
        delete[] items;
        items = nullptr;
    }
    bool addItem(const T &newItem)
    {
        if (count >= capacity)
            return false;
        items[count] = newItem;
        count++;
        return true;
    }
    bool removeItem(int index)
    {
        if (index < 0 || index >= count)
            return false;
        for (int i = index; i < count - 1; i++)
        {
            items[i] = items[i + 1];
        }
        count--;
        return true;
    }
    void displayItems() const
    {
        if (count == 0)
        {
            std::cout << "The box is empty." << std::endl;
            return;
        }
        for (int i = 0; i < count; i++)
        {
            if (items[i] != nullptr)
                std::cout << "Item [" << i << "]: " << items[i] << std::endl;
        }
    }
};

// #include "CandyBox.hpp"

// template <typename T>
// CandyBox<T>::CandyBox(int size)
// {
//     items = new T[size];
//     capacity = size;
//     count = 0;
// }

// template <typename T>
// CandyBox<T>::~CandyBox()
// {
//     delete[] items;
//     items = nullptr;
// }

// template <typename T>
// bool CandyBox<T>::addItem(const T &newItem)
// {
//     if (count >= capacity)
//         return false;
//     items[count] = newItem;
//     count++;
//     return true;
// }

// template <typename T>
// bool CandyBox<T>::removeItem(int index)
// {
//     if (index < 0 || index >= count)
//         return false;
//     for (int i = index; i < count - 1; i++)
//     {
//         items[i] = items[i + 1];
//     }
//     count--;
//     return true;
// }

// template <typename T>
// void CandyBox<T>::displayItems() const
// {
//     if (count == 0)
//     {
//         std::cout << "The box is empty." << std::endl;
//         return;
//     }
//     for (int i = 0; i < count - 1; i++)
//     {
//         std::cout << "Item [" << i << "]: " << items[i] << std::endl;
//     }
// }