#include "Array.h"
#include <iostream>
#include <string>

DynamicArray::DynamicArray(std::string type) {
    this->size = 0;
    if (type == "int") {
        isInt = true;
        arrInt = nullptr;
    }
    else if (type == "double") {
        isInt = false;
        arrDouble = nullptr;
    }
    else throw - 1;
}

DynamicArray::DynamicArray(int size, std::string type) {
    this->size = size;
    if (type == "int") {
        isInt = true;
        arrInt = new int[size];
        for (int i = 0; i < size; i++) {
            arrInt[i] = 0;
        }
    }
    else if (type == "double") {
        isInt = false;
        arrDouble = new double[size];
        for (int i = 0; i < size; i++) {
            arrDouble[i] = (double)0;
        }
    }
    else throw -1;
}

void DynamicArray::insert(int pos, int value) {
    if (!isInt) throw - 1;
    if (pos < 0 || pos >= size) throw - 1;
    size++;
    int* newArr = new int[size];
    for (int i = 0; i < pos; i++) {
        newArr[i] = arrInt[i];
    }
    newArr[pos] = value;
    for (int i = pos + 1; i < size; i++) {
        newArr[i] = arrInt[i - 1];
    }
    delete[] arrInt;
    arrInt = newArr;
};

void DynamicArray::insert(int pos, double value) {
    if (isInt) throw - 1;
    if (pos < 0 || pos >= this->size) throw - 1;
    size++;
    double* newArr = new double[size];
    for (int i = 0; i < pos; i++) {
        newArr[i] = arrDouble[i];
    }
    newArr[pos] = value;
    for (int i = pos + 1; i < size; i++) {
        newArr[i] = arrDouble[i - 1];
    }
    delete[] arrDouble;
    arrDouble = newArr;
};

void DynamicArray::pushBack(int value) {
    if (!isInt) throw - 1;
    size++;
    int* newArr = new int[size];
    for (int i = 0; i < size - 1; i++) {
        newArr[i] = arrInt[i];
    }
    newArr[size - 1] = value;
    delete[] arrInt;
    arrInt = newArr;
};

void DynamicArray::pushBack(double value) {
    if (isInt) throw - 1;
    size++;
    double* newArr = new double[size];
    for (int i = 0; i < size - 1; i++) {
        newArr[i] = arrDouble[i];
    }
    newArr[size - 1] = value;
    delete[] arrDouble;
    arrDouble = newArr;
};

std::variant<int, double> DynamicArray::back() {
    if (!size) throw - 1;
    return (isInt ? arrInt[size - 1] : arrDouble[size - 1]);
};

std::variant<int, double> DynamicArray::at(int position) {
    return (isInt ? arrInt[position] : arrDouble[position]);
};

void DynamicArray::at(int position, int value) {
    if (!isInt) throw - 1;
    if (position < 0 || position >= size) throw - 1;
    arrInt[position] = value;
};

void DynamicArray::at(int position, double value) {
    if (isInt) throw - 1;
    arrDouble[position] = value;
};

std::variant<int, double> DynamicArray::max(std::string type) {
    if (type != "index" && type != "value") throw - 1;
    int maxIndex = 0;
    int maxValueInt = 0;
    double maxValueDouble = (double)0;

    if (isInt) {
        maxValueInt = arrInt[0];
        for (int i = 1; i < size; i++) {
            if (arrInt[i] > maxValueInt) {
                maxValueInt = arrInt[i];
                maxIndex = i;
            }
        }
    }
    else {
        maxValueDouble = arrDouble[0];
        for (int i = 1; i < size; i++) {
            if (arrDouble[i] > maxValueDouble) {
                maxValueDouble = arrDouble[i];
                maxIndex = i;
            }
        }
    }
    return (type == "index" ? maxIndex : (isInt ? maxValueInt : maxValueDouble));
}

void DynamicArray::copy(DynamicArray other) {
    if (this->getType() != other.getType()) throw - 1;
    this->size = other.length();
    if (isInt) {
        int* newArr = new int[size];
        for (int i = 0; i < size; i++) {
            newArr[i] = std::get<1>(other.at(i));
        }
        delete[] arrInt;
        arrInt = newArr;
    }
    else {
        double* newArr = new double[size];
        for (int i = 0; i < size; i++) {
            newArr[i] = std::get<1>(other.at(i));
        }
        delete[] arrDouble;
        arrDouble = newArr;
    }
}

std::string DynamicArray::getType() {
    return (isInt ? "int" : "double");
}

void DynamicArray::resize(int size) {
    if (size < 0) throw - 1;
    if (size == this->size) return;
    if (isInt) {
        int* newArr = new int[size];
        if (size > this->size) {
            for (int i = 0; i < this->size; i++) {
                newArr[i] = arrInt[i];
            }
            for (int i = this->size; i < size; i++) {
                newArr[i] = 0;
            }
        }
        else {
            for (int i = 0; i < size; i++) {
                newArr[i] = arrInt[i];
            }
        }
        delete[] arrInt;
        arrInt = newArr;
    } else {
        double* newArr = new double[size];
        if (size > this->size) {
            for (int i = 0; i < this->size; i++) {
                newArr[i] = arrDouble[i];
            }
            for (int i = this->size; i < size; i++) {
                newArr[i] = 0;
            }
        }
        else {
            for (int i = 0; i < size; i++) {
                newArr[i] = arrDouble[i];
            }
        }
        delete[] arrDouble;
        arrDouble = newArr;
    }
    this->size = size;
};

int DynamicArray::length() {
    return size;
}