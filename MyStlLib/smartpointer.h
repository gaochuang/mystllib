#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H


namespace  MyLib
{

/*智能指针类*/
template <typename T>
class SmartPointer
{
protected:
        T *m_pointer;

public:
    SmartPointer(T* p= nullptr)
    {
        m_pointer = p;
    }

    //拷贝构造函数
    SmartPointer(const SmartPointer<T>& obj)
    {
        m_pointer = obj.m_pointer;

        const_cast<SmartPointer<T>&>(obj).m_pointer = nullptr;

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
            const_cast<SmartPointer<T> &>(obj).m_pointer = nullptr;
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
        return (nullptr == m_pointer);
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
