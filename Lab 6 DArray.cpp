
#ifndef DARRAY_H
#define DARRAY_H

#include <iostream>
using namespace std;

class DArray {
private:
    int* arr;
    int currentSize;
    int currentCapacity;

public:
    DArray();

    // Existing functions
    void push_back(int value);
    ~DArray();

    // Required new functions
    int size() const;
    int capacity() const;

    DArray(const DArray& other);

    const int& operator[](int index) const;

    bool operator==(const DArray& other) const;

    friend ostream& operator<<(ostream& os, const DArray& obj);
};

#endif


#include "DArray.h"

DArray::DArray()
    : arr(nullptr), currentSize(0), currentCapacity(0) {
}

// Size function
int DArray::size() const {
    return currentSize;
}

// Capacity function
int DArray::capacity() const {
    return currentCapacity;
}

// Copy constructor
DArray::DArray(const DArray& other) {
    currentSize = other.currentSize;
    currentCapacity = other.currentCapacity;

    if (currentCapacity > 0) {
        arr = new int[currentCapacity];

        for (int i = 0; i < currentSize; i++) {
            arr[i] = other.arr[i];
        }
    }
    else {
        arr = nullptr;
    }
}

// Subscript operator
const int& DArray::operator[](int index) const {
    return arr[index];
}

// Equality operator
bool DArray::operator==(const DArray& other) const {
    if (currentSize != other.currentSize) {
        return false;
    }

    for (int i = 0; i < currentSize; i++) {
        if (arr[i] != other.arr[i]) {
            return false;
        }
    }

    return true;
}

// Destructor
DArray::~DArray() {
    delete[] arr;
}

#include "DArray.h"
#include <iostream>
using namespace std;

int main() {

    DArray darr1;

    for (int j{}; j < 15; ++j) {
        darr1.push_back(j * 2);

        cout << darr1.size() << '\t'
             << darr1.capacity() << endl;
    }

    cout << darr1 << endl;

    const DArray darr2{darr1};

    for (int j{}; j < 15; ++j) {
        cout << darr2[j] << ' ';
    }

    cout << endl;

    if (darr1 == darr2)
        cout << "darr1 & darr2 are equal" << endl;
    else
        cout << "darr1 & darr2 are not equal" << endl;

    return 0;
}

