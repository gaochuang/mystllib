#include <iostream>
#include"smartpointer.h"

using namespace std;
using namespace MyLib;

//测试类
class Test
{
public:
    Test()
    {
        cout<<"Test()"<<endl;
    }

    ~Test()
    {
        cout<<"~Test()"<<endl;
    }

};

int main()
{
    SmartPointer<Test> t = new Test();

    return 0;
}
