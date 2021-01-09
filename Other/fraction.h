#ifndef __FRACTION__
#define __FRACTION__

/**
 *  fraction_1 f(3, 5);
 *  double d = 4 + f;   // 通过转换函数将fraction转换为0.6
 **/

class fraction_1 {
public:
    // non-explicit
    fraction_1(int numerator_ = 0, int denominator_ = 1) :
        numerator(numerator_), denominator(denominator_) { }

    int get_numerator() const { return numerator; }
    int get_denominator() const { return denominator; }

    // 转换函数
    operator double() const { return double(numerator / denominator); }
private:
    int numerator;
    int denominator;
};

/**
 *  fraction_2 f(3, 5);
 *  fraction_2 f = 4 + f;   // 4通过non-explicit转换为fraction_2，然后调用fraction_2中重载的+获得fraction_2对象
 **/
class fraction_2 {
public:
    // non-explicit，只需传递一个实参即可构造
    fraction_2(int numerator_, int denominator_ = 1) :
        numerator(numerator_), denominator(denominator_) { }

    int get_numerator() const { return numerator; }
    int get_denominator() const { return denominator; }

    fraction_2 operator + (const fraction_2& f) {
        return fraction_2(this->numerator + f.numerator, this->denominator);
    }
private:
    int numerator;
    int denominator;
};

/**
 *  fraction_3 f(3, 5);
 *  fraction_3 f = 4 + f;   // 编译不通过，因为有两种可能的路线（使用operator+ / 调用转换函数）
 **/
class fraction_3 {
public:
    // non-explicit，只需传递一个实参即可构造
    fraction_3(int numerator_, int denominator_ = 1) :
        numerator(numerator_), denominator(denominator_) { }

    int get_numerator() const { return numerator; }
    int get_denominator() const { return denominator; }

    fraction_3 operator + (const fraction_3& f) {
        return fraction_3(this->numerator + f.numerator, this->denominator);
    }

    // 转换函数
    operator double() const { return double(numerator / denominator); }
private:
    int numerator;
    int denominator;
};

/**
 *  fraction_4 f(3, 5);
 *  fraction_4 f = 4 + f;   // 失败double不能转换为fraction_4
 **/
class fraction_4 {
public:
    // explicit，不允许隐式转换
    explicit fraction_4(int numerator_, int denominator_ = 1) :
        numerator(numerator_), denominator(denominator_) { }

    int get_numerator() const { return numerator; }
    int get_denominator() const { return denominator; }

    // 转换函数
    operator double() const { return double(numerator / denominator); }

private:
    int numerator;
    int denominator;
};
#endif