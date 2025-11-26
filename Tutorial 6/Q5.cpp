#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
    Node* head;
public:
    LinkedList() {
        head = nullptr;
    }

    void insert(int val) {
        Node* newnode = new Node(val);
        if (!head) {
            head = newnode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newnode;
    }

    void makeCircular() {
        if (!head) return;
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = head;
    }

    bool isCircular() {
        if (!head) return false;

        Node* temp = head->next;

        while (temp != nullptr && temp != head) {
            temp = temp->next;
        }

        return (temp == head);
    }
};

int main() {
    LinkedList L;
    L.insert(10);
    L.insert(20);
    L.insert(30);

    if (L.isCircular())
        cout << "Circular Linked List" << endl;
    else
        cout << "Not a Circular Linked List" << endl;

    return 0;
}

