//
// Created by Master on 2021/12/10.
//
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

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