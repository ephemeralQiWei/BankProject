#include <stdio.h>
#include "mysql.h"
//#include "C:/Program Files/MySQL/MySQL Server 8.0/include/mysql.h"
//using namespace std;

//#pragma comment(lib, "C:/Program Files/MySQL/MySQL Server 8.0/lib/libmysql.lib")
//#pragma comment(dll, "C:/Program Files/MySQL/MySQL Server 8.0/lib/libmysql.dll")

int main()
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

    int ret = mysql_query(&mysql, "select * from customer;");

    printf("ret: %d\n", ret);

    res = mysql_store_result(&mysql);

    while (row = mysql_fetch_row(res)) {
        printf("%s  %s  %s %s %s %s\n", row[0], row[1], row[2], row[3], row[4], row[5]);
    }

    mysql_free_result(res);

    mysql_close(&mysql);

    //system("pause");
    
    return 0;

}