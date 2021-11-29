//
// Created by Master on 2021/11/29.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool flagRow(false), flagCol(false);
        for (int i = 0; i < m; ++i) {
            if (!matrix[i][0]){
                flagCol = true;
            }
        }
        for (int j = 0; j < n; ++j) {
            if (!matrix[0][j]){
                flagRow = true;
            }
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (!matrix[i][j]){
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
        if (flagCol){
            for (int i = 0; i < m; ++i) {
                matrix[i][0] = 0;
            }
        }
        if (flagRow){
            for (int j = 0; j < n; ++j) {
                matrix[0][j] = 0;
            }
        }
    }
};

int main(){
    vector<vector<int>> m = {{0,1,2,0},{3,4,0,2},{1,3,1,5}};
    Solution sol;
    sol.setZeroes(m);
    for(auto & i1 : m) {
        for (int &i2 : i1) {
            cout << i2;
        }
        cout << endl;
    }
    return 0;
}
