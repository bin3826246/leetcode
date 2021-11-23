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
            result = (find(nums1, nums2, totalLength / 2) + find(nums1, nums2, totalLength / 2 + 1)) / 2.0;
        } else{
            result = find(nums1, nums2, (totalLength + 1) / 2);
        }
        return result;
    }

    int find(vector<int>& nums1, vector<int>& nums2, int k){
        int start1 = 0, start2 = 0;
        int median(0);
        int l1 = nums1.size();
        int l2 = nums2.size();
        if (l1 == 0 || l2 == 0){
            median = l1 ? nums1[k - 1] : nums2[k - 1];
        } else{
            while (true){
                if (k == 1){
                    median = min(nums1[start1], nums2[start2]);
                    break;
                }
                int index1 = min(start1 + k / 2 - 1, l1 - 1);
                int index2 = min(start2 + k / 2 - 1, l2 - 1);
                if (nums1[index1] > nums2[index2]){
                    k -= index2 - start2 + 1;
                    start2 = index2 + 1;
                } else{
                    k -= index1 - start1 + 1;
                    start1 = index1 + 1;
                }
                if (start1 == l1) {
                    median = nums2[start2 + k - 1];
                    break;
                }
                if (start2 == l2) {
                    median = nums1[start1 + k - 1];
                    break;
                }

            }
        }

        return median;
    }
};

int main(){
    vector<int> nums1 = {1};
    vector<int> nums2 = {1};
    Solution sol;
    double median = sol.findMedianSortedArrays(nums1, nums2);
    cout<<median;
    return 0;
}