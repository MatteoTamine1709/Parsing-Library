#include <stdlib.h>
#include "../../include/parsing.h"

std::vector<std::string> Parser::split_word(const std::string &str, const std::vector<std::string> words, bool save_split)
{
    std::vector<std::string> tab;
    bool found = false;

    if (str.length() == 0) {
        tab.push_back("");
        return (tab);
    }
    std::string temp;
    for (int i = 0; i < str.length(); i++) {
        found = false;
        for (int j = 0; j < words.size(); j++) {
            if (str[i] == words[j][0]) { //Found start of a word?
                int k = 0;
                for (k = 0; k < words[j].length(); k++) {
                    if (str[i + k] != words[j][k])
                        break;
                }
                if (k == words[j].length()) {
                    if (temp.length() > 0)
                        tab.push_back(temp);
                    temp.clear();
                    if (save_split)
                        tab.push_back(words[j]);
                    found = true;
                    i += k - 1;
                    break;
                }
            }
        }
        if (!found)
            temp.push_back(str[i]);
    }
    if (temp.length() > 0)
        tab.push_back(temp);
    if (tab.size() == 0)
        tab.push_back("");
    return (tab);
}