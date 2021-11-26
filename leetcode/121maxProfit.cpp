//
// Created by Master on 2021/11/26.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result(0);
        int maxp(prices[0]), minp(prices[0]);
        for(int price : prices){
            if (price < minp){
                minp = price;
                maxp = minp;
            }
            if (price > maxp){
                maxp = price;
                result = max(result, maxp - minp);
            }
        }

        return result;
    }
};

int main(){
    vector<int> nums1 = {2,4,1};
    int v;
    Solution sol;
    v = sol.maxProfit(nums1);
    cout<<v;

    return 0;
}