#include <iostream>
using namespace std;

int fact(int x, int i = 2){
    if(x == 1)
        return i - 1;

    if(x % i != 0)
        return -1;

    return fact(x / i, i + 1);
}

int main(){
    int n;
    cout << "n: ";
    cin >> n;

    cout << fact(n);
} 