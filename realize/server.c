#include "server.h"
#include "structs.h"
#include "unp.h"
#include <stdio.h>

void service(int sockfd)
{
    struct customer_info ci = checkLogin(sockfd);
    /*
    for ( ; ; ) {
        struct request req;
        read(sockfd, &req, sizeof(req));
        printf("code of request id %d\n", req.req_code);
        struct response res;
        write(sockfd, &res, sizeof(res));
    }
    */
}

struct customer_info checkLogin(int sockfd)
{
    struct customer_info ci;
checkLogin: 
    
    read(sockfd, &ci, sizeof(ci));
    puts(ci.card_no);
    puts(ci.password);
    printf("ci.card_no len = %d, ci.password len = %d\n", (int)strlen(ci.card_no), (int)strlen(ci.password));
    printf("%d, %d\n", ci.card_no[5], ci.password[4]);
    printf("%d, %d\n", ci.card_no[6], ci.password[5]);
    printf("%d, %d\n", ci.card_no[7], ci.password[6]);
    printf("%d, %d\n", ci.card_no[8], ci.password[7]);
    // verify customer information

    // query data base
    if (strcmp(ci.card_no, "123456") != 0 || strcmp(ci.password, "qiwei") != 0) {  // strcmp
        struct response res;
        printf("login fail\n");
        res.res_code = 1;  // login fail
        write(sockfd, &res, sizeof(res));
        goto checkLogin;
    } else {
        struct response res;
        printf("login success\n");
        res.res_code = 0; // login success
        write(sockfd, &res, sizeof(res));
    }
    

    return ci;
}