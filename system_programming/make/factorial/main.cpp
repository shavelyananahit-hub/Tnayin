#include "get_number.h"
#include "check_number.h"
#include "calculate_factorial.h"
#include "print_result.h"

int main()
{
    int n = get_number();

    if (!check_number(n))
    {
        return 1;
    }

    long long result = calculate_factorial(n);

    print_result(result);

    return 0;
}
