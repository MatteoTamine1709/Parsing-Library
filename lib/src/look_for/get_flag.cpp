#include <stdlib.h>
#include <iostream>
#include "../../include/parsing.h"

//pType_v : string, char, int, unsigned int, float, long

int get_star(const std::string str, char stop, int index, std::vector<pType_v> *result)
{
    printf("star\n");
    int i = index;
    std::string temp;
    for (i = index; i < str.length() && is_valid_string_char(str[i]) && str[i] != stop; i++)
        temp.push_back(str[i]);
    if (temp.length() == 0)
        return (-2);
    result->push_back(temp);
    return (i);
}

int get_percentage(const std::string str, char stop, int index, std::vector<pType_v> *result)
{
    printf("percentage\n");
    int i = index;
    std::string temp;
    for (i = index; i < str.length() && is_valid_string_char(str[i]) && str[i] != stop; i++)
        temp.push_back(str[i]);
    if (temp.length() == 0)
        return (-2);
    result->push_back(temp);
    return (i);
}

int get_pattern(char flag, char stop, const std::string str, int index, std::vector<pType_v> *result)
{
    std::string flags = "sSn.cdufl*%";
    get_pattern_t flags_func[] = {
        get_string,
        get_complex_string,
        get_number,
        get_dot,
        get_char,
        get_int,
        get_uint,
        get_float,
        get_long,
        get_star,
        get_percentage
    };
    for (int i = 0; i < flags.length(); i++) {
        if (flags[i] == flag) {
            index = flags_func[i](str, stop, index, result);
            break;
        }
    }
    return (index + 1);
}