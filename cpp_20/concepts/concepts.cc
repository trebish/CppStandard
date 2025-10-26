#include <concepts>
#include <iostream>
#include <functional>

template <typename T>
requires std::invocable<T&, int>
void printVec(const std::vector<int>& vec, T fn) {
    for(auto& x: vec) {
        std::cout << fn(x) << std::endl;
    }
}


int main() {
    std::vector<int> vec{1,2,3,4,5,6,7,8,9,10};
    printVec(vec, [](int x) {return x*x;});
}

/* output:
1
4
9
16
25
36
49
64
81
100
*/