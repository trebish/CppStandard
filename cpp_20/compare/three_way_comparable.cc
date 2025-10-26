#include <cassert>
#include <iostream>
#include <compare>

struct Point {
    int x;
    int y;
    auto operator<=>(const Point&) const = default;
};

int main() {
    Point p1{1,2}, p2{2,1}, p3{2,1};
    bool equal = (p1 == p2);
    bool less = (p1 < p2);
    std::cout << "equal == " << equal << std::endl;
    std::cout << "less == " << less << std::endl;

    std::cout << "equal == " << (p3 == p2) << std::endl;
    std::cout << "less == " << (p3 < p2) << std::endl;
}


/* output:
equal == 0
less == 1
equal == 1
less == 0
*/