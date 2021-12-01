//
// Created by Master on 2021/12/1.
//
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> map;
        for(char i : s){
            if (map.find(i) == map.end()){
                map.insert(pair<char, int>(i, 1));
            } else{
                map[i]++;
            }
        }
        for(char j : t){
            if (map.find(j) != map.end()){
                if (map[j] > 1){
                    map[j]--;
                } else{
                    map.erase(j);
                }
            } else{
                return false;
            }
        }
        return map.empty();
    }
};

int main() {
    bool f;
    string s = "ab";
    string t = "a";
    Solution sol;
    f = sol.isAnagram(s, t);
    cout << f;
    return 0;
}