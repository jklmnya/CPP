#ifndef __VARIADIC_TEMPLATE__
#define __VARIADIC_TEMPLATE__

#include <iostream>

using namespace std;

void _print() { }   // 递归终止条件

template<typename T, typename... Types> //typename... Types
void _print(const T& first, const Types&... args) {
    cout << first << endl;
    _print(args...);
}

#endif