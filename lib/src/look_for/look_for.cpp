#include <stdlib.h>
#include <iostream>
#include "../../include/parsing.h"

//pType_v : string, char, int, unsigned int, float, long


bool IGNORE_SPACE = false;

void display_result(std::vector<pType_v> result)
{
    std::cout << "========================" << std::endl;
    for (int i = 0; i < result.size(); i++) {
        if (result[i].index() == 0)
            std::cout << "string \"" << std::get<0>(result[i]) << "\""<< std::endl;
        if (result[i].index() == 1)
           std::cout << "char " << std::get<1>(result[i]) << std::endl;
        if (result[i].index() == 2)
           std::cout << "int " << std::get<2>(result[i]) << std::endl;
        if (result[i].index() == 3)
           std::cout << "unsigned " << std::get<3>(result[i]) << std::endl;
        if (result[i].index() == 4)
           std::cout << "float " << std::get<4>(result[i]) << std::endl;
        if (result[i].index() == 5)
           std::cout << "long " << std::get<5>(result[i]) << std::endl;
    }
    std::cout << "========================" << std::endl;
}

std::vector<pType_v> Parser::look_for(
const std::string &str, const std::string &pattern, bool save_split, bool ignore_space)
{
    IGNORE_SPACE = ignore_space;
    std::vector<pType_v> result;
    int index = 0;
    int error = 0;
    int start = 0;
    int p = 0;

    while (index < str.length()) {
        std::vector<pType_v> temp;
        start = index;
        for (p = 0; p < pattern.length(); p++) {
            if (p < pattern.length() - 1 && pattern[p] == '%' && is_flag(pattern[p + 1])) {
                error = get_pattern(pattern[p + 1], pattern[p + 2], str, index, &temp);
                if (error == -1) {
                    p = 0;
                    index = start + 1;
                    break;
                } else {
                    index = error;
                    if (pattern[p + 2] == '%')
                        index--;
                    p++;
                }
            } else {
                std::string temp_s;
                while (p < pattern.length() && index - 1 < str.length() && pattern[p] == str[index - 1]) {
                    printf("split %c\n", pattern[p]);
                    temp_s.push_back(str[index - 1]);
                    p++;
                    index++;
                }
                if (save_split)
                    temp.push_back(temp_s);
                if (pattern[p] != '%' && p < pattern.length()) {
                    index = start + 1;
                    p = 0;
                    error = -1;
                    break;
                } else {
                    p--;
                    index--;
                }
            }
        }
        if (error != -1) {
            if (str[index - 1] == pattern[p - 1] ||
                (pattern[pattern.length() - 2] == '%' && is_flag(pattern[pattern.length() - 1]))) {
                for (int x = 0; x < temp.size(); x++)
                    result.push_back(temp[x]);
                temp.clear();
                index--;
            } else {
                index = start + 1;
            }
        }
    }
    display_result(result);
    return (result);
}