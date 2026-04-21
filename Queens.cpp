#include <iostream>
#include <cmath>
using namespace std;

int n, k;
int board[20][20];
bool found = false;

bool safe(int r, int c){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] == 1){
                if(i == r || j == c) return false;
                if(abs(i - r) == abs(j - c)) return false;
            }
        }
    }
    return true;
}

void print(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j]) cout << "Q ";
            else cout << ". ";
        }
        cout << endl;
    }
    cout << endl << endl;
}

void solution(int pos, int placed){
    if(placed == k){
        found = true;
        print();
        return;
    }

    if(pos == n*n) return;

    int r = pos / n;
    int c = pos % n;

    solution(pos + 1, placed);

    if(safe(r, c)){
        board[r][c] = 1;
        solution(pos + 1, placed + 1);
        board[r][c] = 0;
    }
}

int main(){
    cout<<"Enter n. ";
    cin >> n;
    
    cout <<"Enter number of queens. ";
    cin >> k;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            board[i][j] = 0;

    solution(0, 0);

    if(!found){
        cout << "No solution. " << endl;
    }
}