#include "assistant_.h"

int main() {
    stone a(3, 3), b(4, 4), c;
    c = getMin(a, b);
    cout<<c.getWeight();
}


