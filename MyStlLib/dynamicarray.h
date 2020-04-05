#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
#include"array.h"
#include"exception.h"
#include <iostream>

using namespace std;

namespace MyLib
{

template<typename T>
class DynamicArray:public Array<T>
{
protected:
     int m_length;
public:
    DynamicArray(int length)
    {
        this->m_array = new T[length];
        if(NULL != this->m_array)
        {
            this->m_length =length;
        }
        else
        {
            THROW_EXCEPTION(NoEnoughMemoryException,"not enougth memory......");
        }
    }

    DynamicArray(const DynamicArray<T>& obj)
    {
        this->Array = new T[obj.m_length];
        if(NULL != this->Array)
        {
            this->m_length = obj.m_length;
            for(int i=0;i<obj.m_length;i++)
            {
                this->Array[i]=obj.Array[i];
            }
        }
        else
        {
            THROW_EXCEPTION(NoEnoughMemoryException,"not enougth memory......");
        }

    }

    DynamicArray<T>& operator = (const DynamicArray<T>& obj)
    {
       if(this != &obj)
       {
            T* array = new T[obj.m_length];
            if(NULL != array)
            {
                for(int i=0;i<m_length;i++)
                {
                    array[i]=obj.m_array[i];
                }

                T* temp = this->m_array;
                this->m_array=array;
                this->m_length=obj.m_length;

                delete  []temp;
            }
            else
            {
                THROW_EXCEPTION(NoEnoughMemoryException,"not enougth memory......");
            }

       }
      return *this;
    }

      int length() const
      {
          return m_length;
      }


      void resize(int length)
      {
           if(this->m_length != length)
           {
               T* array = new T[length];
               if(NULL != array)
               {
                   int size = (length < m_length)?length:m_length;

                   for(int i=0;i<size;i++)
                   {
                       array[i]=this->m_array[i];
                   }

                   T* temp = this->m_array;
                   this->m_array = array;
                   this->m_length =length;

                   delete  []temp;
               }
               else
               {
                 THROW_EXCEPTION(NoEnoughMemoryException,"not enougth memory......");
               }

           }

      }

     ~DynamicArray()
      {
          delete  []this->m_array;
      }


};


}



#endif // DYNAMICARRAY_H
