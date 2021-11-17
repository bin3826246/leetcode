//
// Created by Master on 2021/11/15.
//

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int sLen = s.size();
        unordered_map<char, int> maps;
        int strLen, left(0), right(0), maxLen(0);
        char letter;
        pair<unordered_map<char, int>::iterator, bool> ret;
        //left，right构建字符串滑动窗口，每次添加新元素，则right加一；
        // 若元素重复，则移动left至最新元素处
        for (int i = 0; i < sLen; ++i) {
            letter = s[i];
            ret = maps.insert(pair<char, int>(letter, i));
            //有重复元素则替换哈希表对应value。
            //该重复元素在现字符串窗口中，移动left至最新插入元素处，并更新替换value；
            // 若不在窗口中则只替换对应value。
            if (!ret.second ) {
                if (left <= maps[letter]) left += maps[letter] - left + 1;
                maps[letter] = i;
            }
            strLen = right - left + 1;
            maxLen = strLen > maxLen ? strLen : maxLen;
            right++;
        }
        return maxLen;
    }
};
int main(){
    string s = "aabaab!bb";
    int len;
    Solution sol;
    len = sol.lengthOfLongestSubstring(s);
    std::cout<<len;
    return 0;
}