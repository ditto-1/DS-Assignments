#include <iostream>
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

        bool search(int v){
            Node *curr = root;
            while(curr){
                if (curr->data == v){
                    return true;
                }

                if (v < curr->data){
                    curr = curr->left;
                }else{
                    curr = curr->right;
                }
            }
            return false;
        }

        Node* search_rec(Node* r, int v){
            if(!r) return nullptr;
            if (r->data == v){
                return r;
            }
            if (v < r->data){
                search_rec(r->left, v);
            }else{
                search_rec(r->right, v);
            }
            return r;
        }

        Node* insert(Node *r, int v){
            if (!r) return new Node(v);
            if(search(v)){
                return nullptr;
            }

            if (v < r->data){
                r->left = insert(r->left, v);
            }else {
                r->right = insert(r->right, v);
            }

            return r;
        }

        Node* Minimum(Node* r){
            while(r->left){
                r = r->left;
            }
            return r;
        }

        Node* del(Node *r, int v){
            if (!r) return r;
            if (v < r->data){
                r->left = del(r->left, v);
            }else if(v > r->data){
                r->right = del(r->right, v);
            }else{
                if (!r->left){
                    Node *temp = r->right;
                    delete r;
                    return temp;
                }else if(!r->right){
                    Node *temp = r->left;
                    delete r;
                    return temp;
                }
                Node *temp = Minimum(r->right);
                r->data = temp->data;
                r->right = del(r->right, temp->data);
            }
        }

        int MaxDepth(Node* r){
            if (!r) return 0;

            int leftDepth = MaxDepth(r->left);
            int rightDepth = MaxDepth(r->right);

            return 1+max(leftDepth, rightDepth);
        }

        int MinDepth(Node *r){
            if (!r) return 0;
            
            if(!r->left && !r->right){
                return 1;
            }

            if(!r->left){
                return 1+MinDepth(r->right);
            }

            if(!r->right){
                return 1+MinDepth(r->left);
            }

            return 1+min(MinDepth(r->left), MinDepth(r->right));
        }
};

int main(){

}