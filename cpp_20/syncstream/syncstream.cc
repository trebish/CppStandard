#include <iostream>
#include <syncstream>

int main() {
    std::osyncstream a(std::cout);
    a << "Welcome";
    a.flush();
    a << std::endl;
}