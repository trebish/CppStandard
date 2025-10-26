#include <ranges>
#include <vector>
#include <string>
#include <iostream>

int main() {
    std::vector<std::string> dates{"2023-01", "2023-02"};
    std::vector<std::string> products{"Shoes", "Pants"};
    std::vector<double> sales{50.0, 30.0};

    for (auto&& [date, product, sale] : std::views::zip(dates, products, sales)) {
        std::cout << date << ": " << product << " - " << sale << '\n';
    }
}


/* output:
2023-01: Shoes - 50
2023-02: Pants - 30
*/