#include <iostream>
using namespace std;

const int N = 100;

int a[N][N];
bool used[N];
int top[N], t = 0;

int dist[N];
int parent[N];

int n = 5; 

void sort(int x) {
    used[x] = true;

    for (int i = 0; i < n; i++) {
        if (a[x][i] != 0 && !used[i]) {
            sort(i);
        }
    }

    top[t++] = x;
}

int main() {

    a[0][1] = 3;
    a[0][2] = 20;
    a[1][3] = 24;
    a[2][3] = 16;
    a[3][4] = 5;

    for (int i = 0; i < n; i++)
        if (!used[i])
            sort(i);

    for (int i = 0; i < n; i++) {
        dist[i] = -1;
        parent[i] = -1;
    }

    dist[0] = 0;

    for (int i = t - 1; i >= 0; i--) {
        int x = top[i];

        if (dist[x] == -1) continue;

        for (int j = 0; j < n; j++) {
            if (a[x][j] != 0) {
                if (dist[j] < dist[x] + a[x][j]) {
                    dist[j] = dist[x] + a[x][j];
                    parent[j] = x;
                }
            }
        }
    }

    int max = 0;
    for (int i = 0; i < n; i++) {
        if (dist[i] > dist[max])
            max = i;
    }

    cout << "Longest length = " << dist[max] << endl;

    int path[N], k = 0;

    while (max != -1) {
        path[k++] = max;
        max = parent[max];
    }

    cout << "Path: ";
    for (int i = k - 1; i >= 0; i--) {
        cout << path[i] << " ";
    }
}