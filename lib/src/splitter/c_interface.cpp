#include <stdlib.h>
#include "../../include/parsing.h"

extern "C" char **pSplit_char(const char *str, const char *symb, int save_split)
{
    string str_s;
    string symb_s;
    bool save_split_b = true;
    Parser p;
    char **ret;

    for (int i = 0; str[i]; i++)
        str_s.push_back(str[i]);
    for (int i = 0; symb[i]; i++)
        symb_s.push_back(symb[i]);
    if (save_split == 0)
        save_split_b = false;
    vector<string> ret_val = p.split_char(str_s, symb_s, save_split_b);
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