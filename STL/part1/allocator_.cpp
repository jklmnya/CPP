#include <iostream>

using namespace std;

int main() {
    allocator<int> alloc;
    int* p;
    alloc.allocate(1);
    alloc.deallocate(p, 1);
}