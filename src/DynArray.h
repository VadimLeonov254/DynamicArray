#ifndef DYNARRAY_H
#define DYNARRAY_H

#include<iostream>
#include<stdexcept>


class DynArray {
private:
    int* data;
    int size = 0;
    int capacity = 2;

public:
    DynArray();
    DynArray(const DynArray& other);
    ~DynArray();
    DynArray(DynArray&& other) noexcept;
    DynArray& operator = (DynArray&& other) noexcept;
    DynArray& operator = (const DynArray& other);
    void push_back(int x);
    void insert(int position, int element);
    void erase(int position);
    void clear();
    int get_size() const;
    int get_capacity() const;
    int& operator[](int index);
    const int& operator[](int index) const;
};


#endif
