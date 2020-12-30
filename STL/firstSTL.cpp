#include "CoreMinial.h"

int main() {

    int array[6] = {27, 210, 12, 47, 109, 83};
    vector<int, allocator<int>> vec(array, array + 6);

    cout<<count_if(vec.begin(), vec.end(), not1(
            bind2nd(less<int>(), 40)
    ));

}