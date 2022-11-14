#include "server.h"
#include "structs.h"
#include "unp.h"
#include <stdio.h>

void service(int sockfd)
{
    MYSQL mysql;
    //MYSQL_RES* res;
    MYSQL_ROW rows[3];

    mysql_init(&mysql);

    //mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "gbk");

    if (mysql_real_connect(&mysql, "127.0.0.1", "root", "qiwei123", "bank", 3306, NULL, 0) == NULL) {
        printf(" %s\n", mysql_error(&mysql));
        printf("\n");
        exit(-1);
    }

    struct customer_info ci = checkLogin(sockfd, &mysql, rows);

    /*
    for ( ; ; ) {
        struct request req;
        read(sockfd, &req, sizeof(req));
        printf("code of request id %d\n", req.req_code);
        struct response res;
        write(sockfd, &res, sizeof(res));
    }
    */

    //mysql_free_result(res);
    mysql_close(&mysql);
}

struct customer_info checkLogin(int sockfd, MYSQL* mysql, MYSQL_ROW* rows)
{
    MYSQL_RES* sqlres;
    struct response res;
    struct request req;

checkLogin: 
    read(sockfd, &req, sizeof(req));
    printf("request code = %u\n", req.req_code);
    puts(req.ci.card_no);
    puts(req.ci.password);
    printf("ci.card_no len = %d, ci.password len = %d\n", (int)strlen(req.ci.card_no), (int)strlen(req.ci.password));

    char sql[100] = "select * from account where accountNo = '";
    strcat(sql, req.ci.card_no);
    char temp[32] = "' and password = '";
    strcat(sql, "' and password = '");
    strcat(sql, req.ci.password);
    strcat(sql, "'");
    puts(sql);
    int ret = mysql_query(mysql, sql);
    
    

    printf("ret: %d\n", ret);
    printf("affect rows = %lu\n", mysql_affected_rows(mysql));
    printf("mysql rows = %u\n", mysql_field_count(mysql));

    sqlres = mysql_store_result(mysql);
    printf("select rows = %lu\n", mysql_num_rows(sqlres));
    printf("select fields = %u\n", mysql_num_fields(sqlres));
    
    // query data base
    if (ret != 0 || mysql_num_rows(sqlres) <= 0) {  // strcmp
        printf("login fail\n");
        res.res_code = 0;  // login fail
        write(sockfd, &res, sizeof(res));
        goto checkLogin;
    } else {
        printf("login success\n");
        res.res_code = 1; // login success

                
        printf("%p\n", sqlres);
        rows[0] = mysql_fetch_row(sqlres);
        printf("%p\n", rows[0]);
        printf("%s %s %s %s\n", rows[0][0], rows[0][1], rows[0][2], rows[0][3]);
        char sql1[100] = "select * from customer where IDNo = '";
        strcat(sql1, rows[0][1]);
        strcat(sql1, "'");
        printf("%s\n", sql1);
        mysql_query(mysql, sql1);
        sqlres = mysql_store_result(mysql);
        rows[1] = mysql_fetch_row(sqlres);

        char sql2[100] = "select * from curdep where accountNo = '";
        strcat(sql2, req.ci.card_no);
        strcat(sql2, "'");
        puts(sql2);
        mysql_query(mysql, sql2);
        sqlres = mysql_store_result(mysql);
        rows[2] = mysql_fetch_row(sqlres);

        memcpy(res.nb.name, rows[1][1], strlen(rows[1][1])+1);
        res.nb.balance = strtod(rows[2][1], NULL);

        printf("res_code = %d", res.res_code);
        getchar();
        write(sockfd, &res, sizeof(res));
    }
    
    mysql_free_result(sqlres);
    return req.ci;
}