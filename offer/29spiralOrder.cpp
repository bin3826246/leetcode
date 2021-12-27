//
// Created by Master on 2021/12/27.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty()) return vector<int> {};
        int m = matrix.size();
        int n = matrix[0].size();
        int rLow(0), rHigh(m - 1);
        int cLow(0), cHigh(n - 1);
        vector<int> res;

        while(res.size() < m * n){
            for (int i = cLow; i <= cHigh; ++i) {
                res.push_back(matrix[rLow][i]);
            }
            if(++rLow > rHigh) break;
            for (int i = rLow; i <= rHigh; ++i) {
                res.push_back(matrix[i][cHigh]);
            }
            if(--cHigh < cLow) break;
            for (int i = cHigh; i >= cLow; --i) {
                res.push_back(matrix[rHigh][i]);
            }
            if(--rHigh < rLow) break;
            for (int i = rHigh; i >= rLow; --i) {
                res.push_back(matrix[i][cLow]);
            }
            if(++cLow > cHigh) break;
        }
        return res;
    }
};

int main(){
    vector<vector<int>> val = {{1,2}, {3,4}};
    Solution sol;
    vector<int> res = sol.spiralOrder(val);
    for(int n : res){
        cout<<n<<',';
    }
    return 0;
}