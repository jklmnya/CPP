#ifndef __DYNAMIC_BINGING__
#define __DYNAMIC_BINGING__

#include <iostream>

using namespace std;

/**
 * MyDoc md;
 * md.openFile();  // Document::openFile(&md);, 调用父类的函数，默认传递this指针
 * openFile() - this->serilize() - (*(this->vptr)[n])(this)
 *  首先通过调用this->serilize()来调用子类的函数（通过动态绑定完成）
 **/

class Document {
public:
    virtual void serilize() { }
    void openFile() {
        // step1
        serilize();
        // step3
        // .....
    }
};

class MyDoc : public Document {
public:
    virtual void serilize() { 
        cout<<"step2";
    }
};

#endif