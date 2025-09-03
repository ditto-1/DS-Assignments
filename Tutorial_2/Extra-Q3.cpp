#include <iostream>
#include <cstdlib>
using namespace std;

int ** generateMatrix(int A, int *len1, int *len2) {
    *len1 = A;
    *len2 = A;
    
    int top = 0, bottom = A-1, left = 0, right = A-1;
    int n = 1;
    int **arr = (int**)malloc(A * sizeof(int*));
    
    for(int i=0; i<A; i++){
        arr[i] = (int*)malloc(A *sizeof(int));
    }
    
    while(top <= bottom && left<=right){
        for(int i=left; i<=right; i++){
            arr[top][i] = n++;
        }
        top++;
        
        for(int i=top; i<=bottom; i++){
            arr[i][right] = n++;
        }
        right--;
        
        if (top <= bottom){
            for(int i=right; i>=left; i--){
                arr[bottom][i] = n++;
            }
            bottom--;
        }
        
        if (left <= right){
            for(int i=bottom; i>=top; i--){
                arr[i][left] = n++;
            }
            left++;
        }
    }
    
    return arr;
}

int main() {
    int A;
    cout << "Size of matrix: ";
    cin >> A;
    int len1, len2;
    int **matrix = generateMatrix(A, &len1, &len2);
    
    cout << "Spiral Matrix of "<<A<<"x"<<A<<" in:\n";
    for(int i=0; i<len1; i++){
        for(int j=0; j<len2; j++){
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    free(matrix);

    return 0;
}