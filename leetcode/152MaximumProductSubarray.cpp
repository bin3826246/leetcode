//
// Created by Master on 2021/12/16.
//
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int product = 1;
        int res = nums[0];
        int dpmax = 1;
        int dpmin = 1;
        for(int i = 0; i < nums.size(); i++){
            dpmax = max(dpmax * nums[i], max(dpmin * nums[i], nums[i]));
            dpmin = min(dpmax * nums[i], min(dpmin * nums[i], nums[i]));
            res = max(dpmax, res);
        }
        return res;
    }
};

int main(){
    vector<int> nums1 = {-4,-3,-2};
    Solution sol;
    int a = sol.maxProduct(nums1);
    cout<<a;
    return 0;
}