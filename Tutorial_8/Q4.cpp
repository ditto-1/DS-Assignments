#include <iostream>
#include <climits>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int v){
        data = v;
        left = right = nullptr;
    }
};

class BST{
    public:
        Node* root;
        BST(){
            root = nullptr;
        }

        Node* Insert(Node *r, int v){
            if(!r) return new Node(v);

            if (v < r->data){
                r->left = Insert(r->left, v);
            }else{
                r->right = Insert(r->right, v);
            }

            return r;
        }

        bool isBSTUtil(Node *r, int min, int max){
            if (!r) return true;
            if (r->data > max || r->data < min){
                return false;
            }

            return isBSTUtil(r->left, min, r->data-1) &&
                    isBSTUtil(r->right, r->data+1, max);
        }

        bool isBST(Node *r){
            return (isBSTUtil(r, INT_MIN, INT_MAX));
        }
};

int main(){
    BST t;

    // Create tree
    int values[] = {50, 30, 20, 40, 70, 60, 80};
    for (int v : values)
        t.root = t.Insert(t.root, v);

    if (t.isBST(t.root))
        cout << "The tree is a BST" << endl;
    else
        cout << "The tree is NOT a BST" << endl;

    return 0;
}