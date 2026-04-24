#include <iostream>
using namespace std;

bool visited[12][12] = {false};

void print(char arr[12][12], int i1, int j1, char dir) {

    cout << "Direction: " << dir << endl;

    for(int i = 0; i < 12; i++) {
        for(int j = 0; j < 12; j++) {
            if(i == i1 && j == j1)
                cout << 'o' << " ";
            else
                cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

bool move(char arr[12][12], int i, int j) {


    if(i < 0 || i >= 12 || j < 0 || j >= 12) {
        cout << "We arrived!" << endl;
        return true;
    }

if(arr[i][j] == '#' || visited[i][j])
    return false;

    visited[i][j] = true;

    char dirs[4] = {'>', 'v', '<', '^'};
    int di[4] = {0, 1, 0, -1};
    int dj[4] = {1, 0, -1, 0};

    for(int k = 0; k < 4; k++) {
        int i2 = i + di[k];
        int j2 = j + dj[k];

    print(arr, i, j, dirs[k]);
    cin.ignore();

        if(move(arr, i2, j2))
        return true;
    }

    return false;
}

int main() {
    int i = 2, j = 0;

    cout << "Press ENTER to start"<<endl;
    cin.ignore();

    char arr[12][12] = {
        '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#',
        '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#',
        ' ', ' ', '#', ' ', '#', ' ', '#', '#', '#', '#', ' ', '#',
        '#', '#', '#', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', '#',
        '#', ' ', ' ', ' ', ' ', '#', '#', '#', ' ', '#', ' ', '#',
        '#', '#', '#', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#',
        '#', ' ', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#',
        '#', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', ' ',
        '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#',
        '#', '#', '#', '#', '#', '#', ' ', '#', '#', '#', ' ', '#',
        '#', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#',
        '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'};

    if(!move(arr, i, j))
        cout << "No way!";

}