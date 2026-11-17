
#ifndef DARRAY_H
#define DARRAY_H

#include <iostream>
using namespace std;

class DArray {
private:
    int* arr;
    int size;
    int capacity;

public:
    DArray();
    void push_back(int value);
    DArray& operator=(const DArray& other);

    friend ostream& operator<<(ostream& os, const DArray& obj);
};

#endif

#include "DArray.h"

// 1. Default Constructor
DArray::DArray() {
    arr = nullptr;
    size = 0;
    capacity = 0;
}

// 2. push_back()
void DArray::push_back(int value) {

    if (size == capacity) {

        capacity = (capacity == 0) ? 1 : capacity * 2;

        int* new_arr = new int[capacity];

        for (int i = 0; i < size; i++) {
            new_arr[i] = arr[i];
        }

        delete[] arr;

        arr = new_arr;
    }

    arr[size] = value;
    size++;
}

// 3. Assignment Operator
DArray& DArray::operator=(const DArray& other) {

    if (this != &other) {

        delete[] arr;

        size = other.size;
        capacity = other.capacity;

        arr = new int[capacity];

        for (int i = 0; i < size; i++) {
            arr[i] = other.arr[i];
        }
    }

    return *this;
}

// 4. Output Operator
ostream& operator<<(ostream& os, const DArray& obj) {

    for (int i = 0; i < obj.size; i++) {
        os << obj.arr[i] << " ";
    }

    return os;
}

#include <iostream>
#include "DArray.h"
using namespace std;

int main() {

    DArray darr1, darr2;

    for (int j{}; j < 15; ++j) {
        darr1.push_back(j * 2);
    }

    cout << darr1 << endl;

    darr2 = darr1;

    for (int j{15}; j >= 0; --j) {
        darr2.push_back(j * 3);
    }

    cout << darr2 << endl;

    return 0;
}
