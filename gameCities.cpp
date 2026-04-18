#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main() {
    ifstream file("worldcities.csv");

    if (!file.is_open()) {
        cout << "File not found!\n";
        return 1;
    }

    string cities[50000]; 
    int n = 0;

    string line;
    getline(file, line); 

    
    while (getline(file, line)) {
        stringstream ss(line);
        string temp;

        getline(ss, temp, ','); // id
        getline(ss, cities[n], ','); // city
        n++;
    }

    file.close();

    string used[50000];
    int usedCount = 0;

    char lastChar = 0;

    cout << "Game started!\n";

    while (true) {
        string input;
        cout << "Enter city: ";
        cin >> input;

       
        bool exists = false;
        for (int i = 0; i < n; i++) {
            if (cities[i] == input) {
                exists = true;
                break;
            }
        }

        if (!exists) {
            cout << "Wrong city!\n";
            continue;
        }

       
        bool already = false;
        for (int i = 0; i < usedCount; i++) {
            if (used[i] == input) {
                already = true;
                break;
            }
        }

        if (already) {
            cout << "Already used!\n";
            continue;
        }

        if (lastChar != 0 && input[0] != lastChar) {
            cout << "Wrong letter! պետք է սկսվի " << lastChar << endl;
            continue;
        }

        used[usedCount++] = input;

        lastChar = input[input.length() - 1];

        bool found = false;

        for (int i = 0; i < n; i++) {
            if (cities[i][0] == lastChar) {

                bool usedBefore = false;
                for (int j = 0; j < usedCount; j++) {
                    if (used[j] == cities[i]) {
                        usedBefore = true;
                        break;
                    }
                }

                if (!usedBefore) {
                    cout << "Computer: " << cities[i] << endl;

                    used[usedCount++] = cities[i];
                    lastChar = cities[i][cities[i].length() - 1];

                    found = true;
                    break;
                }
            }
        }

        if (!found) {
            cout << "You win!\n";
            break;
        }
    }

    return 0;
}