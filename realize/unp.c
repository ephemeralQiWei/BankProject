#include "unp.h"


void err_sys(const char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    printf(fmt, args);
}
