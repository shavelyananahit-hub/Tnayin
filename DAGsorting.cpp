#include <iostream>
using namespace std;

const int N = 100;

int a[N][N];
int count[N];
bool used[N];
int res[N];

int n = 5;

void top(int pos) {
    if (pos == n) {
        for (int i = 0; i < n; i++)
            cout << res[i] << " ";
        cout << endl;
        return;
    }

    for (int i = 0; i < n; i++) {

        if (!used[i] && count[i] == 0) {

            used[i] = true;
            res[pos] = i;

            for (int j = 0; j < n; j++) {
                if (a[i][j] != 0)
                    count[j]--;
            }

            top(pos + 1);

            used[i] = false;
            for (int j = 0; j < n; j++) {
                if (a[i][j] != 0)
                    count[j]++;
            }
        }
    }
}

int main() {

    a[0][1] = 1;
    a[0][2] = 1;
    a[1][3] = 1;
    a[2][3] = 1;
    a[3][4] = 1;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] != 0)
                count[j]++;

    top(0);
}