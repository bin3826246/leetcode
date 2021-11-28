//
// Created by Master on 2021/11/27.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<vector<int>> result(r);
        int m = mat.size();
        int n = mat[0].size();
        if (m * n != r * c){
            return mat;
        }
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                result[i].push_back(mat[(i * c + j) / n][(i * c + j) % n]);
            }
        }
        return result;
    }
};

int main(){
    vector<vector<int>> mat = {{1,2}, {3,4}};
    int r = 1;
    int c = 4;
    vector<vector<int>> m;
    Solution sol;
    m = sol.matrixReshape(mat, r, c);
    for(auto i1 = m.begin(); i1 != m.end(); i1++){
        for(auto i2 = (*i1).begin(); i2 != (*i1).end(); i2++){
            cout<<*i2;
        }
    }
    return 0;
}
