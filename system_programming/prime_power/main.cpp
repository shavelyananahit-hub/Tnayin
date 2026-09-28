#include <iostream>
#include "functions.h"

using namespace std;

int main()
{
    int n;
    int a, b;

    cout << "Enter a number to check if it is prime: ";
    cin >> n;

    if (isPrime(n))
        cout << n << " is prime." << endl;
    else
        cout << n << " is not prime." << endl;

    cout << "Enter base and exponent: ";
    cin >> a >> b;

    cout << a << "^" << b << " = " << power(a, b) << endl;

    return 0;
}
