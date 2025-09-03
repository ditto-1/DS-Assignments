#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int len = temperatures.size();
        vector<int> res(len, 0);
        stack<int> s;
        for(int i=len-1; i>=0; i--){
            while(!s.empty() && temperatures[s.top()] <= temperatures[i]){
                s.pop();
            }
            if (s.empty()){
                res[i] = 0;
            } else {
                res[i] = s.top()-i;
            }
            s.push(i);
        }
        return res;
    }
};

int main() {
    vector<int> temps = {30, 40, 50, 60};
    Solution sol;
    vector<int> ans = sol.dailyTemperatures(temps);
    cout<<"Result: ";
    for(int x : ans){
        cout << x << " ";
    }
    cout << endl;

    return 0;
}