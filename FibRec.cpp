#include <iostream>
using namespace std;

int fib(int x, int num1 = 1, int num2 = 1, int index = 2){
    if(x == 1) return 1;

    if(num2 == x)
        return index;

    if(num2 > x)
        return -1;

    return fib(x, num2, num1 + num2, index + 1);
}

int main(){
    int n;
    cout << "n: ";
    cin >> n;

    cout << fib(n);
}