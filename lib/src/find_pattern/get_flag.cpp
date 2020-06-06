#include <stdlib.h>
#include <iostream>
#include "../../include/parsing.h"

//pType_v : string, char, int, unsigned int, float, long

int Parser::get_star(const std::string str, char stop, int index, std::vector<pType_v> *result)
{
    int i = index;
    std::string temp;
    for (i = index; i < str.length() && str[i] != stop; i++)
        temp.push_back(str[i]);
    if (temp.length() == 0)
        return (-2);
    result->push_back(temp);
    return (i);
}

int Parser::get_percentage(const std::string str, char stop, int index, std::vector<pType_v> *result)
{
    int i = index + 1;
    if (i >= str.length() || str[i - 1] != '%')
        return (-2);
    if (Parser::pSave_split)
        result->push_back(str[i - 1]);
    return (i);
}

int get_pattern(char flag, char stop, const std::string str, int index, std::vector<pType_v> *result)
{
    Parser p;
    std::string flags = "sn.cdufl*%";
    get_pattern_t flags_func[] = {
        &Parser::get_string,
        &Parser::get_number,
        &Parser::get_dot,
        &Parser::get_char,
        &Parser::get_int,
        &Parser::get_uint,
        &Parser::get_float,
        &Parser::get_long,
        &Parser::get_star,
        &Parser::get_percentage
    };
    for (int i = 0; i < flags.length(); i++)
        if (flags[i] == flag) {
            index = (p.*flags_func[i])(str, stop, index, result);
            break;
        }
    return (index + 1);
}