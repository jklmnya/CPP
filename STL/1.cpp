#include <iostream>
#include <forward_list>

using namespace std;

int main() {
    forward_list<int> fl;
    for (int i = 0;i<10;i++) { fl.push_front(i); }
    for (auto& num : fl) { cout<<num<<endl; }
}