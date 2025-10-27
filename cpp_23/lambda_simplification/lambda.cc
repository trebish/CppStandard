#include <format>
#include <utility>
#include <print>

int main() {
    auto lambda = [i = 0, j = 1] mutable
    {
        i = std::exchange(j,i+j);
        return i;
    };
    for(int i=0; i< 20; ++i)
    {
        std::println("{:d}", lambda());
    }
    return lambda();
}