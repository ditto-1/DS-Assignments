// Online C++ compiler to run C++ program online
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
//  1, 0             // 0, 1
int count(queue<int> q, stack<int> s){
    int count = 0;
    while( !q.empty() && count <= s.size()){
        if (s.top() == q.front()){
            s.pop();
            q.pop();
            count = 0;
        }else{
            q.push(q.front());
            q.pop();
            count++;
        }
    }
    return count;
}
int main() {
    queue<int> q;
    q.push(1);
    q.push(1);
    q.push(1);
    q.push(0);
    q.push(0);
    q.push(1);
    
    stack<int> s;
    s.push(1);
    s.push(0);
    s.push(0);
    s.push(0);
    s.push(1);
    s.push(1);
    
    cout << count(q, s);

    return 0;
}