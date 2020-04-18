#ifndef LIST_H
#define LIST_H
#include "object.h"


namespace MyLib
{
//线性表类
template <typename T>
class List : public Object
{
protected:
       //禁用拷贝构造和赋值构造
       List(const List& obj);
       List& operator= (const List& obj);
public:
     List(){};
    virtual bool insert(const T& e)=0;
    virtual bool insert(int i,const T& e) =0;
    virtual bool remove(int i) =0;
    virtual bool set(int i,const T& e)=0;
    virtual bool get(int i, T& e)const =0;
     virtual int find(const T& e) const =0;
    virtual int  length() const =0;
    virtual void clear() =0;
};



}

#endif // LIST_H
