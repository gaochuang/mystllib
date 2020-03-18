
//封装为了解决不同编译new不成功带来返回差异，提高可移植性
#ifndef OBJECT_H
#define OBJECT_H

namespace Mylib
{

class Object
{
public:
    void* operator new (unsigned long int size) throw();
    void operator delete (void* p);
    void* operator new[] (unsigned long int size) throw();
    void operator delete[] (void* p);
    bool operator == (const Object& obj);
    bool operator != (const Object& obj);
    virtual ~Object() = 0;
};

}

#endif // OBJECT_H

