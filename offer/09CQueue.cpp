//
// Created by Master on 2021/12/3.
//
#include <iostream>
#include <stack>
using namespace std;

class CQueue {
    stack<int> stack_in, stack_out;
public:
    CQueue() {

    }

    void appendTail(int value) {
        stack_in.push(value);
    }

    int deleteHead() {
        int first;
        if (stack_in.empty()){
            first = -1;
        } else{
            while (!stack_in.empty()){
                stack_out.push(stack_in.top());
                stack_in.pop();
            }
            first = stack_out.top();
            stack_out.pop();
            while (!stack_out.empty()){
                stack_in.push(stack_out.top());
                stack_out.pop();
            }
        }
        return first;
    }
};

int main(){
    int value = 3;
    CQueue* obj = new CQueue();
    obj->appendTail(5);
    obj->appendTail(2);
    int param_2 = obj->deleteHead();
    cout<<param_2;
    return 0;
}