//
// Created by a on 2021/3/1.
//

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
vector<T> shellSort(vector<T> &v)
{
    const int LEN = v.size();
    T temp;
    int increment = LEN/2;
    for (int i = increment; i < LEN; ++i) {
        for (int j = i; j < LEN; ++j) {

        }


    }
    return v;
}

int main()
{
    vector<int> v1, v2;
    v1 = {3, 44, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 48};
    v2 = {2, 3, 4, 5, 15, 19, 26, 27, 36, 38, 44, 46, 47, 48, 50};
    v1 = shellSort(v1);
    for (int k : v1) cout<<k<<",";

    cout<<endl;

    cout << boolalpha << (v1 == v2) << endl;
    return 0;
}