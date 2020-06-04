#include <string>
#include <variant>
#include <iostream>
#include "header.h"

int main(int argc, char const *argv[])
{
    const std::string test = "thisisiss olis a simple test of llloisooollllisi";

    const std::vector<std::string> o = {"isiss ol"};
    Parser p;
    std::vector<std::string> lol = p.split_word(test, o);
    for (int i = 0; i < lol.size(); i++)
        std::cout << lol[i] << "\n";

    std::vector<std::variant<int, std::string>> var;
    int val = std::stoi(" \t3");
    var.push_back(val);
    var.push_back("yes");

    for (int i = 0; i < var.size(); i++) {
        if (var[i].index() == 0) {
            printf("Int %d\n", std::get<0>(var[i]));
        }
        if (var[i].index() == 1) {
            printf("string %s\n", std::get<1>(var[i]).c_str());
        }
    }
    return 0;
}