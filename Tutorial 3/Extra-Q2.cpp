// Online C++ compiler to run C++ program online
#include <iostream>
#include <stack>
using namespace std;

class Stacks{
    stack<int> s;
    stack<int> min;
    
    public:
        void push(int x){
            s.push(x);
            
            if (min.empty()||min.top()>=x){
                min.push(x);
            } else {
                min.push(min.top());
            }
        }
        
        int pop(){
            if (s.empty()){
                return -1;
            }
            
            int popped = s.top();
            s.pop();
            if (popped == min.top()){
                min.pop();
            }
            
            return popped;
        }
        
        int peek(){
            if (s.empty()){
                return -1;
            }
            return s.top();
        }
        
        bool isEmpty(){
            return s.empty();
        }
        
        int getMin(){
            if (min.empty()){
                return -1;
            }
            return min.top();
        }
};

int main() {
    Stacks stack;
    
    stack.push(18);
    stack.push(19);
    stack.push(29);
    stack.push(15);
    stack.push(16);

    cout << stack.getMin() << endl;

    return 0;
}