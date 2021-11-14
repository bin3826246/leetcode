//
// Created by Master on 2021/6/15.
//
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr);
};

int Solution::peakIndexInMountainArray(vector<int> &arr) {
    int i;
    for(i = 1; i < arr.size(); i++){
        if(arr[i-1] < arr[i] && arr[i] > arr[i+1]){
            break;
        }
    }
    return i;
}