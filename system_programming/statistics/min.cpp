#include "statistics.h"

int findMin(int numbers[], int size)
{
    int min = numbers[0];

    for (int i = 1; i < size; i++)
    {
        if (numbers[i] < min)
            min = numbers[i];
    }

    return min;
}
