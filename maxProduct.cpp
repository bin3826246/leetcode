//
// Created by Master on 2021/11/17.
//
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <utility>
using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        /*想从乘积最大的开始筛选，结果超时
        multimap<int, pair<string, string>> map;
        int length = words.size();
        int product = 0;
        int result = 0;
        pair<string, string> pairWords;
        for (int i = 0; i < length; ++i) {
            for (int j = i + 1; j < length; ++j) {
                product = int(words[i].size() * words[j].size());
                pairWords = make_pair(words[i], words[j]);
                map.insert(pair<int, pair<string, string>>(product, pairWords));
            }
        }

        unsigned int one = 1;
        vector<unsigned int> mask(2, 0);
        for (auto it = map.rbegin(); it != map.rend(); it++) {
            string word0 = it->second.first;
            string word1 = it->second.second;
            for (char i : word0) mask[0] |= one << (i - 'a');
            for (char j : word1) mask[1] |= one << (j - 'a');

            if (!(mask[0] & mask[1])) {
                result = it->first;
                break;
            } else{
                mask = {0, 0};
            }
        }
    return result;
    }*/
        int length = words.size();
        int result = 0;
        vector<unsigned int> mask(length, 0);
        for (int i = 0; i < length; ++i) {
            string word = words[i];
            for (char j :word)  mask[i] |= 1 << (j - 'a');
        }

        for (int i = 0; i < length; ++i) {
            for (int j = i + 1; j < length; ++j) {
                if (!(mask[i] & mask[j])){
                    result = max(result, int(words[i].size() * words[j].size()));
                }
            }
        }
        return result;
    }
};

int main(){
    vector<string> words = {"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
    Solution sol;
    int product = sol.maxProduct(words);
    cout<<product;
    return 0;
}