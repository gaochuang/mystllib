#include <iostream>
#include "staticarray.h"

using namespace std;
using namespace MyLib;

int main()
{

    StaticArray<int,5> s1;

    for(int i=0;s1.length();i++)
    {
        s1[i]=i*i;
    }

    for(int i=0;i<s1.length();i++)
    {
        cout<<s1[i]<<endl;
    }



    return 0;
}
