#include "unp.h"

int Socket(int family, int type, int protocol)
{
    int sockfd = Socket(family, type, protocol);
    if (sockfd == -1)
        err_sys("socket function error!\n");
    else
        return sockfd;
}

int Connect(int sockfd, const struct sockaddr *servaddr, socklen_t addrlen)
{
    int res = connect(sockfd, servaddr, addrlen);
    if (res == -1)
        err_sys("connect function error!\n");
    else
        return res;
}

int Bind(int sockfd, const struct sockaddr *myaddr, socklen_t addrlen)
{
    int res = bind(sockfd, myaddr, addrlen);
    if (res == -1)
        err_sys("bind function error!\n");
    else
        return res;
}

int Listen(int sockfd, int backlog)
{
    char *ptr;
    if ( (ptr = getenv("LISTENQ")) != NULL )
        backlog = atoi(ptr);
    if(listen(sockfd, backlog) == -1)
        err_sys("listen function error!\n");
    return 0;
}

int Accept(int sockfd, struct sockaddr *cliaddr, socklen_t *addrlen)
{
    int sockfd = accept(sockfd, cliaddr, addrlen);
    if (sockfd == -1)
        err_sys("accept function error!\n");
    else
        return sockfd;
}

int Inet_pton(int family, const char *strptr, void *addrptr)
{
    int res = inet_pton(family, strptr, addrptr);
    if (res == 0) {
        err_sys("presentation of addr is valid!\n");
    } else if (res = -1) {
        err_sys("inet_pton function error!\n");
    } else {
        return res;
    }
}

