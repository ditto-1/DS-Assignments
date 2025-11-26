#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node *prev;
        Node(int a){
            data = a;
            next = nullptr;
            prev = nullptr;
        }
};

class clinkedlist{
    Node *head;
    public:
        clinkedlist(){
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

        int size(){
            Node *temp = head;
            int count = 1;
            while(temp->next != head){
                count++;
                temp = temp->next;
            }
            return count;
        }
};

class dlinkedlist{
    Node *head;
    public:
        dlinkedlist(){
            head = nullptr;
        }

        void insert(int a){
            Node *newnode = new Node(a);
            if (!head){
                head = newnode;
                return;
            }
            Node *temp = head;
            while(temp->next){
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->prev = temp;
        }

        int size(){
            Node* temp = head;
            int count = 0;
            while(temp != nullptr){
                count++;
                temp=temp->next;
            }
            return count;
        }
};

int main(){
    clinkedlist c;
    dlinkedlist d;
    c.insert(10);
    c.insert(20);
    c.insert(30);
    cout << c.size()<<endl;

    d.insert(1);
    d.insert(2);
    cout << d.size()<<endl;
}