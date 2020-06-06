#include "header.h"
#include <cstdio>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    const char *str = "salut toi";
    const char **symb = (const char **) malloc(sizeof(char *) * 3);
    symb[0] = "ut";
    symb[1] = "to";
    symb[2] = NULL;
    char **ret = pSplit_word(str, symb, 0);
    for (int i = 0; ret[i]; i++) {
        //printf("%s\n", ret[i]);
        free(ret[i]);
    }
    free(ret);
    free(symb);
    pCType_s **ret_pattern = pFind_pattern("42.5 21.36", "%l.%d", 0);
    for (int i = 0; ret_pattern[i]; i++) {
        for (int j = 0; ret_pattern[i][j].data; j++) {
            if (ret_pattern[i][j].type == pt_lg)
                printf("long %ld\n", *(long *) ret_pattern[i][j].data);
            if (ret_pattern[i][j].type == pt_int)
                printf("int %d\n", *(int *) ret_pattern[i][j].data);

        }
    }
    return 0;
}