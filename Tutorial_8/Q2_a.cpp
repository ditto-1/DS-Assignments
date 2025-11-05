#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

Node* insert(Node* root, int key){
    if (!root){
        return new Node(key);
    }

    if (key < root->data){
        root->left = insert(root->left, key);
    }else if (key > root->data){
        root->right = insert(root->right, key);
    }

    return root;
}

Node* search_rec(Node* root, int key){
    if (!root || root->data == key){
        return root;
    }

    if (key < root->data){
        return search_rec(root->left, key);
    } else{
        return search_rec(root->right, key);
    }
}

Node* search(Node* root, int key) {
    while (root) {
        if (key == root->data)
            return root;
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return nullptr;
}

Node* max(Node* root){
    if (!root){
        return nullptr;
    }

    while(root->right){
        root = root->right;
    }
    return root;
}

Node* min(Node* root){
    if (!root){
        return nullptr;
    }

    while(root->left){
        root = root->left;
    }
    return root;
}

Node* inorder_Succ(Node* root, Node* target){
    if (target->right)
        return max(target->right);

    Node* successor = nullptr;
    while(true){
        if (target->data < root->data){
            successor = root;
            root = root->left;
        } else if (target->data > root->data){
            root = root->right;
        } else {
            break;
        }
    }
    return successor;
}

Node* inorder_pred(Node* root, Node* target){
    if (target->left)
        return min(target->left);

    Node* predecessor = nullptr;
    while(true){
        if (target->data > root->data){
            predecessor = root;
            root = root->right;
        } else if (target->data < root->data){
            root = root->left;
        } else {
            break;
        }
    }
    return predecessor;
}

int main(){
    Node *root = nullptr;

    int value[] = {40, 20, 60, 10, 30, 50, 70};
    for (int val:value){
        root = insert(root, val);
    }

    cout << "Element you want to search: ";
    int key;
    cin >> key;
    cout << "Recursive way searching "<<key<<"\n";
    Node* res1 = search_rec(root, key);
    if (res1){
        cout<<"Found!";
    } else {
        cout << "Not found!";
    }

    cout << "Iterative way searching "<<key<<"\n";
    Node* res2 = search(root, key);
    if (res2){
        cout<<"Found!";
    } else {
        cout << "Not found!";
    }

    cout << "\n\nMinimum element: " << min(root)->data;
    cout << "\nMaximum element: " << max(root)->data;
    Node* target = search(root, key);
    Node* succ = inorder_Succ(root, target);
    Node* pred = inorder_pred(root, target);

    cout << "\n\nIn-order Successor of " << target->data << ": ";
    if (succ)
        cout << succ->data;
    else
        cout << "None";

    cout << "\nIn-order Predecessor of " << target->data << ": ";
    if (pred)
        cout << pred->data;
    else
        cout << "None";

    cout << endl;


}
