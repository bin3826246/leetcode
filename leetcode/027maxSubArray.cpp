//
// Created by Master on 2021/11/24.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = nums[0];
        int pre(0);
        if  (nums.size() == 1) return nums[0];
        for (auto n : nums){
            pre = max(pre + n, n);
            result = max(pre, result);
        }
        return result;
    }
};

int main(){
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int max;
    Solution sol;
    max = sol.maxSubArray(nums);
    std::cout << max;
    return 0;
}