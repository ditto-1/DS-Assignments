#include <iostream>
using namespace std;

class Node {
    public:
    char data;
    Node* prev;
    Node* next;
    Node(char c){
        data = c;
        prev = nullptr;
        next = nullptr;
    }
};

class linkedlist{
    Node* head;
    public:
        linkedlist(){
            head = nullptr;
        }

        void insert(char value){
            Node* newnode = new Node(value);
            if (!head) {
                head = newnode;
                return;
            }
            Node* temp = head;
            while (temp->next)
                temp = temp->next;
            temp->next = newnode;
            newnode->prev = temp;
        }

        bool isPalindrome(){
            Node *left = head;
            Node *right = head;
            while(right->next)
                right = right->next;
            
            while(left != right){
                if (left->data != right->data) return false;
                left = left->next;
                right = right->prev;
            }
            return true;
        }
};

int main() {
    linkedlist l1;
    l1.insert('L');
    l1.insert('E');
    l1.insert('V');
    l1.insert('A');
    l1.insert('L');

    if (l1.isPalindrome())
        cout << "The linked list is a palindrome.\n";
    else
        cout << "The linked list is NOT a palindrome.\n";
}
