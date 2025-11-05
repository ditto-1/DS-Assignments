#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int value){
        data = value;
        left = right = nullptr;
    }
};

void preorder(Node *root){
    if (root){
        cout << root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(Node *root){
    if (root){
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void postorder(Node *root){
    if (root){
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}

int main() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout<<"Pre order traversal: ";
    preorder(root);

    cout<<"\nInorder traversal: ";
    inorder(root);

    cout<<"\nPostorder traversal: ";
    postorder(root);

    cout << endl;
}
