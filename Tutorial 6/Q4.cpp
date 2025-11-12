#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* prev;
    Node* next;
};

void insert(Node*& head, char value) {
    Node* newNode = new Node{value, nullptr, nullptr};
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

bool isPalindrome(Node* head) {
    if (!head) return true;

    Node* left = head;
    Node* right = head;
while (right->next)
        right = right->next;

    while (left != right && right->next != left) {
        if (left->data != right->data)
            return false;
        left = left->next;
        right = right->prev;
    }
    return true;
}

int main() {
    Node* head = nullptr;

    insert(head, 'R');
    insert(head, 'A');
    insert(head, 'D');
    insert(head, 'A');
    insert(head, 'R');

    if (isPalindrome(head))
        cout << "The linked list is a palindrome.\n";
    else
        cout << "The linked list is NOT a palindrome.\n";
}
