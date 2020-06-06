#include <stdlib.h>
#include "../../include/parsing.h"

extern "C" char **pSplit_char(const char *str, const char *symb, int save_split)
{
    std::string str_s;
    std::string symb_s;
    bool save_split_b = true;
    Parser p;
    char **ret;

    if (str == NULL)
        return (NULL);
    if (symb == NULL) {
        ret = (char **) malloc(sizeof(char) * 2);
        if (ret == NULL)
            return (NULL);
        ret[0] = (char *) str;
        ret[1] = NULL;
        return (ret);
    }
    for (int i = 0; str[i]; i++)
        str_s.push_back(str[i]);
    for (int i = 0; symb[i]; i++)
        symb_s.push_back(symb[i]);
    if (save_split == 0)
        save_split_b = false;
    std::vector<std::string> ret_val = p.split_char(str_s, symb_s, save_split_b);
    ret = (char **) malloc(sizeof(char *) * (ret_val.size() + 1));
    if (ret == NULL)
        return (NULL);
    for (int i = 0; i < ret_val.size(); i++) {
        ret[i] = (char *) malloc(sizeof(char) * (ret_val[i].length() + 1));
        if (ret[i] == NULL) 
            break;
        for (int j = 0; j < ret_val[i].length(); j++)
            ret[i][j] = ret_val[i][j];
        ret[i][ret_val[i].length()] = '\0';
    }
    ret[ret_val.size()] = NULL;
    return (ret);
}

extern "C" char **pSplit_word(const char *str, const char **words, int save_split)
{
    std::string str_s;
    std::vector<std::string> words_v;
    bool save_split_b = true;
    Parser p;
    char **ret;

    if (str == NULL)
        return (NULL);
    if (words == NULL) {
        ret = (char **) malloc(sizeof(char) * 2);
        if (ret == NULL)
            return (NULL);
        ret[0] = (char *) str;
        ret[1] = NULL;
        return (ret);
    }
    for (int i = 0; str[i]; i++)
        str_s.push_back(str[i]);
    for (int i = 0; words[i]; i++) {
        std::string temp;
        for (int j = 0; j < words[i][j]; j++)
            temp.push_back(words[i][j]);
        words_v.push_back(temp);
    }
    if (save_split == 0)
        save_split_b = false;
    std::vector<std::string> ret_val = p.split_word(str_s, words_v, save_split_b);
    ret = (char **) malloc(sizeof(char *) * (ret_val.size() + 1));
    if (ret == NULL)
        return (NULL);
    for (int i = 0; i < ret_val.size(); i++) {
        ret[i] = (char *) malloc(sizeof(char) * (ret_val[i].length() + 1));
        if (ret[i] == NULL) 
            break;
        for (int j = 0; j < ret_val[i].length(); j++)
            ret[i][j] = ret_val[i][j];
        ret[i][ret_val[i].length()] = '\0';
    }
    ret[ret_val.size()] = NULL;
    return (ret);
}