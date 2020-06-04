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

extern "C" void test_variant()
{
    struct pType_s *arr = (pType_s *) malloc(sizeof(struct pType_s) * 3);
    arr[0].type = pt_str;
    arr[0].data = strdup("String value");
    arr[1].type = pt_int;
    arr[1].data = malloc(sizeof(int));
    *((int *)(arr[1].data)) = 5;
    arr[2].type = pt_dbl;
    arr[2].data = malloc(sizeof(double));
    *((double *)(arr[2].data)) = 27.3;

    /* access the values.. */
    for (int i = 0; i < 3; i++) {
      switch(arr[i].type) {
        case pt_str: printf( "String: %s\n", (char *)(arr[0].data) ); break;
        case pt_int: printf( "Integer: %d\n", *((int *)(arr[1].data)) ); break;
        case pt_dbl: printf( "Double: %f\n", *((double *)(arr[2].data)) ); break;
      }
    }

    /* again, ALL data was dynamically allocated, so free each item's data */
    for (int i = 0; i < 3; i++)
      free(arr[i].data);
    /* then free the malloc'ed array */
    free(arr);
}