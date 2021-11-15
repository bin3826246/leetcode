//
// Created by Master on 2021/11/14.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode *p = nullptr;
        ListNode *result = p;
        int carry = 0;
        while (l1 || l2){
            int n1 = l1 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;
            int sum = n1 + n2 + carry;
            carry = sum / 10;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
            if (!result){
                result = p = new ListNode(sum % 10);
            } else{
                p->next = new ListNode(sum % 10);
                p = p->next;
            }

        }
        if (carry > 0){
            p->next = new ListNode(carry);
        }
        return result;
    }
};

int main(){
    vector<int> a1 = {2,4,3};
    vector<int> a2 = {5,6,4};
    int len1 = a1.size();
    ListNode* h1 = new ListNode(a1[0]);
    ListNode* head1 = h1; //保留头指针
    //从前至后创建链表
    for (int i = 1; i < len1; i++) {
        h1->next = new ListNode(a1[i]);
        h1 = h1->next;
    }

    int len2 = a1.size();
    ListNode* h2 = new ListNode(a2[0]);
    ListNode* head2 = h2;
    for (int i = 1; i < len2; i++) {
        h2->next = new ListNode(a2[i]);
        h2 = h2->next;
    }

//    while (head1) {
//       cout << head1->val << endl;
//        head1 = head1->next;
//    }
//    cout<<endl;


    Solution sol;
    ListNode *q = sol.addTwoNumbers(head1, head2);
    for(ListNode* p = q;p;p=p->next){
        cout << p->val<<',' ;
    }
    return 0;
}