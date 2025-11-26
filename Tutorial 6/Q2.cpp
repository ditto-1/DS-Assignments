#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(int v){
            data = v;
            next = nullptr;
        }
};

class linkedlist{
    Node *head;
    public:
        linkedlist(){
            head = nullptr;
        }

        void insert(int a){
            Node *newnode = new Node(a);
            if (!head){
                head = newnode;
                newnode->next = head;
                return;
            }

            Node *temp = head;
            while(temp->next != head){
                temp = temp->next;
            }
            newnode->next = head;
            temp->next = newnode;
        }

        void display(){
            Node *temp = head;
            do {
                cout << temp->data << "->";
                temp = temp->next;
            } while (temp != head);
            cout << head->data<<endl;
        }
};

int main(){
    linkedlist l1;
    l1.insert(20);
    l1.insert(100);
    l1.insert(40);
    l1.insert(80);
    l1.display();
}