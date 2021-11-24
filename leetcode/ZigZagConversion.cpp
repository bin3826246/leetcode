//
// Created by Master on 2021/11/23.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Solution {
public:
    string convert(string s, int numRows) {
        string result;
        int len = s.size(), r, cols, m(0);
        if(len <= 1 || numRows < 2) return s;
        r = len % (2 * numRows - 2) <= numRows ? 1 : 1 + len % (2 * numRows - 2) - numRows;
        cols = len / (2 * numRows - 2) * (numRows - 1) + r;
        vector<vector<char>> z(numRows, vector<char>(cols));
        int j(0);
//        int n = numRows - 2;
        for (int i = 0; i < cols; ++i) {
            for (j = 0; j < numRows; ++j) {
                if(i % (numRows - 1) == 0){
                    if (m < len){
                        z[j][i] = s[m];
                        m++;
                    } else{
                        z[j][i] = ' ';
                    }
                }
                else{
                    if (j == numRows - i % (numRows - 1) - 1){
                        z[j][i] = s[m++];
                    } else{
                        z[j][i] = ' ';
                    }
                }
            }
        }
        for (auto & ity : z) {
            for (auto & itx : ity) {
                if (itx != ' ')
                    result += itx;
            }
        }
        return result;
    }
};

int main(){
    string s = "PAYPALISHIRING";
    int numRows = 3;
    Solution sol;
    string str= sol.convert(s, numRows);
    cout<<str;
    return 0;
}