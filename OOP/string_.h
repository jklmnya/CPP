#ifndef __STRING__
#define __STRING__

#include <cstring>

class String {

public:

    String(const char* cstr = 0);
    String(const String& str);                  // 拷贝构造函数
    String& operator = (const String& str);     // 拷贝赋值函数
    ~String();                                  // 析构函数

    char* get_c_str() const { return m_data; }

private:

    char* m_data;
};


inline String::String(const char* cstr = 0) {
    if (cstr) {
        m_data = new char[strlen(cstr) + 1];
        strcpy(m_data, cstr);
    } else {
        m_data = new char[1];
        *m_data = '\0';
    }
}

inline String::~String() {
    delete[] m_data;
    m_data = nullptr;
}

// 拷贝构造函数
// 深拷贝，拷贝内容
inline String::String(const String& str) {
    m_data = new char[strlen(str.m_data) + 1];
    strcpy(m_data, str.m_data);
}

// 拷贝赋值函数
// s1 = s2
inline String& String::operator = (const String& str) {
    // 判断是否是自我赋值, s1 = s1(若不判断，此操作会出错)
    if (this == &str) { return *this; }
    // 1.先清除自身内容
    delete[] m_data;
    // 2.申请空间
    m_data = new char[strlen(str.m_data) + 1];
    // 3.深拷贝
    strcpy(m_data, str.m_data);
    return *this;
}

/**
 *   global function
 **/ 
#include <iostream>
using namespace std;

ostream& operator << (ostream& os, const String& str) {
    os << str.get_c_str();
    return os;
}

#endif