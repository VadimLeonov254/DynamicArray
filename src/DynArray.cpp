#include "DynArray.h"
#include<iostream>
#include<stdexcept>
DynArray::DynArray() {
    data = new int[capacity];
}

DynArray::DynArray(const DynArray& other) {
    size = other.size;
    capacity = other.capacity;
    data = new int[capacity];
    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
}

DynArray::~DynArray() {
    delete[] data;
}

void DynArray::push_back(int x) {
    if (size >= capacity) {
        int* newData = new int[2 * capacity];
        for (int i = 0; i < size; i++)
            newData[i] = data[i];
        delete[] data;
        data = newData;
        capacity *= 2;
    }
    data[size] = x;
    size++;
}

void DynArray::insert(int position, int element) {
    if (position < 0 || position > size) {
        std::cerr << "Error: invalid position\n";
        return;
    }

    if (size >= capacity) {
        int* newData = new int[2 * capacity];
        for (int i = 0; i < size; i++)
            newData[i] = data[i];
        delete[] data;
        data = newData;
        capacity *= 2;
    }

    for (int i = size; i > position; i--)
        data[i] = data[i - 1];

    data[position] = element;
    size++;
}

void DynArray::erase(int position) {
    if (position < 0 || position >= size) {
        std::cerr << "Error: invalid position\n";
        return;
    }
    for (int i = position; i < size - 1; i++)
        data[i] = data[i + 1];
    size--;
}

void DynArray::clear() {
    size = 0;
}

int& DynArray::operator[](int index) {
    if (index < 0 || index >= size)
        throw std::out_of_range("Index out of range");
    return data[index];
}

const int& DynArray::operator[](int index) const {
    if (index < 0 || index >= size)
        throw std::out_of_range("Index out of range");
    return data[index];
}



DynArray::DynArray(DynArray&& other) noexcept{

    data = other.data;
    size = other.size;
    capacity = other.capacity;
    
    other.data = nullptr;
    other.size = 0;
    other.capacity = 0;
}


DynArray& DynArray::operator = (DynArray&& other) noexcept{
    if(this != &other){
        delete[] data;

        data = other.data;
        size = other.size;
        capacity = other.capacity;

        other.data = nullptr;
        other.size = 0;
        other.capacity = 0;

    }
    return *this;

}

DynArray& DynArray::operator=(const DynArray& other){
    if(this == &other){
       return *this;
    }
    delete[] data;
    size = other.size;
    capacity = other.capacity;
    data = new int[capacity];

    for(int i = 0; i < size; i++){
        data[i] = other.data[i];
    }
    return *this;
}


int DynArray::get_size() const {
    return size;
}

int DynArray::get_capacity() const {
    return capacity;
}

