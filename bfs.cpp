#include <iostream>
#include <queue>
using namespace std;

const int N = 100;

int a[N][N];
bool used[N];
int n = 5;

void bfs(int start) {
    queue<int> q;

    q.push(start);
    used[start] = true;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        cout << v << " ";

        for (int i = 0; i < n; i++) {
            if (a[v][i] != 0 && !used[i]) {
                q.push(i);
                used[i] = true;
            }
        }
    }
}

int main() {
    a[0][1] = 1; a[1][0] = 1;
    a[0][3] = 1; a[3][0] = 1;
    a[1][2] = 1; a[2][1] = 1;
    a[3][4] = 1; a[4][3] = 1;

    bfs(0);
}