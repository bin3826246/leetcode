//
// Created by Master on 2021/11/28.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result(numRows);
        result[0].push_back(1);
        for (int i = 1; i < numRows; ++i) {
            result[i].push_back(1);
            for (int j = 1; j < i; ++j) {
                result[i].push_back(result[i - 1][j - 1] + result[i - 1][j]);
            }
            result[i].push_back(1);
        }
        return result;
    }
};

int main(){
    int numRows = 5;
    vector<vector<int>> m;
    Solution sol;
    m = sol.generate(numRows);
    for(auto & i1 : m){
        for(int & i2 : i1){
            cout<<i2;
        }
        cout<<endl;
    }
    return 0;
}