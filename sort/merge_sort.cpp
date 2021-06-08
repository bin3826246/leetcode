//
// Created by Master on 2021/6/5.
//

#include <iostream>
#include <vector>


using namespace std;
template <typename T>
void merge(vector<T> &arr, vector<T> &tmpArr, int left, int center, int right)
{
    int i = left;
    int j = center + 1;
    int k;
    for (k = i; i <= center && j <= right; k++) {
        if (arr[i] <= arr[j])
            tmpArr[k] = arr[i++];
        else
            tmpArr[k] = arr[j++];
    }
    while (i<=center)
        tmpArr[k++] = arr[i++];
    while (j<=right)
        tmpArr[k++] = arr[j++];
    for (int m = left; m <= right; m++) {
        arr[m] = tmpArr[m];
    }
}

template <typename T>
void Msort(vector<T> &arr, vector<T> &tmpArr, int left, int right)
{
    if (left < right)
    {
        int center = (left + right) / 2;
        Msort(arr, tmpArr, left, center);
        Msort(arr, tmpArr, center+1, right);
        merge(arr, tmpArr, left, center, right);
    }
}
template <typename T>
void mergeSort(vector<T> &v)
{
   vector<T> tmpArr(v.size());
   Msort(v, tmpArr, 0, v.size()-1);

}



int main()
{
    vector<int> v1, v2;
    v1 = {3, 44, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 48};
    v2 = {2, 3, 4, 5, 15, 19, 26, 27, 36, 38, 44, 46, 47, 48, 50};
    mergeSort(v1);
    for (int k : v1) cout<<k<<",";

    cout<<endl;

    cout << boolalpha << (v1 == v2) << endl;
    return 0;
}