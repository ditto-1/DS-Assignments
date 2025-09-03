#include <iostream>
#include <cstdlib>
#include <stack>
using namespace std;

int* prevSmaller(int* A, int n1, int *len1) {
    *len1 = n1;
    int *res = (int*)malloc((*len1) * sizeof(int));
    stack<int>s;
    
    for(int i=0; i<n1; i++){
        
        while(!s.empty() && s.top() >= A[i]){
            s.pop();
        }
        
        if(s.empty()){
            res[i] = -1;
        } else {
            res[i] = s.top();
        }
        
        s.push(A[i]);
    }
    
    return res;
}
int main() {
    int A[] = {4, 5, 2, 10, 8};
    int n1 = sizeof(A)/sizeof(A[0]);
    
    int len1;
    int *result = prevSmaller(A, n1, &len1);
    cout<<"Input array: ";
    for(int i=0; i<n1; i++){
        cout << A[i] << " ";
    }
    cout<<endl;
    
    cout << "Previous smalled elements: ";
    for(int i=0; i<len1; i++){
        cout << result[i] << " ";
    }

    return 0;
}