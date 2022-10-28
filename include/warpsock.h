#pragma once

#include "unp.h"

int Socket(int family, int type, int protocol);

int Connect(int sockfd, const struct sockaddr *servaddr, socklen_t addrlen);

int Bind(int sockfd, const struct sockaddr *myaddr, socklen_t addrlen);

int Listen(int sockfd, int backlog);

int Accept(int sockfd, struct sockaddr *cliaddr, socklen_t *addrlen);

int Inet_pton(int family, const char *strptr, void *addrptr);

