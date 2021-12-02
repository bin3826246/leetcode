//
// Created by Master on 2021/12/1.
//
#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {

        ListNode *prehead = new ListNode();
        prehead->next = head;
        ListNode *pre = prehead;
        while(pre->next != nullptr){
            if(pre->next->val == val){
                auto tmp = pre->next->next;
                delete pre->next;
                pre->next = tmp;
            }else{
                pre = pre->next;
            }

        }
        return prehead->next;
    }
};