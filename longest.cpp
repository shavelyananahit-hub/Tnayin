#include <iostream>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    int maxLen = 0;
    int maxStart = 0;

    for (int i = 0; i < a.size(); i++) {
        int len = 0;

        for (int j = 0; j < b.size() && i + j < a.size(); j++) {
            if (a[i + j] == b[j]) {
                len++;
            } else {
                break;
            }
        }

        if (len > maxLen) {
            maxLen = len;
            maxStart = i;
        }
    }

    cout << a.substr(maxStart, maxLen);
}