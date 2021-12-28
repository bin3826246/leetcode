//
// Created by Master on 2021/12/28.
//有限状态自动机
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        unordered_map <int, unordered_map <char, int>> state = {
                {0, {{' ', 0}, {'s', 1}, {'d', 2}, {'.', 4}}},
                {1, {{'d', 2}, {'.', 4}}},
                {2, {{'d', 2}, {'.', 3}, {'e', 5}, {' ', 8}}},
                {3, {{'d', 3}, {'e', 5}, {' ', 8}}},
                {4, {{'d', 3}}},
                {5, {{'s', 6}, {'d', 7}}},
                {6, {{'d', 7}}},
                {7, {{'d', 7}, {' ', 8}}},
                {8, {{' ', 8}}}
        };
        int p = 0;
        char t;
        for(char c : s){
            if(c - '0' >= 0 && c - '0' <= 9){
                t = 'd';
            }else if(c == '+' || c == '-'){
                t = 's';
            }else if(c == 'e' || c == 'E'){
                t = 'e';
            }else if(c == '.' || c == ' '){
                t = c;
            }else{
                t = '?';
            }
            if(state[p].find(t) == state[p].end()){
                return false;
            }
            p = (int) state[p][t];
        }
        return p == 2 || p == 3 || p == 7 || p == 8;
    }
};
int main(){
    string s = "05A";
    Solution sol;
    bool res = sol.isNumber(s);

    cout<<res<<',';

    return 0;
}