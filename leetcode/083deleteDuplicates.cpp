//
// Created by Master on 2021/12/2.
//
#include <iostream>
#include <vector>
#include <unordered_set>
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
    ListNode* deleteDuplicates(ListNode* head) {
        unordered_set<int> nums;
        if (head == nullptr) return head;
        ListNode *cur = head;
        ListNode *next = cur->next;
        nums.insert(cur->val);
        while (next != nullptr){
            if (nums.find(next->val) != nums.end()){
                ListNode *tmp = next;
                cur->next = next->next;
                next = cur->next;
                delete tmp;
            } else{
                nums.insert(next->val);
                cur = next;
                next = next->next;
            }
        }
        return head;
    }
};

int main(){
    vector<int> a1 = {1,1,2,3,3};
    int len1 = a1.size();
    auto* h1 = new ListNode(a1[0]);
    //保留头指针
    ListNode* head1 = h1;
    //从前至后创建链表
    for (int i = 1; i < len1; i++) {
        h1->next = new ListNode(a1[i]);
        h1 = h1->next;
    }
    Solution sol;
    ListNode *q = sol.deleteDuplicates(head1);
    for(ListNode* p = q;p;p=p->next){
        cout << p->val<<',' ;
    }
    return 0;
}
