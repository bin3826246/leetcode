//
// Created by a on 2020/9/14.
//

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v1, v2;
    v1 = {3, 44, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 48};
    v2 = {2, 3, 4, 5, 15, 19, 26, 27, 36, 38, 44, 46, 47, 48, 50};
    const int len = v1.size();
    int temp;
    for (int i = 0; i < len; i++) {
        int min = i;

        for (int j = i + 1; j < len; ++j) {
            if (v1[j] < v1[min]){
                min = j;
            }
        }
        if(min != i)
        {
            temp = v1[i];
            v1[i] = v1[min];
            v1[min] = temp;
        }
    }
    for (int k : v1) {
        cout<<k<<",";
    }
    cout<<endl;

    cout << boolalpha << (v1 == v2) << endl;
    return 0;
}