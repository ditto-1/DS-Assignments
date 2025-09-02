#include <iostream>
#include <stack>
#include <string>
using namespace std;
int precedence(char op){
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

string postfix(string Q){
    stack<char> ch;
    string P;
    Q+=')';
    ch.push('(');
    for(int i=0; i<Q.length(); i++){
        char c = Q[i];
        if (c == '('){
            ch.push(c);
        } else if (c == '+' || c == '-' || c == '/' || c == '*'){
            while (!ch.empty() && precedence(ch.top()) >= precedence(c)){
                P += ch.top();
                ch.pop();
            }
            ch.push(c);
        } else if (c == ')'){
            while (!ch.empty() && ch.top()!= '('){
                P += ch.top();
                ch.pop();
            }
            if (!ch.empty() && ch.top() == '('){
                ch.pop();
            }
        } else {
           P += c; 
        }
    }
    
    return P;
}

int main() {
    cout << "Enter infix expression: ";
    string infix;
    cin >> infix;
    cout << postfix(infix);

    return 0;
}