#include "assistFunc.h"
#include <array>

/**
 *      C++11 array一次性分配内存，不可动态增加
 **/

int main() {
    
    array<long, CSIZE> arr;
    for(auto& num : arr) { num = rand();}

    cout<<"array-size = "<<arr.size()<<endl;
    cout<<"array-front = "<<arr.front()<<endl;
    cout<<"array-back = "<<arr.back()<<endl;
    cout<<"array-data = "<<arr.data()<<endl; // array首元素地址
    
    long target = get_a_target_long();
    clock_t timeStart = clock();

    sort(arr.begin(), arr.end());
    long* findLong = (long*)bsearch(&target, (arr.data()), CSIZE, sizeof(long), compareLongs);

    cout<<"quickSort + binarySearch time = "<<(clock() - timeStart)<<endl;
    if (findLong) {
        cout<<"find "<<*(findLong)<<endl;
    } else {
        cout<<"not find"<<endl;
    }
}