#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cout << "string: ";
    cin >> s;

    string result = "";
    int count = 1;

    for (int i = 1; i <= s.length(); i++) {
        if (i < s.length() && s[i] == s[i - 1]) {
            count++;
        } else {
            if (count >= 2) {
                if (count < 10) {
                    result += char(count + '0');
                } else {
                    string num = "";
                    int temp = count;

                    while (temp > 0) {
                        num = char(temp % 10 + '0') + num;
                        temp /= 10;
                    }
                    result += num;
                }
            }

            result += s[i - 1];

            count = 1;
        }
    }

  cout << "RLE string: " << result;

    return 0;
}