//
// Created by Master on 2021/12/19.
//
#include <iostream>
#include <vector>
#include <queue>
//#include <functional>
using namespace std;

class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int, vector<int>, less<>> maxHeap;
    priority_queue<int, vector<int>, greater<>> minHeap;
    MedianFinder() {}

    void addNum(int num) {
        if(minHeap.size() == maxHeap.size()){
            minHeap.push(num);
            maxHeap.push(minHeap.top());
            minHeap.pop();
        } else{
            maxHeap.push(num);
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }

    double findMedian() {
        double med;
        if (minHeap.size() == maxHeap.size()){
            med = (maxHeap.top() + minHeap.top()) / 2.0;
        } else{
            med = maxHeap.top();
        }
        return med;
    }
};

int main(){
    MedianFinder* obj = new MedianFinder();
//    obj->addNum(1);
    obj->addNum(2);
    obj->addNum(3);
    double param_2 = obj->findMedian();
    cout<<param_2;
    return 0;
}

