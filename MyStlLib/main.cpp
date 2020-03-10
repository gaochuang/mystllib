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
        throw Exception("test",__FILE__,__LINE__);
    }
    catch (const Exception& e)
    {
        cout<<"Exception& e"<<endl;
        cout<<e.location()<<endl;
        cout<<e.message()<<endl;
    }
    return 0;
}
