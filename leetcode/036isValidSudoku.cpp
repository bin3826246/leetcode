//
// Created by Master on 2021/11/28.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unsigned int> rowMask(9, 0);
        vector<unsigned int> colMask(9, 0);
        vector<unsigned int> boxMask(9, 0);
        for(int i = 0; i < board.size(); i++){
            for (int j = 0; j < board[i].size(); ++j) {
                if (board[i][j] != '.'){
                    unsigned int mask = 1u << (unsigned int)(board[i][j] - '0');
                    if ((rowMask[i] & mask) || (colMask[j] & mask) || (boxMask[(i / 3) * 3 + j / 3] & mask)){
                        return false;
                    }
                    rowMask[i] |= mask;
                    colMask[j] |= mask;
                    boxMask[(i / 3) * 3 + j / 3] |= mask;
                }
            }
        }
        return true;
    }
};

int main(){
    bool a;
    vector<vector<char>> m = {{'5','3','.','.','7','.','.','.','.'}
                            ,{'6','.','.','1','9','5','.','.','.'}
                            ,{'.','9','8','.','.','.','.','6','.'}
                            ,{'8','.','.','.','6','.','.','.','3'}
                            ,{'4','.','.','8','.','3','.','.','1'}
                            ,{'7','.','.','.','2','.','.','.','6'}
                            ,{'.','6','.','.','.','.','2','8','.'}
                            ,{'.','.','.','4','1','9','.','.','5'}
                            ,{'.','.','.','.','8','.','.','7','9'}};
    Solution sol;
    a = sol.isValidSudoku(m);
    cout<<a;
    return 0;
}
