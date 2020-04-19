#include <iostream>
#include "dynamicarray.h"
#include"linklist.h"
#include"staticlinklist.h"

using namespace std;
using namespace MyLib;

int main()
{
    StaticLinkList<int,5> list;

    for(int i=0;i<5;i++)
    {
        list.insert(0,i);
    }

    try
    {
       list.insert(6);
    }
    catch (const Exception& e)
    {
        cout<<e.message()<<endl;
    }



    for(list.move(0);!list.end();list.next())
    {
        cout<<list.current()<<endl;
    }


    return 0;
}
