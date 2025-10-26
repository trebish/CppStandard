#include <span>
#include <iostream>

template<class T, std::size_t N>
[[nodiscard]]
constexpr auto slide(std::span<T, N> s, std::size_t offset, std::size_t width)
{
    return s.subspan(offset, offset + width <= s.size() ? width : 0U);
}

void println(const auto& seq){
    for(const auto x: seq)
    {
        std::cout << x << ' ';
    }
    std::cout << std::endl;
}
int main(){
    constexpr int a[]{0, 1, 2, 3, 4, 5, 6, 7, 8};
    constexpr static std::size_t width{6};
        for (std::size_t offset{}; ; ++offset)
        if (auto s = slide(std::span{a}, offset, width); !s.empty())
            println(s);
        else
            break;
}