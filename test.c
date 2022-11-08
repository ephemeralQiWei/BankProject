#include <stdio.h>
#include <string.h>

int main(int argc, char* arg[])
{
    char str1[60] = "name = 'qiwei' and password = 'qiwei123456'";
    gets(str1);
    char str2[33] = "select * from table where ";
    printf("str1 len = %d\n", (int)strlen(str1));
    printf("str2 len = %d\n", (int)strlen(str2));
    puts(str1);
    puts(str2);
    printf("str1 address = %p\n", str1);
    printf("str2 address = %p\n", str2);
    puts(strcat(str2, str1));
    printf("return address = %p\n", strcat(str1, str2));
    puts(str1);
    printf("\n");
    puts(str2);
    printf("str1 len = %d\n", (int)strlen(str1));
    printf("str2 len = %d\n", (int)strlen(str2));
    return 0;
}