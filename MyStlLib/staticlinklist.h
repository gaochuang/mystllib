#ifndef STATICLINKLIST_H
#define STATICLINKLIST_H
#include"linklist.h"

namespace MyLib
{

template<typename  T,int N>
class StaticLinkList: public LinkList<T>
{
protected:
    //使用LinkList的Node需要指明作用域，但是导致编译器不知道代表的类型还是静态成员变量，需要加上typename表示泛指类型
    typedef typename LinkList<T>::Node Node;
    struct SNode : public Node
     {
        void* operator new(unsigned long size,void* p_loc)
        {
            (void)size;
            return p_loc;
        }
     };

    unsigned char m_space[sizeof(SNode)*N];
    int m_used[N];
    Node* create()
    {
        SNode* ret = NULL;

        for(int i = 0; i < N; i++ )
        {
            if(!m_used[i])
            {
                 ret = reinterpret_cast<SNode*>(m_space) + i;//分配空间，强转后进行指针操作
                 ret = new(ret)SNode();//重载new，类类型在ret处调用构造函数创建对象，在ret处申请SNode大的空间。
                 m_used[i] = 1;//标记空间已用
                 break;
            }
         }
         return ret;
    }

void destroy(SNode* p_n)
{
    SNode* space = reinterpret_cast<SNode*>(m_space);
    SNode* psn = dynamic_cast<SNode*>(p_n);//父类指针转换成子类指针
    for(int i = 0; i < N; i++)
    {
        if( psn == (space + i) )
        {
            m_used[i] = 0;//标记可用
            psn->~SNode();//调用析构函数归还空间，Node类里的T为类类型时就可以调用析构函数
        }
}


}

public:
    StaticLinkList()
    {
        for(int i=0;i<N;i++)
        {
            m_used[i]=0;
        }
    }
    int capacity()
    {
        return N;
    }

};





}

#endif // STATICLINKLIST_H
