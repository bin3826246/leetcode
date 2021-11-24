//
// Created by Master on 2021/11/24.
//
#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int ret(0), pre(0);
        while(x != 0){
            pre = ret;
            ret = x % 10 + ret * 10;
            if ((ret - x % 10) / 10 != pre) return 0;
            x = x / 10;
        }
            return ret;
    }
};

int main(){
    int x = 1534236469;
    Solution sol;
    int r= sol.reverse(x);
    cout<<r;
    return 0;
}