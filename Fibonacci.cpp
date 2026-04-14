#include <iostream>
#include <string>
using namespace std;

string sum(string a, string b) {
    string result = "";
    int carry = 0;

    int i = a.length() - 1;
    int j = b.length() - 1;

    while (i >= 0 || j >= 0 || carry > 0) {
        int sum = carry;

        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';

        result = char(sum % 10 + '0') + result;
        carry = sum / 10;
    }

    return result;
}

int fib(string a){
    string num1 = "1";
    string num2 = "1";
    int count = 2;

    if(a == "1")
        return 1;

    while (num2.length() < a.length() || 
          (num2.length() == a.length() && num2 < a)) {
        
        string b = sum(num1, num2);
        num1 = num2;
        num2 = b;
        count++;
    }

    if (num2 == a)
        return count;
    else
        return -1;
}

int main(){
    string a;
    cout << "a: ";
    cin >> a;

    cout << fib(a);
}