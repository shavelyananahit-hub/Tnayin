#include <iostream>
using namespace std;

const int INF = 1000000;
const int N = 100;

int n = 5;
int a[N][N] = {
    {0, 2, 0, 1, 0},
    {2, 0, 3, 2, 0},
    {0, 3, 0, 0, 1},
    {1, 2, 0, 0, 3},
    {0, 0, 1, 3, 0}
};

int dist[N];
bool used[N];

int main() {
    int start = 0;

    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        used[i] = false;
    }

    dist[start] = 0;

    for (int i = 0; i < n; i++) {
        int v = -1;

        for (int j = 0; j < n; j++)
            if (!used[j] && (v == -1 || dist[j] < dist[v]))
                v = j;

        used[v] = true;

        for (int j = 0; j < n; j++) {
            if (a[v][j] != 0) {
                if (dist[v] + a[v][j] < dist[j]) {
                    dist[j] = dist[v] + a[v][j];
                }
            }
        }
    }

    cout << "Distances:"<< endl;
    for (int i = 0; i < n; i++)
        cout << "0 -> " << i << " : " << dist[i] << endl;
}