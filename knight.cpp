#include <iostream>
using namespace std;

int board[8][8];

void printBoard() {
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            cout << board[i][j] << "  " ;
        }
        cout << endl;
    }
}

bool move(int i, int j, int step) {
    if(i < 0 || i >= 8 || j < 0 || j >= 8)
        return false;

    if(board[i][j] != -1)
        return false;

    board[i][j] = step;

    if(step == 64) {
        printBoard();
        return true;
    }

    int x[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int y[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

    for(int k = 0; k < 8; k++) {
        int i2 = i + x[k];
        int j2 = j + y[k];

        if(move(i2, j2, step + 1))
            return true;
    }

    board[i][j] = -1;
    return false;
}

int main() {
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            board[i][j] = -1;
        }
    }

    if(!move(0, 0, 1))
        cout << "Noooo!" << endl;

    return 0;
}