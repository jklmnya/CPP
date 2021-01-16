#ifndef __OVERRIDE___
#define __OVERRIDE___

class Base {
    virtual void func(int num) { }
};

class Child : public Base {
    virtual void func(float num) { }    // 不是override，而是重新定义了一个新的虚函数
    virtual void func(int num) override { } // 重写父类虚函数
    // member function declared with 'override' does not override a base class member
    // virtual void func(double num) override { }  
};

#endif