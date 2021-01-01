#include <iostream>

using namespace std;

#define Pi 3.14

typedef struct Tongji_University {
    Tongji_University(int build_time = 0, int student_number = 0) :
        _build_time(build_time), _student_number(student_number) {}
    int _build_time;
    int _student_number;

    int getBuildTime() { 
        return _build_time;
    }
} TU;

int main() {
    float r = 10.0f;
    cout<<"Area = "<<(2*Pi*r)<<endl;

    TU t1(1991, 10000);
    cout<<t1.getBuildTime();
}