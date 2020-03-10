#ifndef EXCEPTION_H
#define EXCEPTION_H

namespace  MyLib
{

class Exception
{
protected:

     char* m_message;  //当前异常信息
     char* m_location; //当前发生异常位

     void init(const char* message,const char* file,int line);

public:

    Exception(const char* message);
    Exception(const char* file,int line);
    Exception(const char* message,const char* file,int line);

    Exception(const Exception& e);
    Exception& operator = (const Exception& e);

    virtual const char* message() const;
    virtual const char* location() const;



    virtual ~Exception();
};



};

#endif // EXCEPTION_H
