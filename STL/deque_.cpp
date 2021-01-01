#include "assistFunc.h"
#include <deque>

/**
 *  deque, 双向队列
 *  每个buffer是连续的，每次分配一个buffer
 **/ 

int main() {

    deque<string> deq;
    char buf[10];
    clock_t startTime = clock();

    for (int i = 0;i<CSIZE;i++) {
        try {
            snprintf(buf, 10, "%d", rand());
            deq.push_back(string(buf));
        } catch (exception& e) {
            cout<<"std::bad_allocation"<<endl;
            abort();    // exit
        }
    }
    cout<<"time = "<<(clock() - startTime)<<endl;
    cout<<"deque.size() = "<<deq.size()<<endl;
    cout<<"deque.front() = "<<deq.front()<<endl;
    cout<<"deque.back() = "<<deq.back()<<endl;
    
    string target = get_a_target_string();
    startTime = clock();
    auto p = ::find(deq.begin(), deq.end(), target);    // find顺序搜索，返回iterator
    cout<<"find time = "<<(clock() - startTime)<<endl;

    if (p != deq.end()) { cout<<"found "<<*p<<endl; }
    else { cout<<"not found"<<endl; }

    startTime = clock();
    sort(deq.begin(), deq.end());

}