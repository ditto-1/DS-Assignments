#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insert(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }
}

int countAndDelete(Node*& head, int key) {
    int count = 0;

    while (head && head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        count++;
    }

    Node* curr = head;
    while (curr && curr->next) {
        if (curr->next->data == key) {
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
            count++;
        } else {
            curr = curr->next;
        }
    }

    return count;
}

void display(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << "->";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    insert(head, 1);
    insert(head, 2);
    insert(head, 1);
    insert(head, 2);
    insert(head, 1);
    insert(head, 3);
    insert(head, 1);

    cout << "Original List: ";
    display(head);

    int key = 1;
    int count = countAndDelete(head, key);

    cout << "Count of " << key << ": " << count << endl;
    cout << "Updated Linked List: ";
    display(head);
}
