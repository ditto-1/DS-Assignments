#include <iostream>
#include <stack>
using namespace std;
int main() {
    int a[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int n = 3;
    bool found = false;
    for(int i=0; i<n; i++){
        int Min_row = a[i][0];
        int col = 0;
        for(int j=1; j<n; j++){
            if (a[i][j] < Min_row){
                Min_row = a[i][j];
                col = j;
            }
        }
        
        bool saddle = true;
        for(int k=0; k<n; k++){
            if (a[k][col] > Min_row){
                saddle = false;
                break;
            }
        }
        
        if (saddle){
            cout << "Saddle point: "<<Min_row<<" at ("<<i<<", "<<col<<")";
            found = true;
        }
    }
    
    if (!found){
        cout << "No saddle point";
    }

    return 0;
}