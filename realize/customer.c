#include "customer.h"
#include "warpsock.h"
#include "structs.h"
#include "cliserv.h"
#include "unp.h"

#define SERV_PORT 8888
#define SERV_ADDR "127.0.0.1"

struct customer_info customer_login()
{
    printf("in customer_login function\n");
    // If the customer enters the bank card number and password, connect to the server synchronously
    struct customer_info ci;
    int CIconfirm = 0;
    //char BankCardID[20];
    while (CIconfirm != 1) {
        printf("Please input your BankCardID:");
        // fgets(ci.card_no, 20, stdin);
        gets(ci.card_no);
        printf("Please input your Password:");
        // fgets(ci.password, 20, stdin);
        gets_s(ci.password, sizeof(ci.password));
        printf("Please confirm your input for BankCardID and password (1:confirm; else:re-enter):");
        scanf("%d", &CIconfirm);
        flushIn();
    }

    puts(ci.card_no);
    puts(ci.password);
    printf("ci.card_no len = %d, ci.password len = %d\n", (int)strlen(ci.card_no), (int)strlen(ci.password));
    
    //** connect to server to verify identity
    printf("will connect service\n");
    int sockfd = Socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    struct sockaddr_in servaddr;
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERV_PORT);
    inet_pton(AF_INET, SERV_ADDR, &servaddr.sin_addr);

    connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr));

    write(sockfd, &ci, sizeof(ci));

    struct response res;
    read(sockfd, &res, sizeof(res));

    printf("code of response returned from the server is %d\n", res.res_code);

    // dispose
    return ci;
}



