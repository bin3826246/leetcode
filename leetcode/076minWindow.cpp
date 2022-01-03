//
// Created by Master on 2022/1/3.
//
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int len = s.size();
        unordered_map<char, int> tmap;
        int left(0), right(0);
        int need = t.size();
        int minLen = len + 1;
        int start(0);
        for(char c : t){
            if(tmap.find(c) == tmap.end()){
                tmap.insert({{c, 1}});
            }else{
                tmap[c]++;
            }
        }
        while(right <= len){
            char l = s[left];
            char r = s[right];
            if(tmap.find(s[left]) == tmap.end()){
                left++;
            }
            if(tmap.find(s[right]) != tmap.end()){
                if(tmap[s[right]] > 0) need--;
                tmap[s[right]]--;
            }
            if(need == 0){
                if(tmap.find(s[left]) != tmap.end() && tmap[s[left]] < 0){
                    tmap[s[left]]++;
                    left++;
                    while (tmap.find(s[left]) == tmap.end() || (tmap.find(s[left]) != tmap.end() && tmap[s[left]] != 0)){
                        if(tmap.find(s[left]) != tmap.end() && tmap[s[left]] != 0) tmap[s[left]]++;
                        left++;
                    }
                }
                if(right - left + 1 < minLen){
                    minLen = right - left + 1;
                    start = left;
                }
            }
            right++;
        }
        cout<<start<<','<<minLen;
        return minLen == len + 1 ? "" : s.substr(start, minLen);
    }
};

int main(){
    string s ="bba";
    string t = "ab";
    Solution sol;
    string res = sol.minWindow(s, t);
    cout<<res;
    return 0;
}
