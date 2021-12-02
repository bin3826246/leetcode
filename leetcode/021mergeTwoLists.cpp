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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        auto *r = new ListNode(-1);
        auto *head = r;
        while (list1 != nullptr && list2 != nullptr){
            if (list1->val <= list2->val){
                auto *t = new ListNode(list1->val);
                r->next = t;
                r = r->next;
                list1 = list1->next;
            } else{
                auto *t = new ListNode(list2->val);
                r->next = t;
                r = r->next;
                list2 = list2->next;
            }
        }
        r->next = list1 == nullptr ? list2 : list1;

        return head->next;
    }
};

int main(){
    vector<int> a1 = {1,2,4};
    vector<int> a2 = {1,3,4,5,6};
    int len1 = a1.size();
    int len2 = a2.size();
    ListNode* h1 = new ListNode(a1[0]);
    ListNode* h2 = new ListNode(a2[0]);
    //保留头指针
    ListNode* head1 = h1;
    ListNode* head2 = h2;
    //从前至后创建链表
    for (int i = 1; i < len1; i++) {
        h1->next = new ListNode(a1[i]);
        h1 = h1->next;
    }
    for (int i = 1; i < len2; i++) {
        h2->next = new ListNode(a2[i]);
        h2 = h2->next;
    }

    Solution sol;
    ListNode *q = sol.mergeTwoLists(head1, head2);
    for(ListNode* p = q;p;p=p->next){
        cout << p->val<<',' ;
    }
    return 0;
}