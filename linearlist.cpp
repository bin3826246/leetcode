//
// Created by a on 2020/12/22.
//
#include <iostream>

using namespace std;

template<class T>
class linearList
{
public:
    ~linearList();
    virtual bool empty() const=0;
    virtual int size() const =0;
    virtual T& get(int theIndex) const=0;
    virtual int indexOf(const T& theElement) const =0;
    virtual void erase(int theIndex) =0;
    virtual void insert(int theIndex, const T& theElement) = 0;
    virtual void output(std::ostream& out) const = 0;

};

template<class T>
linearList<T>::~linearList() {
cout<<'0';
}

int main()
{
    linearList<T> l ;
    return 0;
}