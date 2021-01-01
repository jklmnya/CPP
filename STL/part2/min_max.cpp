#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool comp(const string& a, const string& b);

int main() {
    string a = "hello";
    string b = "woo";
    // 1
    cout<<max(a, b)<<endl;
    // compare by length
    cout<<max(a, b, comp);
}

bool comp(const string& a, const string& b) {
    return a.size() < b.size();
}