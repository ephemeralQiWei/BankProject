#include "cliserv.h"

#include <stdio.h>

void clear_in(FILE* file)
{
    char ch;
    while (ch != '\n')
        fscanf(file, "%c", &ch);
    /*
    while (getchar() != '\n')
        scanf("%c", &ch);
    */
}

