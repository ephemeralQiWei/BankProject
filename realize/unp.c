#include "unp.h"


void err_sys(const char* fmt, ...)
{
    printf("in err_sys function\n");
    va_list args;
    va_start(args, fmt);
    printf(fmt, args);
}
