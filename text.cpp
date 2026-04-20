#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string current = "";
    stack<string> st;

    string line;

    cout<< "Enter command. " << endl;
    while (getline(cin, line)) {

        string cmd = "";
        int i = 0;

        while (i < line.size() && line[i] != ' ') {
            cmd += line[i];
            i++;
        }

        if (i < line.size()) 
        i++;

        if (cmd == "type") {
            st.push(current);

            string text = "";
            while (i < line.size()) {
                text += line[i];
                i++;
            }

            current += text;
        }

        else if (cmd == "delete") {
            st.push(current);

            int k = 0;
            while (i < line.size()) {
                k = k * 10 + (line[i] - '0');
                i++;
            }

            if (k > current.size()) 
            k = current.size();

            string newStr = "";
            for (int j = 0; j < current.size() - k; j++) {
                newStr += current[j];
            }

            current = newStr;
        }

        else if (cmd == "print") {
            cout << current << endl;
        }

        else if (cmd == "undo") {
            if (st.size() != 0) {
                current = st.top();
                st.pop();
            }
        }

        else {
            cout << "Unknown command." << endl;
        }
    }
}