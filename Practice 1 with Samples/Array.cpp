#include "Array.h"
#include <iostream>

Array::Array() : data(nullptr), size(0) {}


Array::Array(size_t n) : size(n) {
    data = new int[n];
    for (size_t i = 0; i < n; ++i) {
        data[i] = 0;
    }
}


Array::Array(size_t n, int min, int max) : size(n) {
    data = new int[n];
    for (size_t i = 0; i < n; ++i) {
        data[i] = min + (i % (max - min + 1));
    }
}

Array::~Array() {
    delete[] data;
}


void Array::display() const {
    for (size_t i = 0; i < size; ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}


void Array::init(int min, int max) {
    for (size_t i = 0; i < size; ++i) {
        data[i] = min + (i % (max - min + 1));
    }
}


void Array::resize(size_t newSize) {
    int* newData = new int[newSize];
    for (size_t i = 0; i < (size < newSize ? size : newSize); ++i) {
        newData[i] = data[i];
    }
    for (size_t i = size; i < newSize; ++i) {
        newData[i] = 0;
    }
    delete[] data;
    data = newData;
    size = newSize;
}


int Array::findMin() const {
    if (size == 0) return 0;
    int minVal = data[0];
    for (size_t i = 1; i < size; ++i) {
        if (data[i] < minVal) minVal = data[i];
    }
    return minVal;
}


int Array::findMax() const {
    if (size == 0) return 0;
    int maxVal = data[0];
    for (size_t i = 1; i < size; ++i) {
        if (data[i] > maxVal) maxVal = data[i];
    }
    return maxVal;
}


void Array::sort() {
    for (size_t i = 0; i < size - 1; ++i) {
        for (size_t j = 0; j < size - i - 1; ++j) {
            if (data[j] > data[j + 1]) {
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}