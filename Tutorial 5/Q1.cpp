#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};


class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() {
        head = nullptr;
    }


    void insertAtBeginning(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = head;
        head = newNode;
        cout << value << " inserted at the beginning.\n";
    }


    void insertAtEnd(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = newNode;
        }
        cout << value << " inserted at the end.\n";
    }

 
    void insertBefore(int target, int value) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        if (head->data == target) {
            insertAtBeginning(value);
            return;
        }

        Node* prev = nullptr;
        Node* curr = head;

        while (curr != nullptr && curr->data != target) {
            prev = curr;
            curr = curr->next;
        }

        if (curr == nullptr) {
            cout << "Node " << target << " not found.\n";
            return;
        }

        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = curr;
        prev->next = newNode;
        cout << value << " inserted before " << target << ".\n";
    }


    void insertAfter(int target, int value) {
        Node* temp = head;
        while (temp != nullptr && temp->data != target)
            temp = temp->next;
        if (temp == nullptr) {
            cout << "Node " << target << " not found.\n";
            return;
        }

        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = temp->next;
        temp->next = newNode;
        cout << value << " inserted after " << target << ".\n";
    }


    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        head = head->next;
        cout << "Deleted " << temp->data << " from beginning.\n";
        delete temp;
    }

    void deleteFromEnd() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        if (head->next == nullptr) {
            cout << "Deleted " << head->data << " from end.\n";
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next->next != nullptr)
            temp = temp->next;

        cout << "Deleted " << temp->next->data << " from end.\n";
        delete temp->next;
        temp->next = nullptr;
    }

    void deleteNode(int value) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            cout << "Deleted node " << value << ".\n";
            delete temp;
            return;
        }

        Node* prev = nullptr;
        Node* curr = head;

        while (curr != nullptr && curr->data != value) {
            prev = curr;
            curr = curr->next;
        }

        if (curr == nullptr) {
            cout << "Node " << value << " not found.\n";
            return;
        }

        prev->next = curr->next;
        cout << "Deleted node " << value << ".\n";
        delete curr;
    }

    void searchNode(int value) {
        Node* temp = head;
        int pos = 1;

        while (temp != nullptr) {
            if (temp->data == value) {
                cout << "Node " << value << " found at position " << pos << ".\n";
                return;
            }
            temp = temp->next;
            pos++;
        }

        cout << "Node " << value << " not found in the list.\n";
    }


    void display() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        cout << "Linked List: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    SinglyLinkedList list;
    int choice, value, target;

    while (true) {
        cout << "\n--- Singly Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert Before a Node\n";
        cout << "4. Insert After a Node\n";
        cout << "5. Delete from Beginning\n";
        cout << "6. Delete from End\n";
        cout << "7. Delete a Specific Node\n";
        cout << "8. Search for a Node\n";
        cout << "9. Display List\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                list.insertAtBeginning(value);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;
                list.insertAtEnd(value);
                break;

            case 3:
                cout << "Enter target node value: ";
                cin >> target;
                cout << "Enter value to insert: ";
                cin >> value;
                list.insertBefore(target, value);
                break;

            case 4:
                cout << "Enter target node value: ";
                cin >> target;
                cout << "Enter value to insert: ";
                cin >> value;
                list.insertAfter(target, value);
                break;

            case 5:
                list.deleteFromBeginning();
                break;

            case 6:
                list.deleteFromEnd();
                break;

            case 7:
                cout << "Enter node value to delete: ";
                cin >> value;
                list.deleteNode(value);
                break;

            case 8:
                cout << "Enter value to search: ";
                cin >> value;
                list.searchNode(value);
                break;

            case 9:
                list.display();
                break;

            case 0:
                cout << "Exiting program...\n";
                return 0;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}
