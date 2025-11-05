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
        return (front == -1 || front>rear);
    }
    
    bool isFull(){
        return (rear == capacity-1);
    }
    
    void enqueue(int num){
        if (isFull()){
            cout << "Overflow"<<endl;
        }
        else if (isEmpty()){
            front = rear = 0;
            arr[rear] = num;
        } else {
            ++rear;
            arr[rear] = num;
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
};

int main() {
    int c = 6;
    queue q(c);
    int array[c] = {4, 7, 11, 20, 5, 9};
    
    for (int i=0; i<c/2; i++){
        q.enqueue(array[i]);
        q.enqueue(array[c/2 + i]);
    }
    
    q.display();
}