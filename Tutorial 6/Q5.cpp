#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};


void insert(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

void makeCircular(Node* head) {
    if (!head) return;
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = head;  
}

bool isCircular(Node* head) {
    if (head == nullptr)
        return false;

    Node* temp = head->next;
    while (temp != nullptr && temp != head)
        temp = temp->next;

    return (temp == head);
}

int main() {
    Node* head = nullptr;

     insert(head, 10);
    insert(head, 20);
    insert(head, 30);

    cout << "Initially checking normal linked list:\n";
    if (isCircular(head))
        cout << "The linked list is circular.\n";
    else
        cout << "The linked list is NOT circular.\n";


    makeCircular(head);
    cout << "\nAfter making it circular:\n";
    if (isCircular(head))
        cout << "The linked list is circular.\n";
    else
        cout << "The linked list is NOT circular.\n";
}

