#include <iostream>
#include <string>
using namespace std;

string convert(string a, int base1, int base2) {
    int decimal = 0;
    for (int i = 0; i < a.length(); i++) {
        decimal = decimal * base1 + (a[i] - '0');
    }

    if (decimal == 0) return "0";

    string result = "";
    while (decimal > 0) {
        result = char((decimal % base2) + '0') + result;
        decimal /= base2;
    }

    return result;
}

int main() {
    string num = "100780";
    int base1 = 9;
    int base2 = 7;

    cout << convert(num, base1, base2);
}