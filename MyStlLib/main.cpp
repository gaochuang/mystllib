#include <iostream>
#include "dynamicarray.h"

using namespace std;
using namespace MyLib;

int main()
{

    DynamicArray<int> s1(5);

    for(int i=0;i<s1.length();i++)
    {
        s1[i]=i*i;
    }

    for(int i=0;i<s1.length();i++)
    {
        cout<<s1[i]<<endl;
    }

    DynamicArray<int> s2(10);


    s2=s1;
    for(int i=0;i<s2.length();i++)
    {
        cout<<s2[i]<<endl;
    }

    s2.resize(3);

    for(int i=0;i<s2.length();i++)
    {
        cout<<s2[i]<<endl;
    }


    return 0;
}
