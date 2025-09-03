#include <iostream>
using namespace std;

int* spiralOrder(const int** A, int n11, int n12, int *len1) {
    *len1 = n11*n12;
    int *res;
    res = (int *) malloc((*len1) * sizeof(int));
    int index = 0;
    int top = 0, bottom = n11-1, left = 0, right = n12-1;
    
    while(top <= bottom && left <= right){
       for(int i=left; i<=right; i++){
           res[index++] = A[top][i];
       }
       top++;
       
       for(int i=top; i<=bottom; i++){
           res[index++] = A[i][right];
       }
       right--;
       
       if (top <= bottom){
           for(int i=right; i>=left; i--){
               res[index++] = A[bottom][i];
           }
           bottom--;
       }
       
       if (left <= right){
           for(int i=bottom; i>= top; i--){
               res[index++] = A[i][left];
           }
           left++;
       }
    }
    
    return res;
}

int main() {
    int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};

    const int* A[3];
    for (int i = 0; i < 3; i++) {
        A[i] = arr[i];
    }
    
    int len;
    int *result = spiralOrder(A, 3, 3, &len);
    cout << "Spiral order: ";
    for (int i = 0; i < len; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    
    free(result);

    return 0;
}