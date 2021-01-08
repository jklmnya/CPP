#ifndef __SHAPE__
#define __SHAPE__

#include <iostream>

using namespace std;

class shape {

public:
    shape(int _id = 0) : id(_id) { }
    // 纯虚函数
    virtual void draw() = 0;
    // 虚函数
    virtual void print_error_msg() { cout<<"error message:"<<endl; }
    int getId() const { return this->id; }
    // template method
    void print_log() {
        cout<<"log start"<<endl;
        print_error_msg();
        cout<<"finished";
    }
private:
    int id;
};

class circle : public shape {
    // 子类必须重写父类的纯虚函数
    virtual void draw() {
        cout<<"circle draw"<<endl;
    }
    // override
    virtual void print_error_msg() {
        cout<<"circle error message:"<<endl;
    }
};

#endif