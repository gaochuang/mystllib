#ifndef DYNAMICLIST_H
#define DYNAMICLIST_H

#include "seqlist.h"
#include "exception.h"

namespace MyLib
{

template <typename T>
class DynamicLisy :public Seqlist<T>
{

protected:
    int m_capacity; //顺序存储空间大家
public:
    DynamicLisy(int capacity)
    {
        this->m_array = new T[capacity];
        if(NULL != this->m_array)
        {
               this->m_length =0;
               this->m_capacity=capacity;
        }
        else
        {
            THROW_EXCEPTION(NoEnoughMemoryException,"not enougth memory");
        }

    }

    int capacity() const
    {
        return capacity();
    }

    //重新设置存储空间大小
    void resize(int capacity)
    {
         if(m_capacity != capacity)
         {

               T* array = new T[capacity];

               if(NULL != array)
               {
                    int length = (this->m_length < capacity ? this->m_length :capacity);
                     for(int i=0;i<length;i++)
                    {
                        array[i]=this->m_array[i];
                    }

                  T* temp = this->m_array;
                  this->m_array = array;
                  this->m_length = length;
                  this->m_capacity = capacity;

                  delete []temp;
               }
               else
               {
                   THROW_EXCEPTION(NoEnoughMemoryException,"No memory enougth to resize");
               }


         }
    }


    ~DynamicLisy()
    {
        delete []this->m_array;
    }

};



}



#endif // DYNAMICLIST_H
