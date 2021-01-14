#ifndef __DEFAULT__DELETE__
#define __DEFAULT__DELETE__

class Foo {

public:
    Foo(int a) : _a(a) { }  // 重载构造函数
    Foo() = default;        // 可以与上一个构造函数并存
    Foo(const Foo& f) : _a(f._a) { }    // 拷贝构造函数
    // Foo(const Foo& f) = default;    // error,已定义过拷贝构造函数，不能重新定义
    // Foo(const Foo& f) = delete;     // error

    Foo& operator= (const Foo& f) {    // 拷贝赋值函数
        _a = f._a;
        return *this;
    }
    // Foo& operator= (const Foo& f) = default; // error
    // Foo& operator= (const Foo& f) = delete;  // error

    // void fun1() = default; // '= default' can only appear on default constructors, copy/move constructors, copy/move assignment operators, and destructors
    void fun2() = delete;   // ok

    // ~Foo() = delete;     // error
    ~Foo() = default;   // ok
private:
    int _a;
};

#endif