#ifndef __A__
#define __A__

/**
 *  饿汉式
 **/

class A {

public:
    static A& get_instance();
    A(const A&) = delete;
    A& operator= (const A&) = delete;

private:
    A();
};

A& A::get_instance() {
    static A a;
    return a;
}

/**
 *  懒汉式
 **/
class B {

public:
    static B& get_instance() {
        return b;
    }
    B(const B&) = delete;
    B& operator= (const B&) = delete;
private:
    B();
    static B b;
};

#endif