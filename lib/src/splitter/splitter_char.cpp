#include <stdlib.h>
#include "../../include/parsing.h"

int symb_checker_char(char c, const string symb)
{
    for (int i = 0; symb[i]; i++)
        if (symb[i] == c || !c)
            return (42);
    return (0);
}

int word_count_char(const string str, const string symb)
{
    int nb_word = 0;

    if (!symb_checker_char(str[0], symb))
        nb_word++;
    for (int i = 0; str[i]; i++)
        if (symb_checker_char(str[i], symb) && symb_checker_char(str[i + 1], symb) == 0)
            nb_word++;
    return (nb_word);
}

int sizeof_word_char(const string str, int i, const string symb)
{
    int size = 0;

    for (size = 0; i < str.length(); i++, size++) {
        if (symb_checker_char(str[i], symb))
            return (size);
    }
    return (size);
}

int is_symb(char c, const string symb)
{
    for (int i = 0; symb[i]; i++)
        if (symb[i] == c || !c)
            return (42);
    return (0);
}

vector<string> Parser::split(const string &str, const string &symb, bool save_split)
{
    vector<string> tab;
    int i = 0;

    while (i < str.length()) {
        string temp;
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
    return (tab);
}