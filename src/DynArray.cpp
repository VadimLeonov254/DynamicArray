#include <iostream>
#include <stdexcept>

class DynArray {
private:
    int* data;
    int size = 0;
    int capacity = 2;

public:
    DynArray();
    DynArray(const DynArray& other);
    ~DynArray();
    void push_back(int x);
    void insert(int position, int element);
    void erase(int position);
    void clear();
    int get_size() const;
    int get_capacity() const;
    int& operator[](int index);
    const int& operator[](int index) const;
};

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

int DynArray::get_size() const {
    return size;
}

int DynArray::get_capacity() const {
    return capacity;
}

int main() {
    DynArray arr;
    //pushing numbers back in the dynamic array
    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);
    std::cout << "After push_back: ";
    for (int i = 0; i < arr.get_size(); i++)
        std::cout << arr[i] << " ";
    std::cout << "\n";

    //inserting a new element(15) in the position 1 -> .insert(position, element)
    arr.insert(1, 15);
    std::cout << "After insert at index 1: ";
    for (int i = 0; i < arr.get_size(); i++)
        std::cout << arr[i] << " ";
    std::cout << "\n";

    //erasing the element at the index of the dynamic array
    arr.erase(2);
    std::cout << "After erase at index 2: ";
    for (int i = 0; i < arr.get_size(); i++)
        std::cout << arr[i] << " ";
    std::cout << "\n";

    //clearing the entire dynamic array
    arr.clear();
    std::cout << "After clear, size = " << arr.get_size() << "\n";

    return 0;
}
