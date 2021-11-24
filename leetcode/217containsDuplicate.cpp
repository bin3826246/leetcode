//
// Created by Master on 2021/11/24.
//
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        bool result(false);
        unordered_set<int> s;
        pair<unordered_set<int>::iterator, bool> r;
        for (int a : nums) {
            r = s.insert(a);
            if (!r.second){
                result = true;
                break;
            }
        }

        return result;
    }
};

int main() {
    bool f;
    vector<int> nums;
    Solution sol;
    f = sol.containsDuplicate(nums);
    cout << f;
    return 0;
}