#include "unp.h"
#include "customer.h"
#include "warpsock.h"
#include "structs.h"
#include "cliserv.h"
#include <stdio.h>

#define SERV_PORT 8888
#define SERV_ADDR "127.0.0.1"

int customer_login(struct customer_info *ci, struct name_balance *nb)
{
    printf("in customer_login function\n");
    // If the customer enters the bank card number and password, connect to the server synchronously
    int sockfd = -1;
    int CIconfirm;
    struct request req;

    //char BankCardID[20];
login:
    CIconfirm = 0;
    while (CIconfirm != 1) {
        printf("Please input your BankCardID:");
        fgets(ci->card_no, sizeof(ci->card_no), stdin);
        printf("Please input your Password:");
        fgets(ci->password, sizeof(ci->password), stdin);
        printf("Please confirm your input for BankCardID and password (1:confirm; 0:re-enter; else:exit):");
        scanf("%d", &CIconfirm);
        if (CIconfirm != 1 && CIconfirm != 0)
            exit(-1);
        clear_in(stdin);
    }
    ci->card_no[strlen(ci->card_no)-1] = '\0';
    ci->password[strlen(ci->password)-1] = '\0';

    puts(ci->card_no);
    puts(ci->password);
    printf("ci->card_no len = %d, ci->password len = %d\n", (int)strlen(ci->card_no), (int)strlen(ci->password));
    
    //** connect to server to verify identity
    printf("will connect service\n");

    if (sockfd != -1)
        goto send;
    sockfd = Socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    struct sockaddr_in servaddr;
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERV_PORT);
    Inet_pton(AF_INET, SERV_ADDR, &servaddr.sin_addr);

    Connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr));


send:
    req.req_code = 1;
    req.ci = *ci;
    write(sockfd, &req, sizeof(struct request));

    struct response res;
    read(sockfd, &res, sizeof(res));

    printf("code of response returned from the server is %u\n", res.res_code);
    printf(res.res_code == 1 ? "login successful\n" : "login failed\n");
    if (res.res_code != 1)
        goto login;
    // dispose
    nb->balance = res.nb.balance;
    strcpy(nb->name, res.nb.name);

    return sockfd;
}


unsigned int login_page()
{
    /*
    int choice;
    printf("    ---------login_page---------\n");
    printf("\t1、user login\n");
    printf("    Please input your choice(1~1):");
    scanf("%d", &choice);
    clear_in();
    //fflush(stdin);   // vain in linux(gcc), useful in vc
    while (!(choice < 2 && choice > 0)) {
        printf("    Please re-enter your selection(1~1):");
        scanf("%d", &choice);
        clear_in();
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
    clear_in(stdin);
    //fflush(stdin);   // vain in linux(gcc), useful in vc
    while (!(choice < 5 && choice > 0)) {
        printf("    Please re-enter your selection(1~4):");
        scanf("%d", &choice);
        clear_in(stdin);
    }
    return choice;
}

void save_money()
{
    
}

void withdraw_money()
{
    
}


void transfer_account()
{
    
}

void modify_user_information()
{
    
}