#include <iostream>
#include <string>
using namespace std;
#define MAXLEN 100
class stack{
    int element[MAXLEN];
    int top;
    
    public:
    stack(){
        top = -1;
    }
    
    bool isEmpty(){
        return (top == -1);
    }
    
    bool isFull(){
        return (top == MAXLEN-1);
    }
    
    void push(char x){
        if (isFull()){
            cout << "Stack full\n";
            return;
        } 
        top++;
        element[top] = x;
    }
    
    char pop(){
        if (isEmpty()){
            cout << "Stack empty"<<endl;
            return '\0';
        }
        char x = element[top];
        top--;
        return x;
    }
    
    char peek(){
        return element[top];
    }
};


int main() {
    string exp = "{()}";
    stack s;
    for(int i=0; i<exp.length(); i++){
        //char c = exp[i];
        if (exp[i] == '{' || exp[i] == '(' || exp[i] == '['){
            s.push(exp[i]);
        }
        while(!s.isEmpty()){
            if ((exp[i] == '}' && s.peek() == '{') ||
            (exp[i] == ')' && s.peek() == '(') ||
            (exp[i] == ']' && s.peek() == '[')){
            s.pop();
            }
        }
        
    }

    cout << s.isEmpty();
}