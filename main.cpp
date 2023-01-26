#pragma once
#include <iostream>
#include "Array.h"


int main() {
    // int
    DynamicArray arrayInt(5, "int");
    std::cout << arrayInt.length() << "\n"; // ouptut: 5
    arrayInt.pushBack(2);
    std::cout << std::get<1>(arrayInt.back()) << "\n"; // ouptut: 2
    arrayInt.pushBack(3);
    std::cout << std::get<1>(arrayInt.back()) << "\n"; // ouptut: 3
    arrayInt.insert(0, 5);
    std::cout << std::get<1>(arrayInt.at(0)) << "\n"; // ouptut: 5
    arrayInt.at(0, 7);
    std::cout << std::get<1>(arrayInt.at(0)) << "\n"; // ouptut: 7
    std::cout << arrayInt.length() << "\n"; // ouptut: 8
    std::cout << std::get<1>(arrayInt.max("index")) << "\n"; // ouptut: 0
    std::cout << std::get<1>(arrayInt.max("value")) << "\n"; // ouptut: 7
    arrayInt.resize(10);
    std::cout << arrayInt.length() << "\n"; // ouptut: 10
    std::cout << std::get<1>(arrayInt.at(9)) << "\n"; // ouptut: 0
    arrayInt.resize(1);
    std::cout << std::get<1>(arrayInt.at(0)) << "\n"; // ouptut: 7
    arrayInt.resize(0);
    DynamicArray arrayInt2(3, "int");
    arrayInt2.pushBack(12);
    arrayInt2.pushBack(14);
    arrayInt2.pushBack(8);
    arrayInt.copy(arrayInt2);
    std::cout << (arrayInt.length() == arrayInt2.length()) << "\n"; // ouptut: 1
    std::cout << (arrayInt.at(5) == arrayInt2.at(5)) << "\n"; // ouptut: 1

    // double
    DynamicArray arrayDouble(5, "double");
    std::cout << arrayDouble.length() << "\n"; // ouptut: 5
    arrayDouble.pushBack(2.6);
    std::cout << std::get<1>(arrayDouble.back()) << "\n"; // ouptut: 2.6
    arrayDouble.pushBack(3.1);
    std::cout << std::get<1>(arrayDouble.back()) << "\n"; // ouptut: 3.1
    arrayDouble.insert(0, 5.6);
    std::cout << std::get<1>(arrayDouble.at(0)) << "\n"; // ouptut: 5.6
    arrayDouble.at(0, 2.4);
    std::cout << std::get<1>(arrayDouble.at(0)) << "\n"; // ouptut: 2.4
    std::cout << arrayDouble.length() << "\n"; // ouptut: 8
    std::cout << std::get<1>(arrayDouble.max("index")) << "\n"; // ouptut: 7
    std::cout << std::get<1>(arrayDouble.max("value")) << "\n"; // ouptut: 3.1
    arrayDouble.resize(10);
    std::cout << arrayDouble.length() << "\n"; // ouptut: 10
    std::cout << std::get<1>(arrayDouble.at(9)) << "\n"; // ouptut: 0
    arrayDouble.resize(1);
    std::cout << std::get<1>(arrayDouble.at(0)) << "\n"; // ouptut: 2.4
    arrayDouble.resize(0);
    DynamicArray arrayDouble2(3, "double");
    arrayDouble2.pushBack(12.7);
    arrayDouble2.pushBack(14.9);
    arrayDouble2.pushBack(8.1);
    arrayDouble.copy(arrayDouble2);
    std::cout << (arrayDouble.length() == arrayDouble2.length()) << "\n"; // ouptut: 1
    std::cout << (arrayDouble.at(5) == arrayDouble2.at(5)) << "\n"; // ouptut: 1
}