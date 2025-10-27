#include <print>
int  main() {
    constexpr auto fact = [](this const auto& self, int value) {
        if(value == 1)
        {
            return value;
        }
        else {
            // not allowed to call fact(value-1);
            return value * self(value-1);
        }
    };
    for(int i=1; i<10; ++i)
    {
        std::println("{}", fact(i));
    }
}

/* output:
1
2
6
24
120
720
5040
40320
362880
*/