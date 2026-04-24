#include <iostream>
#include <string>
using namespace std;

int count = 0;

void decoder(string number, int i, string current) {
    if (i == number.length()) {
        cout << current << endl;
        count++;
        return;
    }

    int x = number[i] - '0';
    if (x >= 1 && x <= 9) {
        decoder(number, i + 1, current + char('A' + x - 1));
    }

    if (i + 1 < number.length()) {
        int y = (number[i] - '0') * 10 + (number[i + 1] - '0');
        if (y >= 10 && y <= 26) {
            decoder(number, i + 2, current + char('A' + y - 1));
        }
    }
}

int main() {
    string number;
    cout << "Enter number. ";
    cin >> number;

    decoder(number, 0, "");

    cout << "Count: " << count;
}