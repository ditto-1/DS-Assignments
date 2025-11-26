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

        Node* Minimum(Node* r){
            while(r->left){
                r = r->left;
            }
            return r;
        }

        Node* Maximum(Node *r){
            while(r->right){
                r = r->right;
            }
            return r;
        }

        Node* Inorder_Succ(Node *r, Node* x){
            while(r->right){
                return Minimum(r->right);
            }
            Node* succ = nullptr;
            while (true){
                if (x->data < r->data){
                    succ = r;
                    r = r->left;
                }else if(x->data > r->data){
                    r = r->right;
                }else break;
            }
            return succ;
        }

        Node* Inorder_pred(Node *r, Node* x){
            while(r->left){
                return Maximum(r->left);
            }
            Node* pred = nullptr;
            while(true){
                if (x->data > r->data){
                    pred = r;
                    r = r->left;
                }else if(x->data < r->data){
                    r = r->right;
                }else break;
            }
            return pred;
        }
       
};

int main(){
    tree t;
    int values[] = {50, 30, 20, 40, 70, 60, 80};
    for(int v : values){
        t.root = t.insert(t.root, v);
    }
    Node* n = t.root;
    cout << t.Maximum(t.root)->data<<endl;
    cout << t.Minimum(t.root)->data <<endl;
    cout << t.Inorder_Succ(t.root, n)->data<<endl;
    cout << t.Inorder_pred(t.root, n)->data<<endl;
}