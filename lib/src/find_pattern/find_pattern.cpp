#include <stdlib.h>
#include <iostream>
#include "../../include/parsing.h"

//pType_v : string, char, int, unsigned int, float, long

void display_result(std::vector<std::vector<pType_v>> result)
{
    std::cout << "========================" << std::endl;
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            if (result[i][j].index() == 0)
                std::cout << "string \"" << std::get<0>(result[i][j]) << "\" ";
            if (result[i][j].index() == 1)
               std::cout << "char " << std::get<1>(result[i][j]) << " ";
            if (result[i][j].index() == 2)
               std::cout << "int " << std::get<2>(result[i][j]) << " ";
            if (result[i][j].index() == 3)
               std::cout << "unsigned " << std::get<3>(result[i][j]) << " ";
            if (result[i][j].index() == 4)
               std::cout << "float " << std::get<4>(result[i][j]) << " ";
            if (result[i][j].index() == 5)
               std::cout << "long " << std::get<5>(result[i][j]) << " ";
       }
       std::cout << std::endl;
    }
    std::cout << "========================" << std::endl;
}

std::vector<std::vector<pType_v>> Parser::find_pattern(
const std::string &str, const std::string &pattern, bool save_split)
{
    Parser::pSave_split = save_split;
    std::vector<std::vector<pType_v>> result;
    int index = 0;
    int error = 0;
    int start = 0;
    int p = 0;

    if (pattern.length() == 0 || str.length() == 0)
        return (result);
    while (index < str.length()) {
        std::vector<pType_v> temp;
        start = index;
        std::string stops;
        for (p = 0; p < pattern.length(); p++) {
            if (p < pattern.length() - 1 && pattern[p] == '%' && is_flag(pattern[p + 1])) {
                if (pattern[p + 1] == 'S') {
                    int i = 0;
                    for (i = 0; pattern[p + 3 + i] != ']'; i++)
                        stops.push_back(pattern[p + 3 + i]);
                    error = get_complex_string(stops, str, index, &temp);
                    p += i + 2;
                } else {
                    error = get_pattern(pattern[p + 1], pattern[p + 2], str, index, &temp);
                    stops.clear();
                }
                if (error < 0) {
                    p = 0;
                    index = start + 1;
                    break;
                } else {
                    index = error;
                    if (pattern[p + 2] == '%' && stops.length() == 0)
                        index--;
                    p++;
                }
            } else {
                std::string temp_s;
                if (index == 0)
                    index++;
                while (p < pattern.length() && index - 1 < str.length() && pattern[p] == str[index - 1] && pattern[p] != '%') {
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
                (pattern[pattern.length() - 2] == '%' && is_flag(pattern[pattern.length() - 1])) ||
                is_stop(str[index - 1], stops)) {
                if (temp.size() > 0)
                    result.push_back(temp);
                temp.clear();
                index--;
            } else {
                index = start + 1;
            }
        }
    }
    //display_result(result);
    return (result);
}