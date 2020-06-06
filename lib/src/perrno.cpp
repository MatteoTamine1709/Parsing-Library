#include <stdio.h>
#include "../include/parsing.h"

bool Parser::pSave_split;

void str_perrno(void)
{
    switch (perrno) {
        case PE_VAL:
            printf("PE_VAL\n");
            break;
    }
}