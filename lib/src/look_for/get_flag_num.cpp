#include <stdlib.h>
#include <iostream>
#include "../../include/parsing.h"

//pType_v : string, char, int, unsigned int, float, long

int get_int(const std::string str, char stop, int index, std::vector<pType_v> *result)
{
    printf("int\n");
    int i = index;
    std::string temp;
    int val = 0;
    int neg = 1;
    while (str[i] == ' ' || str[i] == '\t')
        i++;
    if (str[i] == '-') {
        i++;
        neg = -1;
    }
    for (; i < str.length() && is_valid_int_char(str[i]) && str[i] != stop; i++)
        temp.push_back(str[i]);
    if (temp.length() == 0)
        return (-2);
    val = std::stoi(temp) * neg;
    result->push_back(val);
    return (i);
}

int get_uint(const std::string str, char stop, int index, std::vector<pType_v> *result)
{
    printf("unsigned int\n");
    int i = index;
    std::string temp;
    unsigned int val = 0;
    int neg = 1;
    while (str[i] == ' ' || str[i] == '\t')
        i++;
    if (str[i] == '-') {
        i++;
        neg = -1;
    }
    for (; i < str.length() && is_valid_int_char(str[i]) && str[i] != stop; i++)
        temp.push_back(str[i]);
    if (temp.length() == 0)
        return (-2);
    val = (unsigned int) (std::stoi(temp) * neg);
    result->push_back(val);
    return (i);
}

int get_float(const std::string str, char stop, int index, std::vector<pType_v> *result)
{
    printf("float\n");
    int i = index;
    std::string temp;
    float val = 0;
    int neg = 1;
    bool dot = false;
    int start = i;
    while (str[i] == ' ' || str[i] == '\t')
        i++;
    if (str[i] == '-') {
        i++;
        neg = -1;
    }
    for (start = i; i < str.length() && str[i] != stop && (is_valid_int_char(str[i]) ||
    (str[i] == '.' && !dot && i != start)); i++) {
        if (str[i] == '.')
            dot = true;
        temp.push_back(str[i]);
    }
    std::cout << temp << std::endl;
    if (temp.length() == 0)
        return (-2);
    val = std::stof(temp) * neg;
    result->push_back(val);
    return (i);
}

int get_long(const std::string str, char stop, int index, std::vector<pType_v> *result)
{
    printf("long\n");
    int i = index;
    std::string temp;
    long val = 0;
    int neg = 1;
    while (str[i] == ' ' || str[i] == '\t')
        i++;
    if (str[i] == '-') {
        i++;
        neg = -1;
    }
    for (; i < str.length() && str[i] != stop && is_valid_int_char(str[i]); i++) {
        temp.push_back(str[i]);
    }
    if (temp.length() == 0)
        return (-2);
    val = std::stof(temp) * neg;
    result->push_back(val);
    return (i);
}