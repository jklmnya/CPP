#include "assistFunc.h"
#include <vector>

int main() {

    vector<string> vec;
    char buf[10];
    clock_t startTime = clock();

    for (int i = 0;i<CSIZE;i++) {
        try {
            snprintf(buf, 10, "%d", rand());
            vec.push_back(string(buf));
        } catch (exception& e) {
            cout<<"std::bad_allocation"<<endl;
            abort();    // exit
        }
    }
    cout<<"time = "<<(clock() - startTime)<<endl;
    cout<<"vector.size() = "<<vec.size()<<endl;
    cout<<"vector.front() = "<<vec.front()<<endl;
    cout<<"vector.back() = "<<vec.back()<<endl;
    cout<<"vector.capacity() = "<<vec.capacity()<<endl;     // capacity 每次2倍扩容
    cout<<"vector.data() = "<<vec.data()<<endl;

    string target = get_a_target_string();
    startTime = clock();
    auto p = ::find(vec.begin(), vec.end(), target);    // find顺序搜索，返回iterator
    cout<<"find time = "<<(clock() - startTime)<<endl;

    if (p != vec.end()) { cout<<"found "<<*p<<endl; }
    else { cout<<"not found"<<endl; }

    startTime = clock();
    sort(vec.begin(), vec.end());
    string* sptr = (string*)bsearch(&target, vec.data(), CSIZE, sizeof(string), compareStrings);

    cout<<"sort + bs time = "<<(clock() - startTime)<<endl;
    if (sptr) {
        cout<<"found"<<endl;
    } else {
        cout<<"not found"<<endl;
    }
}