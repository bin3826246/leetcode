//
// Created by Master on 2021/11/18.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double result = 0;
        int totalLength = nums1.size() + nums2.size();
        if(totalLength % 2 == 0){

        }
        return result;
    }
    int find(vector<int>& nums1, vector<int>& nums2, int k){
        int index1(0), index2(0);
        int median(0);

        return median;
    }
};

int main(){
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    Solution sol;
    double median = sol.findMedianSortedArrays(nums1, nums2);
    cout<<median;
    return 0;
}