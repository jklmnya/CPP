#include "assistFunc.h"
#include <queue>
#include <stack>

/**
 * stack, queue 底层都由deque实现
 **/

int main() {
    queue<int> q;
    stack<int> s;
    for (int i = 0;i<10;i++) {
        q.push(i);
        s.push(i);
    }
    for (int i = 0;i<10;i++) {
        cout<<"queue value = "<<q.front()<<endl;
        cout<<"stack value = "<<s.top()<<endl;
        q.pop();
        s.pop();
    }
}