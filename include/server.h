#pragma once

#include "mysql.h"

void service(int connfd);

struct customer_info checkLogin(int sockfd, MYSQL* mysql, MYSQL_ROW* rows);