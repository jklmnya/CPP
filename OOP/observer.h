#ifndef __OBSERVER__
#define __OBSERVER__

#include <vector>
using namespace std;

class observer {
public:
    virtual void update(subject* sub, int _data) = 0;
};

class subject {
public:
    subject(int _data = 0) : data(_data) { };
    int getData() const { return this->data; }
    void setDate(int _data) { this->data = _data; }
    void attach(observer* obs) { obs_list.push_back(obs); }
    void notify() {
        for (auto& obs : obs_list) {
            obs->update(this, data);
        }
    }
private:
    int data;
    vector<observer*> obs_list;
};

#endif