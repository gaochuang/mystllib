#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H
#include<cstdlib>
#include"object.h"

namespace  MyLib
{

/*智能指针类*/
template <typename T>
class SmartPointer : public Object
{
protected:
        T *m_pointer;

public:
    SmartPointer(T* p= NULL)
    {
        m_pointer = p;
    }

    //拷贝构造函数
    SmartPointer(const SmartPointer<T>& obj)
    {
        m_pointer = obj.m_pointer;

        const_cast<SmartPointer<T>&>(obj).m_pointer = NULL;

    }

    //赋值构造函数
    SmartPointer<T> operator = (const SmartPointer<T>& obj)
    {
         //防止自赋值
        if(this != obj.m_pointer)
        {
            //释放自己堆空间
            delete  m_pointer;
            m_pointer = obj.m_pointer;
            const_cast<SmartPointer<T> &>(obj).m_pointer = NULL;
        }

        //返回自己为了方便连续赋值
        return *this;

    }

    T* operator ->()
    {
        return m_pointer;
    }

    T operator *()
    {
        return *m_pointer;
    }

    bool isNull()
    {
        return (NULL == m_pointer);
    }

    ~SmartPointer()
    {
        if(m_pointer)
        {
            delete m_pointer;
        }
    }



};

}

#endif // SMARTPOINTER_H
