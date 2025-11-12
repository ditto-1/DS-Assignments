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
        newNode->next = head;
        return;
    }
    Node* temp = head;
    while (temp->next != head)
        temp = temp->next;
    temp->next = newNode;
    newNode->next = head;
}

void displayCircular(Node* head) {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << head->data << endl; 
}

int main() {
    Node* head = nullptr;
    insert(head, 20);
    insert(head, 100);
    insert(head, 40);
    insert(head, 80);
    insert(head, 60);

    cout << "Circular Linked List: ";
    displayCircular(head);
}

