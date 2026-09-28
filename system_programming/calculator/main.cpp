#include <iostream>
#include "calculator.h"

using namespace std;

int main()
{
    double a, b;

    cout << "Enter two numbers: ";
    cin >> a >> b;

    cout << "Sum: " << add(a, b) << endl;
    cout << "Difference: " << subtract(a, b) << endl;
    cout << "Product: " << multiply(a, b) << endl;

    if (b != 0)
        cout << "Quotient: " << divide(a, b) << endl;
    else
        cout << "Cannot divide by zero." << endl;

    return 0;
}
