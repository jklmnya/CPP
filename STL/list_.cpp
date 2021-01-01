#include "assistFunc.h"
#include <list>

/**
 *  list 双向链表, 动态分配
 *  push_back() 空间中寻找一个位置存放
 **/ 

int main() {
    list<string> lis;
    char buf[10];
    clock_t startTime = clock();

    for (int i = 0;i<CSIZE;i++) {
        try {
            snprintf(buf, 10, "%d", rand());
            lis.push_back(string(buf));
        } catch (exception& e) {
            cout<<e.what()<<endl;
            abort();    // exit
        }
    }
    cout<<"time = "<<(clock() - startTime)<<endl;
    cout<<"list.size() = "<<lis.size()<<endl;
    cout<<"list.max_size() = "<<lis.max_size()<<endl;
    cout<<"list.back() = "<<lis.back()<<endl;
    cout<<"list.front() = "<<lis.front()<<endl;

    string target = get_a_target_string();
    startTime = clock();
    auto p = ::find(lis.begin(), lis.end(), target);    // find顺序搜索，返回iterator
    cout<<"find time = "<<(clock() - startTime)<<endl;

    if (p != lis.end()) { cout<<"found "<<*p<<endl; }
    else { cout<<"not found"<<endl; }

    startTime = clock();
    // sort(lis.begin(), lis.end());
    lis.sort(); // 自带sort()
    cout<<"sort time = "<<(clock() - startTime)<<endl;
}