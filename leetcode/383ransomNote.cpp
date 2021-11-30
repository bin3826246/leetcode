//
// Created by Master on 2021/11/30.
//
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> map;
        for(char s : magazine){
            if (map.find(s) == map.end()){
                map.insert(pair<char, int>(s, 1));
            } else{
                map[s]++;
            }
        }
        for(char c : ransomNote){
            if (map.find(c) != map.end()){
                map[c]--;
                if (map[c] == 0){
                    map.erase(c);
                }
            } else{
                return false;
            }
        }
        return true;
    }
};

int main() {
    bool f;
    string ransomNote = "aa";
    string magazine = "aa";
    Solution sol;
    f = sol.canConstruct(ransomNote, magazine);
    cout << f;
    return 0;
}