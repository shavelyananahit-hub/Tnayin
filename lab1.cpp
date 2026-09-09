#include <iostream>
#include <string>
using namespace std;

int main()
{
    string input;

    cout << "Enter an integer: ";
    cin >> input;

    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] < '0' || input[i] > '9')
        {
            cout << "Invalid input!";
            return 0;
        }
    }

    int n = stoi(input);

    if (n > 20)
    {
        cout << "Number is too large!";
        return 0;
    }

    unsigned long long factorial = 1;

    for (int i = 1; i <= n; i++)
    {
        factorial = factorial * i;
        cout << i << "! = " << factorial << endl;
    }

    if (n == 0)
    {
        cout << "0! = 1";
    }

    return 0;
}
