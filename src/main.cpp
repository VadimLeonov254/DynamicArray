#include<iostream>
#include "DynArray.h"

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
