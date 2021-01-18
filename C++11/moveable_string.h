#ifndef __MOVEABLE_STRING__
#define __MOVEABLE_STRING__

#include <iostream>
#include <string>

using namespace std;

class String {

public:
    // 构造函数
    String(const char* c) : _len(strlen(c)) {
        _init_data(c);
    }

    // 默认构造函数
    String() : _data(nullptr), _len(0) { }

    // 拷贝构造函数
    String(const String& str) : _len(str._len) {
        _init_data(str._data);
    }

    // 拷贝赋值函数，要先清除自身指针所指的内容
    String& operator=(const String& str) {
        // 判断是否是自身赋值
        if (&str != this) {
            if (_data) {
                delete _data;
            }
            _len = str._len;
            _init_data(str._data);
        }
        return *this;
    }

    // move constructor
    String(String&& str) noexcept : _data(str._data), _len(str._len) {
        // 只拷贝指针，注意将原来的指针置为nullptr
        str._len = 0;
        str._data = nullptr;    // important
    }

    // move assignment
    String& operator=(String&& str) noexcept {
        if (this != &str) {
            if (_data) { delete _data; }
            _data = str._data;
            _len = str._len;
            str._data = nullptr; // important
            str._len = 0;
        }
        return *this;
    }

    virtual ~String() {
        if (_data) {    // 判断是否为nullptr
            delete _data;
            _data = nullptr;
        }
    }

    char* get() const { return _data; }

    bool operator==(const String& str) { return string(_data) == string(str._data); }

    bool operator<(const String& str) { return string(_data) < string(str._data); }

private:
    char* _data;
    int _len;
    void _init_data(const char* c) {
        _data = new char[_len + 1];
        memcpy(_data, c, _len);
        _data[_len] = '\0';
    }
};

#endif