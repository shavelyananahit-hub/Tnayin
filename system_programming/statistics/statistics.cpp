#include <iostream>
#include "statistics.h"

using namespace std;

void calculateStatistics(int numbers[], int size)
{
    int min = findMin(numbers, size);
    int max = findMax(numbers, size);
    int sum = calculateSum(numbers, size);
    double average = calculateAverage(sum, size);

    cout << "Min: " << min << endl;
    cout << "Max: " << max << endl;
    cout << "Sum: " << sum << endl;
    cout << "Average: " << average << endl;
}
