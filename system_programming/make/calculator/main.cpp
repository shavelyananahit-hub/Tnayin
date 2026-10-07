#include <iostream>
#include "calculator.h"

int main()
{
    int a = 20;
    int b = 5;

    std::cout << "Add: " << add(a, b) << std::endl;
    std::cout << "Subtract: " << subtract(a, b) << std::endl;
    std::cout << "Multiply: " << multiply(a, b) << std::endl;
    std::cout << "Divide: " << divide(a, b) << std::endl;

    return 0;
}
