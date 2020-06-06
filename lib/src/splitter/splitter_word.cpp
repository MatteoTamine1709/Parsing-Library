#include <stdlib.h>
#include "../../include/parsing.h"

bool found = false;
std::string temp;
std::vector<std::string> tab;

std::vector<std::string> end_split_word(void)
{
    if (temp.length() > 0)
        tab.push_back(temp);
    if (tab.size() == 0)
        tab.push_back("");
    return (tab);
}

bool found_word(int *i, int j, const std::string &str,
    const std::vector<std::string> words)
{
    if (str[(*i)] == words[j][0]) { //Found start of a word?
        int k = 0;
        for (k = 0; k < words[j].length(); k++)
            if (str[(*i) + k] != words[j][k])
                break;
        if (k == words[j].length()) {
            if (temp.length() > 0)
                tab.push_back(temp);
            temp.clear();
            if (Parser::pSave_split)
                tab.push_back(words[j]);
            found = true;
            (*i) += k - 1;
            return (true);
        }
    }
    return (false);
}

std::vector<std::string> Parser::split_word(const std::string &str, const std::vector<std::string> words, bool save_split)
{
    Parser::pSave_split = save_split;

    if (str.length() == 0) {
        tab.push_back("");
        return (tab);
    }
    for (int i = 0; i < str.length(); i++) {
        found = false;
        for (int j = 0; j < words.size(); j++)
            if (found_word(&i, j, str, words))
                break;
        if (!found)
            temp.push_back(str[i]);
    }
    return (end_split_word());
}