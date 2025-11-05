#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

Node* insert(Node* root, int key) {
    if (root == nullptr)
        return new Node(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    else
        cout << "Duplicate value " << key << " not allowed.\n";

    return root;
}

Node* min(Node* root) {
    while (root && root->left != nullptr)
        root = root->left;
    return root;
}

Node *del(Node* root, int key){
    if (!root){
        return root;
    }

    if (key < root->data){
        root->left = del(root->left, key);
    }else if (key > root->data){
        root->right = del(root->right, key);
    }else{
        if (!root->left){
            Node *temp = root->right;
            delete root;
            return temp;
        }else if (!root->right){
            Node *temp = root->left;
            delete root;
            return temp;
        }

        Node *temp = min(root->right);
        root->data = temp->data;
        root->right = del(root->right, temp->data);
    }
    return root;
}

void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main(){
    Node* root = nullptr;

    int elements[] = {20, 10, 30, 5, 15, 25, 35};
    for (int val : elements)
        root = insert(root, val);

    cout << "In-order traversal of BST: ";
    inorder(root);
    cout << endl;

    cout << "\nDeleting node 10...\n";
    root = del(root, 10);

    cout << "In-order traversal after deletion: ";
    inorder(root);
    cout << endl;
}