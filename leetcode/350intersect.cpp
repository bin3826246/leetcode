//
// Created by Master on 2021/11/26.
//
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        unordered_map<int, int> maps;
        pair<unordered_map<int, int>::iterator, bool> isInsert;
        for(auto s1 : nums1){
            isInsert = maps.insert(pair<int, int>(s1, 1));
            if (!isInsert.second) isInsert.first->second++;
        }
        unordered_map<int, int>::iterator got;
        for(auto s2 : nums2){
            got = maps.find(s2);
            if (got != maps.end()){
                result.push_back(s2);
                got->second--;
                if (got->second == 0){
                    maps.erase(s2);
                }
            }
        }
        return result;
    }
};

int main(){
    vector<int> nums1 = {1,2,2,1};
    vector<int> nums2 = {2,2};
    vector<int> v;
    Solution sol;
    v = sol.intersect(nums1, nums2);
    for(int a : v){
        cout<<a<<',';
    }
    return 0;
}