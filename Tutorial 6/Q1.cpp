#include <iostream>
using namespace std;


struct DNode {
    int data;
    DNode* prev;
    DNode* next;
};

class DoublyLinkedList {
private:
    DNode* head;

public:
    DoublyLinkedList() { head = nullptr; }

    void insertAtBeginning(int value) {
        DNode* newNode = new DNode{value, nullptr, head};
        if (head != nullptr)
            head->prev = newNode;
        head = newNode;
        cout << value << " inserted at beginning.\n";
    }

    void insertAtEnd(int value) {
        DNode* newNode = new DNode{value, nullptr, nullptr};
        if (head == nullptr) {
            head = newNode;
            cout << value << " inserted as first node.\n";
            return;
        }

        DNode* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
        cout << value << " inserted at end.\n";
    }

    void insertBefore(int target, int value) {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        DNode* temp = head;
        while (temp && temp->data != target)
            temp = temp->next;
        if (!temp) {
            cout << "Node " << target << " not found.\n";
            return;
        }
        DNode* newNode = new DNode{value, temp->prev, temp};
        if (temp->prev)
            temp->prev->next = newNode;
        else
            head = newNode;
        temp->prev = newNode;
        cout << value << " inserted before " << target << ".\n";
    }

    void insertAfter(int target, int value) {
        DNode* temp = head;
        while (temp && temp->data != target)
            temp = temp->next;
        if (!temp) {
            cout << "Node " << target << " not found.\n";
            return;
        }
        DNode* newNode = new DNode{value, temp, temp->next};
        if (temp->next)
            temp->next->prev = newNode;
        temp->next = newNode;
        cout << value << " inserted after " << target << ".\n";
    }

 
    void deleteNode(int value) {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        DNode* temp = head;
        while (temp && temp->data != value)
            temp = temp->next;
        if (!temp) {
            cout << "Node " << value << " not found.\n";
            return;
        }
        if (temp->prev)
            temp->prev->next = temp->next;
        else
            head = temp->next;
        if (temp->next)
            temp->next->prev = temp->prev;
        delete temp;
        cout << "Node " << value << " deleted.\n";
    }

   
    void search(int value) {
        DNode* temp = head;
        int pos = 1;
        while (temp) {
            if (temp->data == value) {
                cout << "Node " << value << " found at position " << pos << ".\n";
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Node " << value << " not found.\n";
    }

    void display() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        cout << "Doubly Linked List: ";
        DNode* temp = head;
        while (temp) {
            cout << temp->data;
            if (temp->next)
                cout << " <-> ";
            temp = temp->next;
        }
        cout << endl;
    }
};


struct CNode {
    int data;
    CNode* next;
};

class CircularLinkedList {
private:
    CNode* head;

public:
    CircularLinkedList() { head = nullptr; }

    void insertAtBeginning(int value) {
        CNode* newNode = new CNode{value, nullptr};
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
        } else {
            CNode* temp = head;
            while (temp->next != head)
                temp = temp->next;
            newNode->next = head;
            temp->next = newNode;
            head = newNode;
        }
        cout << value << " inserted at beginning.\n";
    }

    void insertAtEnd(int value) {
        CNode* newNode = new CNode{value, nullptr};
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
            cout << value << " inserted as first node.\n";
            return;
        }
        CNode* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
        cout << value << " inserted at end.\n";
    }

    void insertAfter(int target, int value) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        CNode* temp = head;
        do {
            if (temp->data == target) {
                CNode* newNode = new CNode{value, temp->next};
                temp->next = newNode;
                cout << value << " inserted after " << target << ".\n";
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Node " << target << " not found.\n";
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
        CNode* prev = head;
        CNode* curr = head->next;
        while (curr != head && curr->data != target) {
            prev = curr;
            curr = curr->next;
        }
        if (curr == head) {
            cout << "Node " << target << " not found.\n";
            return;
        }
        CNode* newNode = new CNode{value, curr};
        prev->next = newNode;
        cout << value << " inserted before " << target << ".\n";
    }


    void deleteNode(int value) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        CNode* curr = head;
        CNode* prev = nullptr;

        do {
            if (curr->data == value) {
                if (curr == head && curr->next == head) {
                    delete curr;
                    head = nullptr;
                    cout << "Deleted last remaining node " << value << ".\n";
                    return;
                }
                if (curr == head) {
                    CNode* temp = head;
                    while (temp->next != head)
                        temp = temp->next;
                    temp->next = head->next;
                    head = head->next;
                    delete curr;
                    cout << "Deleted head node " << value << ".\n";
                    return;
                } else {
                    prev->next = curr->next;
                    delete curr;
                    cout << "Deleted node " << value << ".\n";
                    return;
                }
            }
            prev = curr;
            curr = curr->next;
        } while (curr != head);

        cout << "Node " << value << " not found.\n";
    }


    void search(int value) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        CNode* temp = head;
        int pos = 1;
        do {
            if (temp->data == value) {
                cout << "Node " << value << " found at position " << pos << ".\n";
                return;
            }
            temp = temp->next;
            pos++;
        } while (temp != head);
        cout << "Node " << value << " not found.\n";
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        CNode* temp = head;
        cout << "Circular Linked List: ";
        do {
            cout << temp->data;
            if (temp->next != head)
                cout << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << " (Back to head)\n";
    }
};


int main() {
    DoublyLinkedList dll;
    CircularLinkedList cll;
    int listType, choice, value, target;

    cout << "Choose Linked List Type:\n1. Doubly Linked List\n2. Circular Linked List\nEnter choice: ";
    cin >> listType;

    while (true) {
        cout << "\n--- MENU ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert Before a Node\n";
        cout << "4. Insert After a Node\n";
        cout << "5. Delete a Node\n";
        cout << "6. Search a Node\n";
        cout << "7. Display\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 0) break;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                (listType == 1) ? dll.insertAtBeginning(value) : cll.insertAtBeginning(value);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;
                (listType == 1) ? dll.insertAtEnd(value) : cll.insertAtEnd(value);
                break;

            case 3:
                cout << "Enter target value: ";
                cin >> target;
                cout << "Enter value to insert: ";
                cin >> value;
                (listType == 1) ? dll.insertBefore(target, value) : cll.insertBefore(target, value);
                break;

            case 4:
                cout << "Enter target value: ";
                cin >> target;
                cout << "Enter value to insert: ";
                cin >> value;
                (listType == 1) ? dll.insertAfter(target, value) : cll.insertAfter(target, value);
                break;

            case 5:
                cout << "Enter value to delete: ";
                cin >> value;
                (listType == 1) ? dll.deleteNode(value) : cll.deleteNode(value);
                break;

            case 6:
                cout << "Enter value to search: ";
                cin >> value;
                (listType == 1) ? dll.search(value) : cll.search(value);
                break;

            case 7:
                (listType == 1) ? dll.display() : cll.display();
                break;

            default:
                cout << "Invalid choice!\n";
        }
    }

    cout << "Exiting program...\n";
    return 0;
}
