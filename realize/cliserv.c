#include "cliserv.h"

#include <stdio.h>

void flushIn()
{
    char ch;
    while (ch != '\n')
        scanf("%c", &ch);
    /*
    while (getchar() != '\n')
        scanf("%c", &ch);
    */
}

unsigned int login_page()
{
    /*
    int choice;
    printf("    ---------login_page---------\n");
    printf("\t1、user login\n");
    printf("    Please input your choice(1~1):");
    scanf("%d", &choice);
    flushIn();
    //fflush(stdin);   // vain in linux(gcc), useful in vc
    while (!(choice < 2 && choice > 0)) {
        printf("    Please re-enter your selection(1~1):");
        scanf("%d", &choice);
        flushIn();
    }
    return choice;
    */
   return 1;
}



unsigned int dispaly_client_operator()
{
    unsigned int choice;
    printf("    ---------pick your business---------\n");
    printf("\t1、save money\n");
    printf("\t2、withdraw money\n");
    printf("\t3、transfer account\n");
    printf("\t4、modify personal information\n");
    printf("    Please input your choice(1~4):");
    scanf("%d", &choice);
    flushIn();
    //fflush(stdin);   // vain in linux(gcc), useful in vc
    while (!(choice < 5 && choice > 0)) {
        printf("    Please re-enter your selection(1~4):");
        scanf("%d", &choice);
        flushIn();
    }
    return choice;
}
