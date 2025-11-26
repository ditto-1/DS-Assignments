#include <iostream>
using namespace std;
#define SIZE 100
class queue{
  int front, rear;
  int arr[SIZE];
  public:
    queue(){
        front = rear = -1;
    }
    void push(int n){
        //q = 2, 3 - 2, 3, 1
        if (rear == SIZE -1) return;
        arr[++rear] = n;
        if (front == -1) front = 0;
        int s = rear - front;
        for(int i=0; i<s; i++){
            int temp = arr[front++];
            arr[++rear] = temp;
        }
    }
    
    int pop(){
        if (front == -1 || front > rear) return -1;
        return arr[front++];
    }
};

int main() {
    queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    cout << q.pop()<<endl;
    cout << q.pop() <<endl;

    return 0;
}