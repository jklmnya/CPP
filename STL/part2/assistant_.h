#include <iostream>

using namespace std;

// 函数模版，内联函数
template <typename T>
inline
const T& getMin(const T& a, const T& b) {
    // 编译器推测出T的类型，并检查T中是否实现重载了<
    return b < a ? b : a;
}


class stone {
public:
    stone(int len = 0, int wi = 0) : _len(len) , _wi(wi) {
        _weight = _len*_wi;
    }

    // < 操作符重载 
    bool operator< (const stone& _astone) const {
        return _weight < _astone._weight;
    }

    int getWeight() const {
        return _weight;
    }

private:
    int _len, _wi, _weight;
};