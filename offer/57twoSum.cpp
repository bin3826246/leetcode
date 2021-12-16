//
// Created by Master on 2021/12/15.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        int f(0), s(len - 1);
        int l(0), r = (f + s) / 2;
        vector<int> res;
        while(!(nums[r] < target / 2 && nums[r + 1] >= target / 2)){
            if(nums[r + 1] < target / 2) f = r + 1;
            if(nums[r] > target / 2) s = r - 1;
            r = (f + s) / 2;
        }
        for(int i = r + 1; nums[i] < target && res.empty(); i++){
            int p = target - nums[i];
            int left = l, right = r;
            while(left <= right){
                int m = (left + right) / 2;
                if(nums[m] == p){
                    res = {p, nums[i]};
                    break;
                }
                if(nums[m] < p){
                    left = m + 1;
                }
                if(nums[m] > p){
                    right = m - 1;
                }
            }
        }
        return res;
    }
};

int main(){
    vector<int> nums = {14,15,16,22,53,60};

    int target = 76;
    Solution sol;
    vector<int> res = sol.twoSum(nums, target);
    for(int n : res){
        cout<<n<<',';
    }
    return 0;
}
