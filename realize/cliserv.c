#include "cliserv.h"

#include <stdio.h>

void flushIn()
{
    char ch;
    while (ch != '\n')
        scanf("%c", &ch);
}

void login_page()
{

}

unsigned int dispaly_client_operator()
{
    int choice;
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
