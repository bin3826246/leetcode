//
// Created by Master on 2021/12/5.
//
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
TreeNode* build_tree(vector<string>& v) {
    if (v.empty() || v[0] == "null") return nullptr;
    TreeNode* root = new TreeNode(stoi(v[0])), * cur;
    queue<TreeNode*> q;
    q.push(root);
    int node_num = 0, idx = 0, N = v.size();
    while (!q.empty() && idx < N - 1) {
        node_num = q.size();
        while ((node_num-- > 0) && (idx < N - 1)) {
            cur = q.front(); q.pop();
            if ((++idx < N) && (v[idx] != "null")) {
                cur->left = new TreeNode(stoi(v[idx]));
                q.push(cur->left);
            }
            if ((++idx < N) && (v[idx] != "null")) {
                cur->right = new TreeNode(stoi(v[idx]));
                q.push(cur->right);
            }
        }
    }
    return root;
}

void inorder(TreeNode* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->val << ' ';
    inorder(root->right);
}
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        if(root == nullptr) return res;
        TreeNode* pre=root;
        stk.push(root);
        while(!stk.empty()){
            if(root->right == pre || (root->left == pre && root->right == nullptr)){
                res.push_back(root->val);
                stk.pop();
                if(stk.empty()) break;
                pre = root;
                root = stk.top();
            }else{
                if(root->right) stk.push(root->right);
                if(root->left) stk.push(root->left);
                if(root->left == nullptr && root->right == nullptr){
                    res.push_back(root->val);
                    stk.pop();
                    pre = root;
                }
                if(stk.empty()) break;
                root = stk.top();
            }
        }
        return res;
    }
};
int main() {
    string s;
    vector<string> node_infor;
//    cout << "Input node val(leetcode form): ";
//    getline(cin, s);
    s = "[1]";
    s.assign(s.begin() + 1, s.end() - 1);

    int cont = 0;
    for (auto ch = s.begin(); ch != s.end(); ch++) {
        if (*ch != ',') cont++;
        else {
            node_infor.push_back(s.substr(ch - s.begin() - cont, cont));
            cont = 0;
        }
    }
    if (!s.empty()) {
        node_infor.push_back(s.substr(s.size() - cont, cont));
    }
    TreeNode* root = build_tree(node_infor);
//    cout << "Inorder traversal: "; inorder(root);//���������֤
    Solution sol;
    vector<int> v = sol.postorderTraversal(root);
    for(int a : v){
        cout<<a<<',';
    }
    return 0;
}