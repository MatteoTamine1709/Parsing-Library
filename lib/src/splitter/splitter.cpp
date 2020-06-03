#include <stdlib.h>
#include "../../include/parsing.h"

int symb_checker(char c, const string symb)
{
    for (int i = 0; symb[i]; i++)
        if (symb[i] == c || !c)
            return (42);
    return (0);
}

int word_count(const string str, const string symb)
{
    int nb_word = 0;

    if (!symb_checker(str[0], symb))
        nb_word++;
    for (int i = 0; str[i]; i++)
        if (symb_checker(str[i], symb) && symb_checker(str[i + 1], symb) == 0)
            nb_word++;
    return (nb_word);
}

int sizeof_word(const string str, int i, const string symb)
{
    int size = 0;

    for (size = 0; i < str.length(); i++, size++) {
        if (symb_checker(str[i], symb))
            return (size);
    }
    return (size);
}

vector<string> Parser::split(const string &str, const string &symb, bool save_split)
{
    vector<string> tab;
    int nb_word = word_count(str, symb);
    int y = 0;
    int step = 0;
    int i = 0;

    for (step = 0; step < nb_word; step++, i++) {
        for (; symb_checker(str[i], symb); i++);
        string temp;
        for (y = 0; i < str.length() && !symb_checker(str[i], symb); y++, i++)
            temp.push_back(str[i]);
        tab.push_back(temp);
    }
    return (tab);
}