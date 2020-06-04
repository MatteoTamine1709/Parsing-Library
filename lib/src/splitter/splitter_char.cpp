#include <stdlib.h>
#include "../../include/parsing.h"

int is_symb(char c, const std::string symb)
{
    for (int i = 0; symb[i]; i++)
        if (symb[i] == c || !c)
            return (42);
    return (0);
}

std::vector<std::string> Parser::split_char(const std::string &str, const std::string &symb, bool save_split)
{
    std::vector<std::string> tab;
    int i = 0;

    if (str.length() == 0) {
        tab.push_back("");
        return (tab);
    }
    while (i < str.length()) {
        std::string temp;
        while (!is_symb(str[i], symb) && i < str.length()) {
            temp.push_back(str[i]);
            i++;
        }
        if (temp.length() > 0)
            tab.push_back(temp);
        temp.clear();
        while (is_symb(str[i], symb) && i < str.length()) {
            if (save_split)
                temp.push_back(str[i]);
            i++;
        }
        if (temp.length() > 0 && save_split)
            tab.push_back(temp);
    }
    if (tab.size() == 0)
        tab.push_back("");
    return (tab);
}