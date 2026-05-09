#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {

    Node* a1 = new Node{1, NULL};
    Node* a2 = new Node{3, NULL};
    Node* a3 = new Node{5, NULL};

    a1->next = a2;
    a2->next = a3;

    Node* b1 = new Node{2, NULL};
    Node* b2 = new Node{4, NULL};
    Node* b3 = new Node{6, NULL};

    b1->next = b2;
    b2->next = b3;

    Node* x = a1;
    Node* y = b1;

    while (x != NULL && y != NULL) {

        if (x->data < y->data) {
          cout << x->data << " ";
            x = x->next;
        }
        else {
            cout << y->data << " ";
             y = y->next;
        }
    }

    while (x != NULL) {
       cout << x->data << " ";
        x = x->next;
    }

    while (y != NULL) {
        cout << y->data << " ";
        y = y->next;
    }
}