#include "CoreMinial.h"

int main() {

    vector<int> vec = {1, 2, 3, 4, 5};

    // loop1
    vector<int>::iterator iter = vec.begin();
    for (;iter != vec.end();iter++) {
        cout<<*(iter)<<endl;
    }
    // .end() 指向容器中最后一个元素的后一个位置
    cout<<*(vec.end()); // 会得到奇奇怪怪的东西
    
    // C++11
    for (auto num : vec) { cout<<num<<endl; }

    // C++11 ref
    for (auto num : vec) { 
        num += 2;
        cout<<num<<endl; 
    }
}