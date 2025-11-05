#include <iostream>
using namespace std;

class queue{
  int front, rear, capacity;
  int *arr;
  
  public:
    queue(int cap){
        capacity = cap;
        arr = new int[capacity];
        front = -1;
        rear = -1;
    }
     
    ~queue(){
        delete[] arr;
    }
    
    bool isEmpty(){
        return (front == rear && rear == -1);
    }
    
    bool isFull(){
        return (front == (rear+1)%capacity);
    }
    
    void enqueue(int num){
        if (isFull()){
            cout << "Overflow"<<endl;
        }
        else {
            rear = (rear+1)%capacity;
            arr[rear] = num;
            if (front == -1){
                front = 0;
            }
            cout << "Added "<<num<<endl;
        }
    }
    
    void dequeue(){
        int item;
        if (isEmpty()){
            cout << "Underflow";
        } else {
            item = arr[front];
            if (front == rear){
                front = rear = -1;
            } else {
                front = (front + 1)%capacity;
            }
            cout << "Removed: "<<item<<endl;
        }
    }
    
    void display(){
        if (isEmpty()){
            cout << "List Empty";
        } else {
            for(int i=front; i<=rear; i++){
                cout << arr[i]<<"\n";
            }
            cout << endl;
        }
        
    }
    
    void peek(){
        int item;
        if (isEmpty()){
            cout << "Queue Empty!"<<endl;
        } else {
            item = arr[front];
            cout << item << " is at the front"<<endl;
        }
    }
};

int main() {
    cout << "Enter capacity: ";
    int c;
    cin >> c;
    queue q(c);
    int value;
    while (true){
        cout << "\n--- Queue Operations Menu ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Check if Empty\n";
        cout << "6. Check if Full\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        
        switch (choice){
            case 1:
                cout << "Enter value: ";
                cin >> value;
                q.enqueue(value);
                break;
            
            case 2:
                q.dequeue();
                break;
             
            case 3:
                q.peek();
                break;
            
            case 4:
                q.display();
                break;
            
            case 5:
                if (q.isEmpty()){
                    cout << "Empty list";
                } else {
                    cout << "Not empty";
                }
                break;
                
            case 6:
                if (q.isFull()){
                    cout << "List is full";
                } else {
                    cout << "List is not full";
                }
                break;
                
            case 7:
                cout << "Exiting program";
                return 0;
                
            default:
                cout <<"Invalid choice"<<endl;
        }
    }
}