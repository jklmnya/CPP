#ifndef __TEST__
#define __TEST__

#include <iostream>
using namespace std;

class C {
public:
    C() { cout<<"Component"<<endl; }
};

class A {
public:
    A() { cout<<"Father"<<endl; }
};

class B : public A {
public:
    B() { cout<<"Child"<<endl; }

private:
    C c;
};

#endif