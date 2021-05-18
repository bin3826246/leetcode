//
// Created by a on 2021/1/11.
//
#include <iostream>
#include <vector>
#include <array>

int main()
{
    using namespace std;
    array<double, 4> a3 = {3.14, 2.72, 1.62, 1.41};
    array<double, 4> a4{};
    a4 = a3;
    a3[1] = 3;
    cout << a3[1] <<endl;
    cout << a4[1] <<endl;
    vector<double> a1,a2;
    a1 = {1,2,3,4};
    a2 = a1;
    a1[1] = 9;
    cout<< a1[1]<<endl;
    cout<< a2[1]<<endl;
}