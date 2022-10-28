#pragma once

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#include <strings.h>
#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

void err_sys(const char* str, ...);



