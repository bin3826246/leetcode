//
// Created by Master on 2021/11/25.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> tnums(nums1.begin(), nums1.begin() + m);
        auto itt = tnums.begin();
        auto it1 = nums1.begin();
        auto it2 = nums2.begin();
        while (it1 != nums1.end()){
            if(itt != tnums.end() && it2 != nums2.end()){
                if(*itt <= *it2){
                    *it1 = *itt;
                    itt++;
                } else{
                    *it1 = *it2;
                    it2++;
                }
            } else if(itt == tnums.end()){
                *it1 = *it2;
                it2++;
            } else{
                *it1 = *itt;
                itt++;
            }
            it1++;
        }

    }
};

int main(){
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    int m(3), n(3);
    Solution sol;
    sol.merge(nums1, m, nums2, n);
    for(int a : nums1){
        cout<<a<<',';
    }
    return 0;
}