#include <stdio.h>
#include "../include/parsing.h"

void str_perrno(void)
{
    switch (perrno) {
        case PE_VAL:
            printf("PE_VAL\n");
            break;
    }
}