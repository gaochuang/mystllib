#include <iostream>
#include "dynamiclist.h"

using namespace std;
using namespace MyLib;

int main()
{

   DynamicLisy<int> test(5);

   for(int i=0;i<test.capacity();i++)
   {
         test.insert(0,i);
   }

    for(int i=0;i<test.length();i++)
   {
      cout<<test[i]<<endl;
    }
    return 0;
}
