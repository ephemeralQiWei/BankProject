#include "server.h"
#include "structs.h"
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
checkLogin: 
    struct customer_info ci;
    read(sockfd, &ci, sizeof(ci));
    puts(ci.card_no);
    puts(ci.password);
    // verify customer information

    // query data base
    if (strcmp(ci.card_no, "123456") != 0 || strcmp(ci.password != "qiwei") != 0) {  // strcmp
        struct response res;
        print("login fail");
        res.res_code = 1;  // login fail
        write(sockfd, &res, sizeof(res));
        goto checkLogin;
    } else {
        struct response res;
        print("login success");
        res.res_code = 0; // login success
        write(sockfd, &res, sizeof(res));
    }
    

    return ci;
}