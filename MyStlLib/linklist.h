#ifndef LINKLIST_H
#define LINKLIST_H

#include "list.h"
#include "object.h"
#include "exception.h"

namespace MyLib
{

template < typename T >
class LinkList : public List<T>
{
protected:
    struct Node : public Object
    {
        T m_value;
        Node* m_next;
    };



    mutable struct : public Object
    {
        char m_reservered[sizeof (T)];
        Node* m_next;
    } m_header;

    int m_length;
    int m_step;
    Node* m_current;

    Node* position(int i) const
    {
        Node* current = reinterpret_cast<Node*>(&m_header);

        for(int p=0; p<i; p++)
        {
            current = current->m_next;
        }

        return current;
    }

    virtual Node* create()
    {
        return new Node();
    }

    virtual void destroy(Node* pn)
    {
        delete pn;
    }

public:
    LinkList();
    virtual bool insert(const T& e);
    virtual bool insert(int i, const T& e);
    virtual bool remove(int i);
    virtual bool set(int i, const T& e);
    virtual bool get(int i, T& e) const;
    virtual T get(int i) const;
    virtual int length() const;
    virtual void clear();
    virtual int find(const T& e) const;
    ~LinkList();
    virtual bool move(int i, int step = 1);
    virtual bool end();
    virtual T current();
    virtual bool next();
};

template < typename T >
LinkList<T>::LinkList()
{
    m_header.m_next = nullptr;
    m_length = 0;
    m_step = 1;
    m_current = nullptr;
}

template < typename T >
bool LinkList<T>::move(int i, int step)
{
    bool ret = ((0 <= i) && (i < m_length) && (step > 0));

    if( ret )
    {
        Node* current = position(i);
        m_current = current->m_next;
        m_step = step;
    }

    return ret;
}

template < typename T >
bool LinkList<T>::end()
{
    return (m_current == nullptr);
}

template < typename T >
T LinkList<T>::current()
{
    if (!end())
    {
        return m_current->m_value;
    }
    else
    {
        THROW_EXCEPTION(, "No value at current position...");
    }
}

template < typename T >
bool LinkList<T>::next()
{
    int i = 0;

    while ((i < m_step) && !end())
    {
        m_current = m_current->m_next;
        i++;
    }

    return (i == m_step);
}

template < typename T >
bool LinkList<T>::insert(const T& e)
{
    return insert(m_length, e);
}

template < typename T >
bool LinkList<T>::insert(int i, const T& e)
{
    bool ret = ((0 <= i) && (i <= m_length));
    if( ret )
    {
        Node* node = create();
        if( node )
        {
            Node* current = position(i);

            node->m_value = e;
            node->m_next = current->m_next;
            current->m_next = node;

            m_length++;
        }
        else
        {
            THROW_EXCEPTION(NoEnoughMemoryException, "No memory to insert new element ...");
        }
    }
    else
    {
        THROW_EXCEPTION(IndexOutOfBoundsException, "Parameter i is invalid...");
    }


    return ret;
}

template < typename T >
bool LinkList<T>::remove(int i)
{
    bool ret = ((0 <= i) && (i < m_length));
    if( ret )
    {
        Node* current = position(i);

        Node* toDel = current->m_next;

        if(m_current == toDel)
        {
            m_current = toDel->m_next;
        }

        current->m_next = toDel->m_next;
        m_length--;

        this->destroy(toDel);
    }
    else
    {
        THROW_EXCEPTION(IndexOutOfBoundsException, "Parameter i is invalid...");
    }

    return ret;
}

template < typename T >
bool LinkList<T>::set(int i, const T& e)
{
    bool ret = ((0 <= i) && (i < m_length));

    if( ret )
    {
        Node* current = position(i);

        Node* toSet = current->m_next;
        toSet->m_value = e;
    }
    else
    {
        THROW_EXCEPTION(IndexOutOfBoundsException, "Parameter i is invalid...");
    }

    return ret;
}

template < typename T >
bool LinkList<T>::get(int i, T& e) const
{
    bool ret = ((0 <= i) && (i < m_length));

    if( ret )
    {
        Node* current = position(i);

        Node* toGet = current->m_next;

        e = toGet->m_value;
    }
    else
    {
        THROW_EXCEPTION(IndexOutOfBoundsException, "Parameter i is invalid...");
    }

    return ret;
}

template < typename T >
T LinkList<T>::get(int i) const
{
    T ret;
    get(i, ret);
    return ret;
}

template < typename T >
int LinkList<T>::length() const
{
    return m_length;
}

template < typename T >
void LinkList<T>::clear()
{
    while( m_header.m_next )
    {
         remove(0);
    }
}

template < typename T >
LinkList<T>::~LinkList()
{
     clear();
}

template<typename T>
int LinkList<T>::find(const T& e) const
{
    int ret = -1;
    int i = 0;
    Node* node = m_header.m_next;
    while (node)
    {
        if(node->m_value == e)
        {
            ret = i;
            break;
        }

        i++;
        node = node->m_next;
    }

    return ret;
}


}




#endif // LINKLIST_H
