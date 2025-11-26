#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int a){
            data = a;
            left = nullptr;
            right = nullptr;
        }
};

class tree{
    public:
    Node *root;
        tree(){
            root = nullptr;
        }

        Node* insert(Node* r, int value){
            if (!r) return new Node(value);

            if(value < r->data){
                r->left = insert(r->left, value);
            }else{
                r->right = insert(r->right, value);
            }
            return r;
        }

        bool search_rec(Node* r, int v){
            if (!r) return -1;
            if (r->data == v){
                return true;
            }

            if(v < r->data){
                search_rec(r->left, v);
            }else{
                search_rec(r->right, v);
            }
        }

        bool search(int v){
            Node *curr = root;
            while(curr){
                if (curr->data == v){
                    return true;
                }
                if (v < curr->data){
                    curr = curr->left;
                }else {
                    curr = curr->right;
                }
            }

        }
};

int main(){
    tree t;
    int values[] = {50, 30, 20, 40, 70, 60, 80};
    for(int v : values){
        t.root = t.insert(t.root, v);
    }
}
