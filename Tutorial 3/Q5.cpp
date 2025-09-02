#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

double result(char c, int f, int s){
    if (c == '+'){
        return f+s;
    } else if ( c == '-'){
        return f-s;
    } else if (c == '*'){
        return f*s;
    } else if (c == '/'){
        return f/s;
    }
    return 0;
}

double Eval(string Q){
    stack<double> P;
    for(int i=0; i<(int)Q.length(); i++){
        char c = Q[i];
        if (isdigit(c)){
            P.push(c - '0');
        } else if (c == '+' || c == '-' || c == '*' || c == '/'){
            if (P.size() < 2){
                cout << "Error. Not enough operands";
            }
            double second = P.top();
            P.pop();
            double first = P.top();
            P.pop();
            
            double res = result(c, first, second);
            P.push(res);
        } else {
            cout << "Error: Invalid character";
        }
    }
    return P.top();
}

int main() {
    string expression;
    cout << "Enter exp: ";
    cin >> expression;
    cout << Eval(expression);
    return 0;
}