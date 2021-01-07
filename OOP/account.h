#ifndef __ACCOUNT__
#define __ACCOUNT__

class account {

public:
    static double _rate;
    static void set_rate(const double& rate) {
        _rate = rate;
    }
};

// 定义_rate
double account::_rate = 8.0;

/**
 *    1. 通过Object::func 来使用static函数
 *    2. 通过具体对象来使用static函数
 *    account::set_rate(3.0);
 *    
 *    account a();
 *    a.set_rate(2.0);
 **/

#endif