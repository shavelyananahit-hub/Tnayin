#include <iostream>
#include "statistics.h"

using namespace std;

int main()
{
    int numbers[10];

    cout << "Enter 10 numbers:" << endl;

    for (int i = 0; i < 10; i++)
        cin >> numbers[i];

    calculateStatistics(numbers, 10);

    return 0;
}
