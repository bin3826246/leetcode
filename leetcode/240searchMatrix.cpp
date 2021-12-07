//
// Created by Master on 2021/12/7.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;
        int m = matrix.size();
        int n = matrix[0].size();
        int i(0), j(n - 1);
        while (i <= m - 1 && j >= 0){
            if(matrix[i][j] == target){
                return true;
            }
            if (matrix[i][j] > target){
                j--;
            } else{
                i++;
            }
        }

        return false;
    }
};

int main(){
    vector<vector<int>> matrix = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24},{18, 21, 23, 26, 30}};
    int target = 20;
    bool a;
    Solution sol;
    a = sol.searchMatrix(matrix, target);
    cout<<a;
    return 0;
}
