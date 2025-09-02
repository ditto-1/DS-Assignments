#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool balanced(string s){
    stack<char> ch;
    for(int i=0; i<s.length(); i++){
        char c = s[i];
        if (c == '{' || c == '[' || c == '('){
            ch.push(c);
        }
        else if (c == '}' || c == ']' || c == ')'){
            if (ch.empty()){
                return false;
            }
            
            char top = ch.top();
            if ((c == '}' && top!= '{') ||
                (c == ']' && top!='[')  ||
                (c == ')' && top!= '(')) {
                    return false;
                }
                
                ch.pop();
        }
    }
    
    return ch.empty();
}

int main() {
    cout << "Enter an expression: ";
    string string;
    getline(cin, string);
    if (balanced(string)){
        cout << "Balanced";
    } else {
        cout << "Not balanced";
    }
    return 0;
}