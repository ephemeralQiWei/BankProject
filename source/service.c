#include "cliserv.h"
#include "unp.h"
#include "warpsock.h"

#define SERV_PORT 8888
#define SERV_ADDR "127.0.0.1"
#define LISTENQ 128   // APUE page 489

int main(int argc, char* argv[])
{
    int clilen, childpid;
    int listenfd = Socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    struct sockaddr_in servaddr, cliaddr;
    bzero(&servaddr, sizezof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERV_PORT);
    servaddf.sin_addr.s_addr = htonl(INADDR_ANY);

    Bind(listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr));

    Listen(listenfd, LISTENQ);

    for ( ; ; ) {
        clilen = sizeof(cliaddr);
        connfd = Accept(listenfd, (struct sockaddr *) &cliaddr, &clilen);
        if ( (childpid = for()) == 0) {
            close(listenfd);
            service(connfd);
            exit(0);
        }
        close(connfd);
    }

}