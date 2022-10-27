#include "customer.h"
#include "warpsock.h"
#include "structs.h"

#define SERV_PORT 8888
#define SERV_ADDR "127.0.0.1"

struct customer_info customer_login()
{

    // If the customer enters the bank card number and password, connect to the server synchronously
    struct customer_info ci;
    int BCIDconfirm = 0;
    //char BankCardID[20];
    while (BCIDconfirm != 1) {
        fgets(ci.card_no, 20, stdin);
        printf("Please confirm your input for BankCardID (1:confirm; else:re-enter):");
        scanf("%d", &BCIDconfirm);
        flushIn();
    }
    int passwdconfirm = 0;
    //char Password[20];
    while (passwdconfirm != 1) {
        fgets(ci.password, 20, stdin);
        printf("Please confirm your input for Password (1:confirm; else:re-enter):");
        scanf("%d", &passwdconfirm);
        flushIn();
    }

    //** connect to server to verify identity
    int sockfd = Socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    struct sockaddr_in servaddr;
    bzero(&servaddr, sizezof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERV_PORT);
    Inet_pton(AF_INET, SERV_ADDR, &servaddr.sin_addr);

    Connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr));

    write(sockfd, &ci, sizeof(ci));

    struct response res;
    read(sockfd, &res, sizeof(res));

    printf("code of response is %d\n", res.res_code);

    // dispose

}



