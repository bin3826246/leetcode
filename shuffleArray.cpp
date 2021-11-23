//
// Created by Master on 2021/11/22.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<int> original_nums;
    vector<int> shuffle_nums;
public:
    Solution(vector<int>& nums) {
        this->original_nums = nums;
        this->shuffle_nums = nums;
    }

    vector<int> reset() {
        return original_nums;
    }

    vector<int> shuffle() {
        int length = original_nums.size();
        int r, tmp;
        for (int i = 0; i < length; ++i) {
            r = rand() % (length);
            tmp = shuffle_nums[i];
            shuffle_nums[i] = shuffle_nums[r];
            shuffle_nums[r] = tmp;
        }
        return shuffle_nums;
    }
};

int main(){
    vector<int> nums = {1, 2, 3};
    auto* obj = new Solution(nums);
    vector<int> param_1 = obj->reset();
    vector<int> param_2 = obj->shuffle();
    for (auto it = param_1.begin(); it < param_1.end(); it++) {
        cout<<*it<<',';
    }
    cout<<endl;
    for (auto it = param_2.begin(); it < param_2.end(); it++) {
        cout<<*it<<',';
    }

    return 0;
}