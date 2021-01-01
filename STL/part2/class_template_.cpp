#include <iostream>

using namespace std;

template <typename T>
class complex {

public:
    // 构造函数，默认r，m = 0
    complex(T r = 0, T m = 0) : re(r), im(m) {

    }

    T getRe() const { return re; }
    T getIm() const { return im; }
    
private:
    T re, im;
};

int main() {
    complex<int> com(2, 3);
    cout<<com.getIm();
}