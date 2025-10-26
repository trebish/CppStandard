#include <numeric>
#include <ranges>
#include <iostream>
#include <vector>

struct SimpleRange
{
    int* begin();
    int* end();
};
static_assert(std::ranges::range<SimpleRange>);

struct NotRange
{
    int t {};
};
static_assert(!std::ranges::range<NotRange>);

struct NotRange2
{
    void* being();
    int* end();
};
static_assert(!std::ranges::range<NotRange2>);

template <std::ranges::range Range>
void print_elements(Range v)
{
    for (auto x: v) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

int main() {
    constexpr size_t numberSize = 10;
    std::vector<int> numbers(numberSize);
    std::iota(numbers.begin(), numbers.end(), 0);
    print_elements(numbers);
    
}