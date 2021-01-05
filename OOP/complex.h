#ifndef __COMPLEX__
#define __COMPLEX__

#include <iostream>
using namespace std;

class complex;

class complex {

public:

    complex(double re = 0, double im = 0) : _re(re), _im(im) { }
    // complex() : _re(0), _im(0) { } 和上一个重复，不能写 

    double real() const { return this->_re; }

    double imag() const { return this->_im; }

    complex& operator += (const complex& c);

    // 友元函数
    friend complex& __doapl(complex* ths, const complex& c);

    // 相同class的各个objects互为友元
    int func(const complex& c) { c._im + c._re; }
    
private:

    double _re, _im;

};

// friend友元函数，可以直接获取类中private变量
inline complex& __doapl(complex* ths, const complex& c) {
    ths->_im += c._im;
    ths->_re += c._re;
    return *ths;
}

inline complex& complex::operator += (const complex& c) {
    return __doapl(this, c);  
}

/**
 *      global function
 **/

// inline function
inline double imag(const complex& c) {
    return c.imag();
}

inline double real(const complex& c) {
    return c.real();
}

/**
 *  一定返回complex（值），因为return complex()是临时对象
 *  操作符重载
 **/

inline complex operator + (const complex& c1, const complex& c2) {
    return complex(real(c1) + real(c2), 
                   imag(c1) + imag(c2));
}

inline complex operator + (const complex& c, double _real) {
    return complex(_real + real(c), imag(c));
}

inline complex operator + (const complex& c) {
    return c;
}

inline complex operator - (const complex& c) {
    return complex(-real(c), -imag(c));
}

inline bool operator == (const complex& c1, const complex& c2) {
    return (real(c1) == real(c2) &&
            imag(c1) == imag(c2));
}

inline bool operator == (const complex& c, double _real) {
    return (imag(c) == 0 && real(c) == _real);
}

inline bool operator != (const complex& c1, const complex& c2) {
    return (real(c1) != real(c2) ||
            imag(c1) != imag(c2));
}

inline bool operator != (const complex& c, double _real) {
    return (imag(c) != 0 || real(c) != _real);
}

inline complex conj(const complex& c) {
    return complex(real(c), -imag(c));
}

ostream& operator << (ostream& os, const complex& c) {
    return os <<"("<<real(c)<<","<<imag(c)<<","<<endl;
}

#endif