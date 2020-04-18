#ifndef LINKLIST_H
#define LINKLIST_H
#include"object.h"
#include"exception.h"
#include"list.h"

namespace MyLib
{

template <typename T>
class LinkList : public List<T>
{
protected:
    struct Node:public Object
    {
      T value;
      Node* next;
    };

    Node m_header;
    int m_length;
public:
    LinkList()
    {
        m_header.next = NULL;
        m_length=0;
    }

    bool insert(const T& e)
    {
        return insert(m_length,e);
    }

     bool insert(int i,const T& e)
     {
        bool ret = (0<=i)&&(i<=m_length);
        if(ret)
        {
           Node* node = new  Node();
           if(NULL != node)
           {
                Node* current = &m_header;

                for(int p=0;p<i;p++)
                {
                    current = current->next;
                }

                node->value =e;
                node->next=current->next;
                current->next = node;
                m_length++;
           }
           else
           {
               THROW_EXCEPTION(NoEnoughMemoryException,"not enough memory create Node......");
           }


        }

     }

     bool remove(int i)
     {
        bool ret = (0<=i)&&(i<=m_length);
        if(ret)
        {
            Node* current = &m_header;
            for(int p=0;p<i;p++)
            {
                current=current->next;
            }
            Node* toDel = current->next;

            current =toDel->next;

            delete toDel;

        }

        return ret;

     }

     bool set(int i,const T& e)
     {
         bool ret = (0<=i)&&(i<=m_length);
         if(ret)
         {
             Node* current = &m_header;
             for(int p=0;p<i;p++)
             {
                 current = current->next;
             }

             current->value=e;
         }
         return ret;
     }
     bool get(int i, T& e)const
     {
         bool ret = (0<=i)&&(i<=m_length);

         if(ret)
         {
            Node* current = &m_header;
            for(int p=0;p<i;p++)
            {
                current=current->next;
            }

            e=current->value;
         }

         return ret;
     }
     int find(const T& e)
     {
         int ret =-1;
         int i =0;
         Node* node =m_header.next;
         while(node)
         {
             if(node->value == e)
             {
                 ret =i;
                 break;
             }
             else
             {
                 node=node->next;
                 i++;
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
         while(m_header.next)
         {
            Node* toDel = m_header.next;

            m_header.next =toDel;

            delete  toDel;

         }

         m_length=0;
     }


};



}

#endif // LINKLIST_H
