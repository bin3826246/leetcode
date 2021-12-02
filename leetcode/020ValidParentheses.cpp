//
// Created by Master on 2021/12/2.
//
#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 == 1) return false;
        unordered_map<char, char> pairs ={{')', '('}, {']', '['}, {'}', '{'}};
        stack<char> barckets;
        for(char c : s){
            if (pairs.find(c) == pairs.end()){
                barckets.push(c);
            } else{
                if (!barckets.empty() && pairs[c] == barckets.top()){
                    barckets.pop();
                } else{
                    return false;
                }
            }
        }
        return barckets.empty();
    }
};

int main() {
    bool f;
    string s = "){";
    Solution sol;
    f = sol.isValid(s);
    cout << f;
    return 0;
}