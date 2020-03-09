#ifndef EXCEPTION_H
#define EXCEPTION_H

namespace Mylib
{

class Exception
{
protected:

     char* m_message;  //当前异常信息
     char* m_location; //当前发生异常位置

public:

    Exception();
};



}

#endif // EXCEPTION_H
