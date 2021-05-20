//
// Created by a on 2020/8/15.
//

#include <iostream>
#include <vector>
using namespace std;

bool ifSameArray(const int *arr , const int *arr1, int size)
{

    int flag = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == arr1[i])
        {
            flag = 1;
        }
        else{
            break;
        }
    }

    return flag != 0;


}

 int main()
 {
    vector<int> v1, v2;
    v1 = {3, 44, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 48};
    v2 = {2, 3, 4, 5, 15, 19, 26, 27, 36, 38, 44, 46, 47, 48, 50};
    const int len = v1.size();
    cout<<len<<endl;
    int temp;
     for (int i = 0; i < len; i++) {
         for (int j = 0; j < len - i - 1; j++) {
             if (v1[j] > v1[j+1])
             {
                 temp = v1[j];
                 v1[j] = v1[j + 1];
                 v1[j + 1] = temp;
             }
         }
//         cout<<i<<endl;
     }
     for (int k : v1) {
         cout<<k<<",";
     }
     cout<<endl;

    cout << boolalpha << (v1 == v2) << endl;
    return 0;
 }