//
// Created by Master on 2021/11/29.
//
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int index(-1);
        int len = s.size();
        vector<int> mask(len, 0);
        unordered_map<char, int> map;
        pair<unordered_map<char, int>::iterator, bool>  ret;
        for (int i = 0; i < len; ++i) {
            ret = map.insert(pair<char, int>(s[i], i));
            if (!ret.second){
                mask[ret.first->second]++;
                mask[i] = mask[ret.first->second];
            } else{
                mask[i]++;
            }
        }
        for (int j = 0; j < 26; ++j) {
            if (mask[j] == 1){
                index = j;
                break;
            }
        }
        return index;
    }
};

int main() {
    int f;
    string s = "aabb";
    Solution sol;
    f = sol.firstUniqChar(s);
    cout << f;
    return 0;
}
