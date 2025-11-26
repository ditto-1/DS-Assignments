#include <iostream>
#include <algorithm>
using namespace std;

#define size 100

class twoqueue{
    int front1, rear1, front2, rear2;
    int q1[size], q2[size];
    public:
        twoqueue(){
            front1 = rear1 = front2 = rear2 = -1;
        }

        void push(int n){
            //q1 = 2, 3, 4
            //q2 = 
            if (rear2 == size-1) return;
            q2[++rear2] = n;
            if (front2 == -1) front2 = 0;
            int i = front1;
            while(i != -1 && i <= rear1){
                q2[++rear2] = q1[i++];
            }

            swap(front1, front2);
            swap(rear1, rear2);
            front2 = rear2 = -1;
        }

        int pop(){
            if (front1 == -1 || front1 > rear1){
                return -1;
            }
            return q1[front1++];
        }
};

int main(){
    twoqueue q;
    q.push(10);
    q.push(20);
    q.push(30);
    cout<< q.pop() << "\n";
    cout << q.pop();
}