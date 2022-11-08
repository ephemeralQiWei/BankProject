#include "server.h"
#include "structs.h"
#include "unp.h"
#include <stdio.h>

void service(int sockfd)
{
    MYSQL mysql;
    MYSQL_RES* res;
    MYSQL_ROW row;

    mysql_init(&mysql);

    //mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "gbk");

    if (mysql_real_connect(&mysql, "127.0.0.1", "root", "qiwei123", "bank", 3306, NULL, 0) == NULL) {
        printf(" %s\n", mysql_error(&mysql));
        printf("\n");
        exit(-1);
    }

    struct customer_info ci = checkLogin(sockfd, &mysql);
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

struct customer_info checkLogin(int sockfd, MYSQL* mysql)
{
    MYSQL_RES* sqlres;
    MYSQL_ROW row;
    struct customer_info ci;
checkLogin: 
    
    read(sockfd, &ci, sizeof(ci));
    puts(ci.card_no);
    puts(ci.password);
    printf("ci.card_no len = %d, ci.password len = %d\n", (int)strlen(ci.card_no), (int)strlen(ci.password));
    // printf("%d, %d\n", ci.card_no[5], ci.password[4]);
    // printf("%d, %d\n", ci.card_no[6], ci.password[5]);
    // printf("%d, %d\n", ci.card_no[7], ci.password[6]);
    // printf("%d, %d\n", ci.card_no[8], ci.password[7]);
    // verify customer information
    char sql[100] = "select IDNo, business from account where accountNo = ";
    strcat(sql, ci.card_no);
    char temp[32] = " and password = ";
    strcat(sql, " and password = ");
    strcat(sql, ci.password);
    int ret = mysql_query(mysql, sql);

    printf("ret: %d\n", ret);

    // query data base
    if (ret != 1) {  // strcmp
        struct response res;
        printf("login fail\n");
        res.res_code = 1;  // login fail
        write(sockfd, &res, sizeof(res));
        goto checkLogin;
    } else {
        struct response res;
        printf("login success\n");
        res.res_code = 0; // login success

        
        sqlres = mysql_store_result(&mysql);
        row = mysql_fetch_row(sqlres);
        char sql1[100] = "select * from customer where IDNo = ";
        strcat(sql, row[0]);
        mysql_query(mysql, sql1);
        write(sockfd, &res, sizeof(res));
    }
    

    return ci;
}