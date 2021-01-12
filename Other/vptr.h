#ifndef __VPTR__
#define __VPTR__

/**
 * sizeof(A) = 16 = 2*4 + 8
 * 8 -> vptr
 **/

class A {
public:
    virtual void vfun1() { }
    virtual void vfun2() { }
    void fun1() { }
    void fun2() { }

private:
    int data1, data2;
};


class B : public A {
public:
    virtual void vfun1() { }    // 重写A的vfun1
    void fun1() { } // B自己的fun1(),与A的不同

private:
    int data1;      // B自己的data1，与A的data1不同
};


#endif