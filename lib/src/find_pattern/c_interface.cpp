#include <stdlib.h>
#include <iostream>
#include "../../include/parsing.h"

//char **pSplit_char(const char *str, const char *symb, int save_split)

using namespace std;

extern "C" pCType_s **pFind_pattern(const char *str, const char *symb,
    int save_split)
{
    string str_s;
    string symb_s;
    bool save_split_b = false;
    pCType_s **ret;

    for (int i = 0; str[i]; i++)
        str_s.push_back(str[i]);
    for (int i = 0; symb[i]; i++)
        symb_s.push_back(symb[i]);
    if (save_split == 1)
        save_split_b = true;
    Parser p;
    vector<vector<pType_v>> ret_val = p.find_pattern(str_s, symb_s, save_split_b);

    ret = (pCType_s **) malloc(sizeof(pCType_s *) * (ret_val.size() + 1));
    if (ret == NULL)
        return (NULL);
    for (int i = 0; i < ret_val.size(); i++) {
        ret[i] = (pCType_s *) malloc(sizeof(pCType_s) * (ret_val[i].size() + 1));
        if (ret[i] == NULL)
            return (NULL);
        for (int j = 0; j < ret_val[i].size(); j++) {
            switch (ret_val[i][j].index()) {
                case 0: {
                    ret[i][j].type = pt_str;
                    string temp = (get<0>(ret_val[i][j]));
                    char *data = (char *) malloc(sizeof(char) * (temp.size() + 1));
                    for (int k = 0; k < temp.size(); k++)
                        data[k] = temp[k];
                    data[temp.size()] = '\0';
                    ret[i][j].data = data;
                    break;
                }
                case 1: {
                    ret[i][j].type = pt_char;
                    char temp = (get<1>(ret_val[i][j]));
                    ret[i][j].data = (void *) malloc(sizeof(char));
                    (*(char *) (ret[i][j].data)) = temp;
                    break;
                }
                case 2: {
                    ret[i][j].type = pt_int;
                    int temp = (get<2>(ret_val[i][j]));
                    ret[i][j].data = (void *) malloc(sizeof(int));
                    (*(int *) (ret[i][j].data)) = temp;
                    break;
                }
                case 3: {
                    ret[i][j].type = pt_uint;
                    unsigned int temp = (get<3>(ret_val[i][j]));
                    ret[i][j].data = (void *) malloc(sizeof(unsigned int));
                    (*(unsigned int *) (ret[i][j].data)) = temp;
                    break;
                }
                case 4: {
                    ret[i][j].type = pt_fl;
                    float temp = (get<4>(ret_val[i][j]));
                    ret[i][j].data = (void *) malloc(sizeof(float));
                    (*(float *) (ret[i][j].data)) = temp;
                    break;
                }
                case 5: {
                    ret[i][j].type = pt_lg;
                    long temp = (get<5>(ret_val[i][j]));
                    ret[i][j].data = (void *) malloc(sizeof(long));
                    (*(long *) (ret[i][j].data)) = temp;
                    break;
                }
            }
        }
        ret[i][ret_val[i].size()].data = NULL;
    }
    ret[ret_val.size()] = NULL;
    return (ret);
    /*struct pCType_s *arr = (pCType_s *) malloc(sizeof(struct pCType_s) * 3);
    arr[0].type = pt_str;
    arr[0].data = strdup("String value");
    arr[1].type = pt_int;
    arr[1].data = malloc(sizeof(int));
    *((int *)(arr[1].data)) = 5;
    arr[2].type = pt_lg;
    arr[2].data = malloc(sizeof(double));
    *((double *)(arr[2].data)) = 27.3;

    /* access the values.. */
    /*for (int i = 0; i < 3; i++) {
      switch(arr[i].type) {
        case pt_str: printf( "String: %s\n", (char *)(arr[0].data) ); break;
        case pt_int: printf( "Integer: %d\n", *((int *)(arr[1].data)) ); break;
        case pt_lg: printf( "Double: %f\n", *((double *)(arr[2].data)) ); break;
      }
    }

    /* again, ALL data was dynamically allocated, so free each item's data */
    //for (int i = 0; i < 3; i++)
      //free(arr[i].data);
    /* then free the malloc'ed array */
    //free(arr);
    return (NULL);
}