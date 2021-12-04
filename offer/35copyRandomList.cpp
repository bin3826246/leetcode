//
// Created by Master on 2021/12/4.
//
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;
        unordered_map<Node*, Node*> maps;
        Node* p = head;
        while(p != nullptr){
            maps[p] = new Node(p->val);
            p = p->next;
        }
        p = head;
        while(p != nullptr){
            maps[p]->next = maps[p->next];
            maps[p]->random = maps[p->random];
            p = p->next;
        }
        return maps[head];
    }
};

int main(){
    vector<vector<int>> val = {{7,-1}, {13,0}, {11,4}, {10,2}, {1,0}};
    cout<<val.size();
    vector<Node*> vNode;
    vNode.push_back(new Node(val[0][0]));
    Node* head = new Node(val[0][0]);
    Node* p = head;
    for(int i = 1; i < val.size(); i++){
        Node* n =new Node(val[i][0]);
        vNode.push_back(n);
        p->next = n;
        p = p->next;
    }
    for (int j = 0; j < val.size(); ++j) {
        if(val[j][1] == -1){
            vNode[j]->random = nullptr;
        } else{
            vNode[j]->random = vNode[val[j][1]];
        }
    }
    Solution sol;
    Node* res = sol.copyRandomList(head);
    return 0;
}
