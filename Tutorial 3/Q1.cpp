#include <iostream>
using namespace std;
class stack{
    static const int MAXLEN = 5;
    int element[MAXLEN];
    int top;
    
    public:
    stack(){
        top = -1;
    };
    
    bool isEmpty(){
        return (top == -1);
    }
    
    bool isFull(){
        return (top == MAXLEN-1);
    }
    
    void push(int x){
        if (isFull()){
            cout << "Stack full\n";
            return;
        } 
        top++;
        element[top] = x;
        cout << "Pushed "<<x<<" onto stack";
    }
    
    void pop(){
        if (isEmpty()){
            cout << "Stack empty"<<endl;
            return;
        }
        int x = element[top];
        top--;
        cout << "Popped "<<x<<" from the stack";
    }
    
    int peek(){
        if (isEmpty()){
            cout << "stack empty"<<endl;
            return -1;
        }
        int x = element[top];
        return x;
    }
    
    void display(){
        if (isEmpty()){
            cout << "Empty stack"<<endl;
            return;
        }
        cout<<"Stack: "<<endl;
        for(int i=top; i>=0; i--){
            cout << element[i] <<" ";
        }
        cout <<endl;
    }
};

int welcome(){
    cout << "\n----stack menu----\n";
    cout << "1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n";
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
    return choice;
}
int main() {
    stack s;
    while(1){
        int choice = welcome();
        int el;
        switch(choice){
            case 1:
                cout << "Enter element to push: ";
                cin >> el;
                s.push(el);
                break;
            
            case 2:
                s.pop();
                break;
            
            case 3:
                el = s.peek();
                if (el != -1) 
                    cout << el << " is the top element" << endl;
                break;
            
            case 4:
                s.display();
                break;
            
            case 5:
                cout << "Exiting the program...";
                return 0;
            
            default:
                cout << "Invalid. Try again.";
                break;
        }
    }

    return 0;
}