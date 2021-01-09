#ifndef __TEMPLATE__
#define __TEMPLATE__

// class template
template <typename T>
class Stone {
public:
    Stone(T weight = 0) : _weight(weight) { }
    int get_weight() const { return _weight; }

private:
    T _weight;
};

// function template
template <typename T>
T& min(T& a, T& b) {
    return a < b;
}

// member template
template <class T1, class T2>
struct pair {
public:
    pair() : first(T1()), second(T2()) { }
    pair(const T1& a, const T2& b) : first(a), second(b) { }

    // U1与T1, U2与T2有继承关系
    template <class U1, class U2>
    pair(const pair<U1, U2>& p) : first(p.first), second(p.second) { }

private:
    T1 first;
    T2 second;
};
#endif