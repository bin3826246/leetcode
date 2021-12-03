//
// Created by Master on 2021/12/3.
//
#include <iostream>
#include <stack>
using namespace std;

class MinStack {
    stack<int> st;
    stack<int> min_st;
public:
    /** initialize your data structure here. */
    MinStack() {
        min_st.push(INT32_MAX);
    }

    void push(int x) {
        st.push(x);
        if (x <= min_st.top()){
            min_st.push(x);
        }
    }

    void pop() {
        if (st.top() == min_st.top()){
            min_st.pop();
        }
        st.pop();
    }

    int top() {
        return st.top();
    }

    int min() {
        return min_st.top();
    }
};

int main(){
    int x = 3;
    MinStack* obj = new MinStack();
    obj->push(-2);
    obj->push(0);
    obj->push(-3);
//    obj->push(-9);
    obj->pop();
    int param_3 = obj->top();
    int param_4 = obj->min();
    cout<<param_3<<endl;
    cout<<param_4<<endl;
    return 0;
}

