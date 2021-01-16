#ifndef __FINAL___
#define __FINAL___

struct Base final { };

// 被final修饰的类不能够被继承
// struct Child : public Base { };

struct Base1 {
    virtual void fun() final { }
};

struct Child1 : public Base1 {
    // cannot override 'final' function
    // virtual void fun() override { }
}; 

#endif