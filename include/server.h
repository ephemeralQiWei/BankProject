#pragma once

#include "mysql.h"

void service(int connfd);

struct customer_info checkLogin(int connfd, MYSQL* mysql);