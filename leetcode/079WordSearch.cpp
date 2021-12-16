//
// Created by Master on 2021/12/16.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    int m;
    int n;
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == word[0]){
                    if(dfs(board, word, i, j)){
                        return true;
                    }

                };
            }
        }

        return false;
    }
    bool dfs(vector<vector<char>>& board, string word, int i, int j){

        if(i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[0]) return false;
        if(word.size() == 1) return true;
        char t = board[i][j];
        board[i][j] = '.';
        bool r = false;
        r = dfs(board, word.substr(1, word.size() - 1), i + 1, j) || dfs(board, word.substr(1, word.size() - 1), i - 1, j)
            || dfs(board, word.substr(1, word.size() - 1), i, j + 1) || dfs(board, word.substr(1, word.size() - 1), i, j - 1);
        board[i][j] = t;
        return r;
    }
};

int main(){
    vector<vector<char>> board = {{'A','B','C','E'},
                                  {'S','F','C','S'},
                                  {'A','D','E','E'}};
    string word = "ABCB";
    Solution sol;
    bool r = sol.exist(board, word);
    cout<<r;
    return 0;
}
