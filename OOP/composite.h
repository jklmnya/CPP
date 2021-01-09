#ifndef __COMPOSITE__
#define __COMPOSITE__

/**
 *  Delegation + Inheritance
 **/

#include <vector>
using namespace std;

class Base {
public:
    Base(int _id) : id(_id) { }
    virtual void add(Base* base) { }
private:
    int id;
};

class File : public Base {
public:
    File(int _id) : Base(_id) { }
};

class Folder : public Base {
public:
    Folder(int _id) : Base(_id) { }
    void add(Base* base) { file_list.push_back(base); }

private:
    vector<Base*> file_list;
};

#endif