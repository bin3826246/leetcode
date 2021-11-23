//
// Created by Master on 2021/11/22.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string result;
        int len, len1, len2;
        int start(0), end(0);
        if (s.size() <= 1) result = s;
        for (int i = 0; i < s.size(); ++i) {
            len1 = getStr(s, i, i);
            len2 = getStr(s, i, i + 1);
            len = max(len1, len2);
            if (len > end - start){
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        result = s.substr(start, end - start + 1);
        return result;
    }
    int getStr(string s, int left, int right){
        int len(0);
        while (left >= 0 && right < s.size() && s[left] == s[right]){
            if (right - left + 1 > len){
                len = right - left + 1;
            }
            left--;
            right++;
        }
        return len;
    }
};

int main(){
    string s = "babad";
    Solution sol;
    string str= sol.longestPalindrome(s);
    cout<<str;
    return 0;
}