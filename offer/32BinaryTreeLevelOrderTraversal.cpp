//
// Created by Master on 2021/12/10.
//
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define null -1
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> order;
        if(root == nullptr) return res;
        order.push(root);
        while(!order.empty()){
            res.emplace_back(order.front()->val);
            if(order.front()->left != nullptr){
                order.push(order.front()->left);
            }
            if(order.front()->right != nullptr){
                order.push(order.front()->right);
            }
            order.pop();
        }
        return res;
    }
};
int main() {
    vector<int> nums = {3,9,20,null,null,15,7};
    TreeNode *root = new TreeNode(nums[0]);
    queue<TreeNode *> que;
    que.push(root);
    int i = 1;
    while (i < nums.size()) {
        if (nums[i] != null) {
            que.front()->left = new TreeNode(nums[i]);
            que.push(que.front()->left);
        } else {
            que.front()->left = nullptr;
        }
        i++;
        if (nums[i] != null) {
            que.front()->right = new TreeNode(nums[i]);
            que.push(que.front()->right);
        } else {
            que.front()->right = nullptr;
        }
        i++;
        que.pop();
    }
    Solution sol;
    vector<int> res = sol.levelOrder(root);
    for(int a : res){
        cout<<a<<',';
    }

    return 0;
}