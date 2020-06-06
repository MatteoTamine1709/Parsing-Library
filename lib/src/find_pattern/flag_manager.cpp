#include <stdlib.h>
#include <iostream>
#include "../../include/parsing.h"

//pType_v : string, char, int, unsigned int, float, long

bool is_flag(char c)
{
    std::string flags = "sSn.cdufl*%";

    for (int i = 0; i < flags.length(); i++)
        if (c == flags[i])
            return (true);
    return (false);
}

bool is_valid_string_char(char c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == ' ' || c == '\t')
        return (true);
    return (false);
}

bool is_valid_string_dot(char c)
{
    if (c == '.' || c == '?' || c == '!' || c == ':' || c == ',' || c == ';')
        return (false);
    return (true);
}

bool is_valid_int_char(char c)
{
    if (c >= '0' && c <= '9')
        return (true);
    return (false);
}

bool is_stop(char c, std::string stops)
{
    for (int i = 0; i < stops.length(); i++)
        if (c == stops[i])
            return (true);
    return (false);
}