//
// Created by Master on 2022/1/2.
//
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int cuttingRope(int n) {
        if(n < 4) return n - 1;
        long long res = 1;
        int nthree = n / 3;
        int rthree = n % 3;
        if(rthree == 2){
            res = 2;
        } else if(rthree == 1){
            res = 4;
            nthree--;
        }
        while (nthree){
            res = res * 3 % 1000000007;
            nthree--;
        }
        return (int)res;
    }
};
int main(){
    int n = 10;
    Solution sol;
    int res = sol.cuttingRope(n);
    cout<<res;
    return 0;
}