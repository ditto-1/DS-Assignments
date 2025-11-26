#include <iostream>
using namespace std;

class Node{
    public:
    int coeff, power;
    Node *next;
    Node(int c, int p){
        coeff = c;
        power = p;
        next = nullptr;
    }
};

class linkedlist{
    Node *head;
    public:
        linkedlist(){
            head = nullptr;
        }

        void insert(int a, int b){
            Node *newnode = new Node(a, b);
            if (!head){
                head = newnode;
                return;
            }

            Node *temp = head;
            while(temp->next){
                temp = temp->next;
            }
            temp->next = newnode;
        }

        void display(){
            Node *temp = head;
            while(temp){
                cout << "["<<temp->coeff<<", "<<temp->power<<"]"<<"->";
                temp=temp->next;
            }
            cout << endl;
        }

        friend void sum(linkedlist &A, linkedlist &B);

        Node* gethead(){
            return head;
        }
};

void sum(linkedlist &A, linkedlist &B){
    Node *h1 = A.gethead();
    Node *h2 = B.gethead();
    while(h1){
        int p = h1->power;
        while(h2){
            if (p == h2->power){
                h1->coeff += h2->coeff;
                break;
            }
            h2 = h2->next;
        }
        h1 = h1->next;
    }
}

int main(){
    linkedlist l1, l2;
    l1.insert(1, 2);
    l2.insert(2, 2);
    l1.insert(3, 1);
    l1.insert(2, 0);
    l2.insert(4, 1);
    l2.insert(5, 0);
    l1.display();
    l2.display();

    sum(l1, l2);
    l1.display();
}