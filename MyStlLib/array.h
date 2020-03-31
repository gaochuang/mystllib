#ifndef ARRAY_H
#define ARRAY_H
#include"object.h"
#include"exception.h"

namespace MyLib
{

template <typename T>
class Array : public Object
{
protected:
    T *array;
public:
    virtual bool set(int i,const T& e)
    {
        bool ret = ((i>=0)&&(i<length()));
        if(ret)
        {
            array[i]=e;
        }

        return ret;
    }

    virtual bool get(int i,const T& e)
    {
        bool ret = ((i>=0)&&(i<length()));
        if(ret)
        {
            e=array[i];
        }

        return ret;
    }

    T& operator[](int i)
    {
        if((0<=i)&&(i<length()))
        {
            return array[i];
        }
        else
        {
            THROW_EXCEPTION(IndexOutOfBoundsException,"parameter is invaild....");
        }
    }

    T& operator[](int i)const
    {
        return (const_cast<Array<T>&>(*this))[i];
    }



    virtual int length() const =0;

};




}


#endif // ARRAY_H
