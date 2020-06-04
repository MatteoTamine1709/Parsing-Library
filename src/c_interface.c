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
        printf("%s\n", ret[i]);
        free(ret[i]);
    }
    free(ret);
    free(symb);
    test_variant();
    return 0;
}