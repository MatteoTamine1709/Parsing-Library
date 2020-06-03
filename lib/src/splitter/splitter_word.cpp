#include <stdlib.h>
#include "../../include/parsing.h"

vector<string> Parser::split(const string &str, const vector<string> words, bool save_split)
{
    vector<string> tab;
    bool found = false;

    string temp;
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
    return (tab);
}