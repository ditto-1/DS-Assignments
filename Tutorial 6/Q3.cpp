#include <iostream>
using namespace std;


struct DNode {
    int data;
    DNode* prev;
    DNode* next;
};

int sizeDoubly(DNode* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

void insertD(DNode*& head, int value) {
    DNode* newNode = new DNode{value, nullptr, nullptr};
    if (!head) {
        head = newNode;
        return;
    }
    DNode* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

struct CNode {
    int data;
    CNode* next;
};

int sizeCircular(CNode* head) {
    if (!head) return 0;
    int count = 0;
    CNode* temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}


void insertC(CNode*& head, int value) {
    CNode* newNode = new CNode{value, nullptr};
    if (!head) {
        head = newNode;
        newNode->next = head;
        return;
    }
    CNode* temp = head;
    while (temp->next != head)
        temp = temp->next;
    temp->next = newNode;
    newNode->next = head;
}

int main() {
    DNode* dhead = nullptr;
    insertD(dhead, 10);
    insertD(dhead, 20);
    insertD(dhead, 30);

    cout << "Size of Doubly Linked List: " << sizeDoubly(dhead) << endl;

    CNode* chead = nullptr;
    insertC(chead, 5);
    insertC(chead, 15);
    insertC(chead, 25);
    insertC(chead, 35);

    cout << "Size of Circular Linked List: " << sizeCircular(chead) << endl;
}
