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

bool used[N];
int minEdge[N];
int parent[N];

int main() {
    for (int i = 0; i < n; i++) {
        minEdge[i] = INF;
        used[i] = false;
    }

    minEdge[0] = 0;

    for (int i = 0; i < n; i++) {
        int v = -1;

        for (int j = 0; j < n; j++)
            if (!used[j] && (v == -1 || minEdge[j] < minEdge[v]))
                v = j;

        used[v] = true;

        for (int j = 0; j < n; j++) {
            if (a[v][j] != 0 && a[v][j] < minEdge[j]) {
                minEdge[j] = a[v][j];
                parent[j] = v;
            }
        }
    }

    cout << "Edges:" << endl;
    for (int i = 1; i < n; i++)
        cout << parent[i] << " -> " << i << endl;
}