#ifndef EXCEPTION_H
#define EXCEPTION_H
#include<cstdlib>
#include "object.h"

namespace  MyLib
{

//不支持异常时#define THROW_EXCEPTION(e,m)
#define THROW_EXCEPTION(e,m) (throw e(m,__FILE__,__LINE__))

class Exception : public Object
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

//算术异常类
class ArithmeticException : public Exception
{
public:
    ArithmeticException():Exception(NULL){}

    ArithmeticException(const char* message):Exception(message){};

    ArithmeticException(const char* file,int line):Exception(file,line){};

    ArithmeticException(const char* message,const char* file,int line):Exception(message,file,line){};

    ArithmeticException(const ArithmeticException& e):Exception(e){};

    ArithmeticException& operator=(const ArithmeticException& e)
    {
        Exception::operator=(e);
        return *this;
    }
    ~ArithmeticException();

};



//空指针异常类
class PointerException : public Exception
{
public:
    PointerException():Exception(NULL){}

    PointerException(const char* message):Exception(message){};

    PointerException(const char* file,int line):Exception(file,line){};

    PointerException(const char* message,const char* file,int line):Exception(message,file,line){};

    PointerException(const PointerException& e):Exception(e){};

    PointerException& operator=(const PointerException& e)
    {
        Exception::operator=(e);
        return *this;
    }
    ~PointerException();

};

//越界异常类
class IndexOutOfBoundsException : public Exception
{
public:
    IndexOutOfBoundsException():Exception(nullptr){}

    IndexOutOfBoundsException(const char* message):Exception(message){};

    IndexOutOfBoundsException(const char* file,int line):Exception(file,line){};

    IndexOutOfBoundsException(const char* message,const char* file,int line):Exception(message,file,line){};

    IndexOutOfBoundsException(const IndexOutOfBoundsException& e):Exception(e){};

    IndexOutOfBoundsException& operator=(const IndexOutOfBoundsException& e)
    {
        Exception::operator=(e);
        return *this;
    }
    ~IndexOutOfBoundsException();

};


//内存不足异常类
class NoEnoughMemoryException : public Exception
{
public:
    NoEnoughMemoryException():Exception(nullptr){}

    NoEnoughMemoryException(const char* message):Exception(message){};

    NoEnoughMemoryException(const char* file,int line):Exception(file,line){};

    NoEnoughMemoryException(const char* message,const char* file,int line):Exception(message,file,line){};

    NoEnoughMemoryException(const NoEnoughMemoryException& e):Exception(e){};

    NoEnoughMemoryException& operator=(const NoEnoughMemoryException& e)
    {
        Exception::operator=(e);
        return *this;
    }
    ~NoEnoughMemoryException();

};


//参数错误异常类
class InvalidParameterException : public Exception
{
public:
    InvalidParameterException():Exception(nullptr){}

    InvalidParameterException(const char* message):Exception(message){};

    InvalidParameterException(const char* file,int line):Exception(file,line){};

    InvalidParameterException(const char* message,const char* file,int line):Exception(message,file,line){};

    InvalidParameterException(const InvalidParameterException& e):Exception(e){};

    InvalidParameterException& operator=(const InvalidParameterException& e)
    {
        Exception::operator=(e);
        return *this;
    }
    ~InvalidParameterException();

};


//计算异常类
class InvalidOperatorException : public Exception
{
public:
    InvalidOperatorException():Exception(nullptr){}

    InvalidOperatorException(const char* message):Exception(message){};

    InvalidOperatorException(const char* file,int line):Exception(file,line){};

    InvalidOperatorException(const char* message,const char* file,int line):Exception(message,file,line){};

    InvalidOperatorException(const InvalidOperatorException& e):Exception(e){};

    InvalidOperatorException& operator=(const InvalidOperatorException& e)
    {
        Exception::operator=(e);
        return *this;
    }
    ~InvalidOperatorException();

};


};

#endif // EXCEPTION_H
