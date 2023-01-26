#include <iostream> 
#include <vector>
#include <string>
#include <variant>

class DynamicArray {
private:
    int size;
    bool isInt;
    int* arrInt;
    double* arrDouble;
public:
    DynamicArray(std::string type);
    DynamicArray(int size, std::string type);

    void insert(int pos, int value);
    void insert(int pos, double value);

    void pushBack(int value);
    void pushBack(double value);

    std::variant<int, double> back();

    std::variant<int, double> at(int position);
    void at(int position, int value);
    void at(int position, double value);

    std::variant<int, double> max(std::string type);

    void copy(DynamicArray other);

    std::string getType();

    void resize(int size);

    int length();
};