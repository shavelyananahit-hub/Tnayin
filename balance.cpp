#include <iostream>
using namespace std;

string history[100];
int count = 0;

void addHistory(string s){
        history[count ++] = s;
}

int deposit(int bal, int a){
    bal = bal + a;
    addHistory(" + " + to_string(a));
    return bal;
}

int withdraw(int bal, int b){
    if(bal >= b){
        bal = bal - b;
        addHistory(" - " + to_string(b));
    } else {
        addHistory("Withdraw failed " + to_string(b));
    }
    return bal;
}

void balanc(int k){
    cout << "Balance: " << k << endl;
}

void showHistory(){
    for(int i = 0; i < count; i++){
        cout << history[i] << endl;
    }
}

int main(){
    int balance = 0;
    string command;
    int amount;

    bool session = false;
    int sessionSum = 0;

    cout << "Enter command." << endl;

    while(true){
        cin >> command;

        if(command == "enter"){
            session = true;
            sessionSum = 0;
            cout << "Session started." << endl;
        }
        else if(command == "exit"){
            session = false;
            cout << "Session ended."<< endl;
        }
        else if(command == "deposit"){
            if(!session){
                cout << "Start session first."<< endl;
                continue;
            }

            cin >> amount;
            if(!cin){
                cout << "Invalid input."<< endl;
            }

            if(amount <= 0){ 
                cout << "Amount must be positive."<< endl;
                continue;
            }

            if(sessionSum + amount >= 400){
                cout << "Limit reached․ Session ended․"<< endl;
                session = false;
            } else {
                balance = deposit(balance, amount);
                sessionSum += amount;
            }
        }
        
        else if(command == "withdraw"){
            if(!session){
                cout << "Start session first."<< endl;
                continue;
            }

            cin >> amount;
            if(!cin){
                cout << "Invalid input."<< endl;
            }

            if(amount <= 0){ 
                cout << "Amount must be positive."<< endl;
                continue;
            }

            balance = withdraw(balance, amount);
        }
        else if(command == "balance"){
            balanc(balance);
        }
        else if(command == "history"){
            showHistory();
        }
        else{
            cout << "Unknown command." << endl;
        }
    }
}