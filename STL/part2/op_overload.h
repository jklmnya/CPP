/**
 * 操作符重载
 * ++i， i++等
 * 
 * C++ 中不允许i++++，但允许++++i（重载是写法不同）
 **/ 

class student {

public:

    student(int age = 0, int number = 0) 
        : _age(age), _number(number) { }

    // prefix ++
    int& operator++() {
        this->_age += 2;
        return this->_age;
    } 

    // post ++
    int operator++(int) {
        this->_age += 2;
        return this->_age;
    }

    int getAge() const {
        return this->_age;
    }

private:

    int _age;
    int _number;

};