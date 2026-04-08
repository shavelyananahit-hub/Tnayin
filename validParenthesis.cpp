#include <iostream>
using namespace std;

bool valid(string s) {
    char stack[s.length()];
    int top=-1;
    
    for(int i=0;i<s.length();i++) {
        char c=s[i];

        if(c=='(' || c=='[' || c=='{') {
            stack[++top]=c;
        } else {
            if(top==-1) return false;

            if(c == ')'&& stack[top] != '(') return false;
            if(c == ']'&& stack[top] != '[') return false;
            if(c == '}'&& stack[top] != '{') return false;

            top--;
        }
    }
    return top==-1;
}

int main() {
    string s;
    cout<<"Enrer string ";
    cin >> s;

    if(valid(s))
        cout << "True" << endl;
    else
        cout << "False" << endl;
}