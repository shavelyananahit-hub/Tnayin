#include "functions.h"

bool isPrime(int n)
{
    if (n < 2)
        return false;

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}

int power(int a, int b)
{
    if (b == 0)
        return 1;

    return a * power(a, b - 1);
}
