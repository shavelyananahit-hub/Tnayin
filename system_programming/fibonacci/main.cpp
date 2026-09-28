#include <iostream>
#include "fibonacci.h"

using namespace std;

int main()
{
    int n;

    cout << "Enter the number: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << fibonacci(i) << " ";
    }

    cout << endl;

    return 0;
}
