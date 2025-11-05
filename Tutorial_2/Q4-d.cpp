#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    cout << "Enter string: ";
    string str;
    getline(cin, str);
    
    //sort(str.begin(), str.end());
    for(int i=1; i<str.length(); i++){
        bool flag = true;
        for(int j=0; j<str.length()-i; j++){
            if (str[j]>str[j+1]){
                flag = false;
                char temp;
                temp = str[j];
                str[j]=str[j+1];
                str[j+1] = temp;
            }
        }
        if (flag == true)break;
    }

    cout <<"Sorted: ";
    cout << str << endl;
}