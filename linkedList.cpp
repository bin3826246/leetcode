//
// Created by Duan Bin on 2021/5/9.
//
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class LinkedList
{
public:
    LinkedList();
    ~LinkedList();
    int Create(const int *arr) const;
    int Insert(Node *newNode, int n) const;
    int Delete(int n) const;
    int Print() const;
    int Reverse() const ;
    Node *head;
    int size;
};

LinkedList::LinkedList() {
    head = new Node;
    head->data = 0;
    head->next = nullptr;
    size = 0;
}

LinkedList::~LinkedList() {
    Node *p = this->head;
    while (p)
    {
        Node * q = p->next;
        delete p;
        p = q;
    }
    delete head;
}

int LinkedList::Create(const int *arr) const {
    Node *p = nullptr;
    p = this->head;
    p->next = nullptr;
    p->data = arr[0];

    int i = 0;
    while (arr[i]){
        Node *ptemp = new Node;
        ptemp->data = arr[i];
        ptemp->next = p->next;
        p->next = ptemp;
        p = ptemp;
        i++;
    }
    return 0;
}

int LinkedList::Insert(Node *newNode, int n) const {
    Node *pNode;
    pNode = this->head;
    for (int i = 0; i < n; i++) {
        pNode = pNode->next;
    }
    newNode->next = pNode->next;
    pNode->next = newNode;
    return 0;
}

int LinkedList::Delete(int n) const {
    Node *pNode;
    pNode = this->head;
    for (int i = 0; i < n; i++) {
        pNode = pNode->next;
    }
    Node *q;
    q = pNode->next;
    pNode->next = pNode->next->next;
    delete q;
    return 0;
}

int LinkedList::Print() const
{
     for(Node * p = head->next;p;p=p->next){
         cout << p->data<<',' ;
     }
     return 0;
}

int LinkedList::Reverse() const
{
     Node * pre = head->next;
     Node * cur = head->next->next;
     Node * next = head->next->next->next;
    pre->next = nullptr;
     while(next){
         cur->next = pre;
         pre = cur;
         cur = next;
         next = next->next;
     }
    cur->next = pre;
     head ->next = cur;
     return 0;
}

int main()
{
    int li[10] = {1,2,3,4,5,6};
    Node temp{};
    temp.data = 100;
    temp.next = nullptr;

    LinkedList List;
    List.Create(li);
    List.Print();
    cout<<endl;
    List.Insert(&temp, 0);
    List.Print();
    cout<<endl;
    List.Delete(3);
    List.Print();
    cout<<endl;
    List.Reverse();
    List.Print();
    cout<<endl;

    return 0;
}
