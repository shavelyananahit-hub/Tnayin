#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {

    Node* a1 = new Node{1, NULL};
    Node* a2 = new Node{2, NULL};
    Node* a3 = new Node{3, NULL};
    Node* a4 = new Node{4, NULL};
    Node* a5 = new Node{5, NULL};

    a1->next = a2;
    a2->next = a3;
    a3->next = a4;
    a4->next = a5;

    Node* head = a1;
    int count = 0;
    Node* temp = head;

    while (temp != NULL) {
     count++;
     temp = temp->next;
    }
    temp = head;

    for (int i = 0; i < count / 2; i++) {
     temp = temp->next;
    }
    cout << "Middle element= " << temp->data;
}