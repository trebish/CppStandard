#include <flat_map>
#include <string>
#include <iostream>

int main() {
    std::flat_map<int, std::string> fm{ {1,"one"},{2,"two"},{3,"three"}};
    for (auto[k, v]: fm) {
        std::cout << "Key: " << k << ", value:" << v << std::endl;
    }
    std::vector<std::string> values = fm.values();
    std::vector<int> key = fm.keys();
    std::less<int> compare = fm.key_comp();
}