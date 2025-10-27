#include <ranges>
#include <vector>
#include <string>
#include <iostream>

int main() {
    std::vector<std::string> dates{"2023-01", "2023-02", "2023-03"};
    std::vector<std::string> products{"Shoes", "Pants","hat"};
    std::vector<double> sales{50.0, 30.0, 60.0};

    // Will only print if a value is found in all 3 containers.
    for (auto&& [date, product, sale] : std::views::zip(dates, products, sales)) {
        std::cout << date << ": " << product << " - " << sale << '\n';
    }
}


/* output:
2023-01: Shoes - 50
2023-02: Pants - 30
2023-03: hat - 60
*/