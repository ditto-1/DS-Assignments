#include <iostream>
#include <stack>
#include <string>
using namespace std;
string reverseString(string& s){
    stack<char> st;
    
    for(int i=0; i<s.length(); i++){
        st.push(s[i]);
    }
    
    string reversed;
    while(!st.empty()){
        reversed += st.top();
        st.pop();
    }
    
    return reversed;
}
int main() {
    string str;
    cout << "Enter string: ";
    cin >> str;
    string output = reverseString(str);
    cout << output << endl;

    return 0;
}