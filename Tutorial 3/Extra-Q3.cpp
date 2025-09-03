#include <iostream>
#include <stack>
using namespace std;

int* NGE(int* A, int n, int* len1){
    *len1 = n;
    int *res = (int*)malloc(n*sizeof(int));
    stack<int> s;
    
    for(int i=n-1; i>=0; i--){
        while(!s.empty() && s.top() <= A[i]){
            s.pop();
        }
        if (s.empty()){
            res[i] = -1;
        } else{
            res[i] = s.top();
        }
        
        s.push(A[i]);
    }
    
    return res;
}
int main() {
    int arr[] = {4, 5, 2, 25};
    int n = sizeof(arr) / sizeof(arr[0]);
    int len1;

    int* result = NGE(arr, n, &len1);

    cout << "Next Greater Elements:\n";
    for (int i = 0; i < len1; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    free(result);
    return 0;
}