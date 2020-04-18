#ifndef SEQLIST_H
#define SEQLIST_H
#include "list.h"
#include"exception.h"

namespace MyLib
{

template <typename T>
class Seqlist :public List<T>
{
protected:
    T* m_array;     //顺序存储空间
    int m_length;   //当前链表长度
public:
     bool insert(const T& e)
     {
         return insert(m_length,e);
     }
     bool insert(int i,const T& e)
     {
         bool ret=((0<=i)&&(i<=m_length));
         ret =ret& (m_length < capacity());

         if(ret)
         {
             for(int index=m_length-1;index>=i;index--)
             {
                m_array[index+1]=m_array[index];
             }

             m_array[i]=e;
             m_length++;
         }

        return ret;
      }

     bool remove(int i)
     {
         bool ret = (0<=i)&&(i<=m_length);

         if(ret)
         {
             for(int index=i;index<m_length-1; index++)
             {
                 m_array[index]=m_array[index+1];
             }
             m_length--;
         }
         return ret;
     }

     bool set(int i,const T& e)
     {
         bool ret = (0<=i)&&(i<m_length);
         if(ret)
         {
             m_array[i]=e;
         }

       return ret;
     }

     bool get(int i, T& e)const
     {
        bool ret = (0<=i)&&(i<=m_length);

        if(ret)
        {
            e = m_array[i];
        }
        else
        {
           THROW_EXCEPTION(IndexOutOfBoundsException,"parameter error .....");
        }

        return ret;
     }

     int find(const T& e) const
     {
        int ret = -1;
        for(int i=0;i<m_length;i++)
        {
            if(e == m_array[i])
            {
                ret = i;
                break;
            }
        }
        return ret;
     }
     int  length() const
     {
         return m_length;
     }

     void clear()
     {
        m_length=0;
     }
      //线性表访问
     T& operator[] (int i)
     {
         bool ret =(0<=i)&&(i<m_length);

         if(ret)
         {
              return m_array[i];
         }
         else
         {
            THROW_EXCEPTION(IndexOutOfBoundsException,"parameter error .....");
         }

     }

     T& operator[] (int i) const
     {
        return (const_cast<Seqlist<T>&>(*this))[i];
     }

     //顺序存储的容量
     virtual int capacity() const =0;

};


}

#endif // SEQLIST_H
