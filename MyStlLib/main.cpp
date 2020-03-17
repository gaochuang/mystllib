#include <iostream>
#include"smartpointer.h"
#include"exception.h"

using namespace std;
using namespace MyLib;



int main()
{
    //测试
    try
    {
       THROW_EXCEPTION(Exception,"test");
    }
    catch (const Exception& e)
    {
        cout<<"Exception& e"<<endl;
        cout<<e.location()<<endl;
        cout<<e.message()<<endl;
    }
    return 0;
}
