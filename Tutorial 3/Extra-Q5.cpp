#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> canSort(vector<int>& A){
    int N = A.size();
    vector<int> B;
    stack<int> s;
    int n = 1;
    for(int i=0; i<N; i++){
        while(!s.empty() && s.top() == n){
            s.pop();
            n++;
        }
        
        if (A[i] == n){
            n++;
        } else if (!s.empty() && A[i] > s.top()){
            return false;
        } else {
            s.push(A[i]);
        }
    }
    return true;
}

int main() {
	// your code goes here
	vector<int> A = {3, 1, 2};
	
	if (canSort(A)){
	    cout << "YES\n";
	} else {
	    cout << "No\n";
	}

}