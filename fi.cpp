//
// Created by a on 2021/3/3.
//

#include <iostream>

using namespace std;
int f(int n)
{

    if (n != 0 && n != 1)
    {
        n = f(n-1)+f(n-2);

    } else
    {
        n = 1;
    }
//    cout<<n<<endl;
    return n;
}

int main()
{
    int member;
    member = f(3);
    cout<<member<<endl;
    return 0;
}