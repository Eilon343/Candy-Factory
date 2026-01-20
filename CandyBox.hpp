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
void displayItems() const {
    if (count == 0) {
        std::cout << "The box is empty." << std::endl;
        return;
    }
    for (int i = 0; i < count; i++) {
        std::cout << "Item [" << i << "]: " << items[i] << std::endl;
    }
}
};