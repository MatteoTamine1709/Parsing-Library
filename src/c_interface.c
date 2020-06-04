#include "header.h"
#include <cstdio>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char *str = "salut toi";
    char *symb = " ";
    char **ret = pSplit_char(str, symb, 1);
    for (int i = 0; ret[i]; i++) {
        printf("%s\n", ret[i]);
        free(ret[i]);
    }
    free(ret);
    return 0;
}