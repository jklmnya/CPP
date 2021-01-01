/**
 *  泛化
 *  特化 ：根据提供的类型不同选择不同的构造器
 **/ 

struct __true_type {

};

struct __false_type {

};

template <typename T>
struct __traits {
    typedef __true_type         true_reason_one;
    typedef __false_type        false_reason_one;
    typedef __false_type        false_reason_two;
    typedef __false_type        false_reason_three;
    typedef __false_type        false_reason_four;
};

// 特化
template<> struct __traits<int> {
    typedef __false_type        false_reason_one;
    typedef __false_type        false_reason_two;
    typedef __false_type        false_reason_three;
    typedef __false_type        false_reason_four;
};

template<> struct __traits<float> {
    typedef __true_type         true_reason_one;
    typedef __false_type        false_reason_one;
};