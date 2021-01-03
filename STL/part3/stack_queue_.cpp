#include <vector>
#include <queue>
#include <stack>
#include <list>

#include <iostream>

using namespace std;

int main() {
    stack<int> s;   // 默认底部容器deque<int>
    queue<int> q;   // 默认底部容器deque<int>

    stack<int, list<int>> s1;   // ok
    queue<int, list<int>> q1;   // ok

    stack<int, vector<int>> s2; // ok， vector.push_back(), vector.pop_back()
    queue<int, vector<int>> q2; // compile ok
    // q2.push();                  // not ok, vector has no function push_front()
}