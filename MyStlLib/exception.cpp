#include "exception.h"
#include <cstring>
#include <cstdlib>
#include <stdio.h>

using namespace std;

//异常类
namespace  MyLib
{

void Exception::init(const char* message,const char* file,int line)
{
    char temp[16] = {0};

    if(NULL != file && NULL != message )
    {
        m_message = strdup(message);
        snprintf(temp,sizeof(temp),"%d",line);
        //异常位置（文件名：行号）
        m_location = static_cast<char*>(malloc(strlen(m_message) + strlen(temp) +2));
        m_location = strcpy(m_location,file);
        m_location = strcat(m_location,":");
        m_location = strcat(m_location,temp);
    }
    else
    {
        m_location = NULL;
        m_message = NULL;
    }
}

Exception::Exception(const char* message)
{
    init(message,NULL,0);
}

Exception::Exception(const char* file,int line)
{
    init(NULL,file,line);
}

Exception::Exception(const char* message,const char* file,int line)
{
    init(message,file,line);
}


Exception::Exception(const Exception& e)
{
    m_location = strdup(e.m_location);
    m_message = strdup(e.m_message);
}

Exception& Exception::operator = (const Exception& e)
{
    if(this != &e)
    {
         free(m_message);
         free(m_location);

         m_location = strdup(e.m_location);
         m_message = strdup(e.m_message);
    }

    return *this;
}

const char* Exception::message() const
{
    return m_message;
}

const char* Exception::location() const
{
    return m_location;
}

Exception::~Exception()
{
    free(m_message);
    free(m_location);

    m_message =NULL;
    m_location = NULL;
}

}

