//
// Created by Master on 2021/11/23.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.size() != goal.size()) return false;
        else{
            if (s == goal){
                vector<int> count(26);
                for (char i : s) {
                    count[i - 'a']++;
                    if (count[i - 'a'] > 1){
                        return true;
                    }
                }
                return false;
            } else{
                int first(-1), second(-1), ds(0);
                for (int i = 0; i < s.size(); ++i) {
                    if (s[i] != goal[i] && first == -1){
                        first = i;
                        ds++;
                    }
                    if (s[i] != goal[i] && first != i){
                        second = i;
                        ds++;
                    }
                    if (ds > 2) return false;
                }
                return s[first] == goal[second] && s[second] == goal[first];
            }
        }
    }
};

int main() {
    bool f;
    string s = "abac";
    string goal = "abad";
    Solution sol;
    f = sol.buddyStrings(s, goal);
    cout << f;
    return 0;
}