#include <iostream>
#include <string>
using namespace std;

class queue {
    int rear, front, capacity;
    char *arr;
    
    public: 
        queue(int x){
            rear = -1;
            front = -1;
            capacity = x;
            arr = new char[capacity];
        }
        
        ~queue(){
            delete[] arr;
        }
        
        bool isFull(){
            return (rear == capacity -1);
        }
        
        bool isEmpty(){
            return (front == -1 || front > rear);
        }
        
        void enqueue(char s){
            if (isFull()){
                return;
            } else if (isEmpty()){
                front = rear = 0;
                arr[rear] = s;
            } else {
                rear++;
                arr[rear] = s;
            }
        }
        
        void dequeue(){
            if (isEmpty()){
                return;
            } else {
                front++;
            }
        }
        
        char peek(){
            if (isEmpty()){
                return '\0';
            } else {
                return arr[front];
            }
        }
};

int main() {
    string str;
    cout << "Enter string: ";
    getline(cin, str);
    int n = str.length();
    queue q(n);
    int freq[256] = {0};
    
    for(int i=0; i<n; i++){
        char ch = str[i];
        freq[ch]++;
        q.enqueue(ch);
        
        while (!q.isEmpty() && freq[q.peek()] > 1){
            q.dequeue();
        }
        
        if (q.isEmpty()){
            cout << "-1 ";
        } else {
            cout << q.peek()<<" ";
        }
    }

    return 0;
}