//
// Created by a on 2020/12/24.
//
#include <iostream>
int main()
{
    using namespace std;
    const int ArSize = 20;
    char name[ArSize];
    char dessert[ArSize];
    int a;
    cin>>a;
    cout<<"Enter your name:\n";

    cin.getline(name, ArSize);
    cout<<"Enter your favourite dessert:\n";
    cin.getline(dessert,ArSize);
    cout<<"I have some delicious " << dessert;
    cout<<" for you," << name << ".\n";
    return 0;
}
