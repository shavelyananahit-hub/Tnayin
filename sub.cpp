#include <iostream>
#include <string>
using namespace std;

string sub(string a, string b) {

    if (a.length() < b.length() || (a.length() == b.length() && a < b)) {
        return "-" + sub(b, a);
    }

    string result = "";

    int i = a.length() - 1;
    int j = b.length() - 1;
    int d = 0;

    while (i >= 0) {
        int numA = a[i] - '0';
        int numB = (j >= 0) ? b[j] - '0' : 0;

        numA -= d;

        if (numA < numB) {
            numA += 10;
            d = 1;
        } else {
            d = 0;
        }

        int s = numA - numB;
        result = char(s + '0') + result;

        i--;
        j--;
    }

    int k = 0;
    while (k < result.length() - 1 && result[k] == '0') k++;

    return result.substr(k);
}

int main() {
    string a, b;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;

    cout << "Result = " << sub(a, b);

    return 0;
}