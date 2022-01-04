//
// Created by Master on 2022/1/4.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        if(len < 3) return vector<vector<int>>{};
        quickSort(nums);
        vector<vector<int>> res;
        for(int i = 0; i < nums.size() - 2; i++){
            if(nums[0] > 0) break;
            if(i >= 1 && nums[i] == nums[i - 1]) continue;
            int left = i + 1;
            int right = len - 1;
            while(left < right){
                if(nums[i] + nums[left] + nums[right] < 0){
                    left++;
                }else if(nums[i] + nums[left] + nums[right] > 0){
                    right--;
                }else{
                    res.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    while(left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }
                    while(left < right && nums[right] == nums[right + 1]){
                        right--;
                    }
                }
            }
        }
        return res;
    }
    void quickSort(vector<int>& nums){
        int len = nums.size();
        qsort(nums, 0, len - 1);
    }
    void qsort(vector<int>& nums, int left, int right){
        if(left >= right) return;
        int pivot = nums[left];
        int i = left;
        int j = right;
        while(i < j){
            while(i < j && nums[j] >= pivot) j--;
            swap(nums[i], nums[j]);
            while(i < j && nums[i] <= pivot) i++;
            swap(nums[i], nums[j]);
        }
        qsort(nums, left, i - 1);
        qsort(nums, i + 1, right);
    }
};

int main(){
    vector<int> nums = {-1,0,1,2,-1,-4};
    Solution sol;
    vector<vector<int>> res = sol.threeSum(nums);
    for(auto v : res){
        for(int n : v){
            cout<<n<<',';
        }
        cout<<endl;
    }
    return 0;
}
