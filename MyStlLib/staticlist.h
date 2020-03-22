#ifndef STATICLIST_H
#define STATICLIST_H
#include"seqlist.h"

namespace MyLib
{

template<typename  T,int N>
class Staticlist:public Seqlist<T>
{
protected:
        T m_space[N];
public:
    Staticlist();
    int capacity()const;
};



template<typename  T,int N>
Staticlist<T,N>::Staticlist()
{
   this->m_array= m_space;
   this->m_length=0;

}

template < typename T, int N >

int Staticlist<T, N>::capacity() const
{
    return N;
}
}

#endif // STATICLIST_H
