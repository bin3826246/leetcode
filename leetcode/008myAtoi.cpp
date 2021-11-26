//
// Created by Master on 2021/11/25.
//
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int result(0);
        long long ret(0);
        int flag(1); //正数为1
        for(int i = 0; i < s.size(); i++){
            if ((s[i] - 'a' >= 0 && s[i] - 'a' <= 26) || (s[i] - 'A' >= 0 && s[i] - 'A' <= 26) || s[i] == '.') break;
            if (s[i] - '0' >= 0 && s[i] - '0' <= 9){
                ret = ret * 10 + (s[i] - '0');
                if (ret > 2147483647 || ret < -2147483648){
                    ret = flag > 0 ? 2147483647 : -2147483648;
                    flag = 1;
                    break;
                }
                if (s[i + 1] - '0' < 0 || s[i + 1] - '0' > 9) break;
            }
            if (s[i] == ' ') continue;
            if (s[i] == '-') {
                flag = -1;
                if (s[i + 1] - '0' < 0 || s[i + 1] - '0' > 9) break;
                continue;
            }
            if (s[i] == '+') {
                if (s[i + 1] - '0' < 0 || s[i + 1] - '0' > 9) break;
                continue;
            }
        }
        ret = ret * flag;
        result = (int)ret;
        return result;
    }
};

int main(){
    string s = "2147483648";
    Solution sol;
    int a= sol.myAtoi(s);
    cout<<a;
    return 0;
}
