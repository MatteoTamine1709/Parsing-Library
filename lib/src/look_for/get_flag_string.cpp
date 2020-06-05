#include <stdlib.h>
#include <iostream>
#include "../../include/parsing.h"

//pType_v : string, char, int, unsigned int, float, long

int get_string(const std::string str, char stop, int index, std::vector<pType_v> *result)
{
    printf("string\n");
    int i = index;
    std::string temp;
    for (i = index; i < str.length() && is_valid_string_char(str[i]) && str[i] != stop; i++)
        temp.push_back(str[i]);
    if (temp.length() == 0)
        return (-2);
    result->push_back(temp);
    return (i);
}

int get_complex_string(const std::string str, char stop, int index, std::vector<pType_v> *result)
{
    printf("complex string\n");
    int i = index;
    std::string temp;
    for (i = index; i < str.length() && is_valid_string_char(str[i]) && str[i] != stop; i++)
        temp.push_back(str[i]);
    if (temp.length() == 0)
        return (-2);
    result->push_back(temp);
    return (i);
}

int get_number(const std::string str, char stop, int index, std::vector<pType_v> *result)
{
    printf("number\n");
    int i = index;
    std::string temp;
    while (str[i] == ' ' || str[i] == '\t')
        i++;
    for (i = index; i < str.length() && is_valid_int_char(str[i]) && str[i] != stop; i++)
        temp.push_back(str[i]);
    if (temp.length() == 0)
        return (-2);
    result->push_back(temp);
    return (i);
}

int get_dot(const std::string str, char stop, int index, std::vector<pType_v> *result)
{
    printf("string dot\n");
    int i = index;
    std::string temp;
    for (i = index; i < str.length() && is_valid_string_dot(str[i]) && str[i] != stop; i++)
        temp.push_back(str[i]);
    if (temp.length() == 0)
        return (-2);
    result->push_back(temp);
    return (i);
}

int get_char(const std::string str, char stop, int index, std::vector<pType_v> *result)
{
    printf("char\n");
    int i = index;
    result->push_back(str[i++]);
    return (i);
}