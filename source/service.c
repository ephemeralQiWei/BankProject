#include "cliserv.h"
#include "unp.h"
#include "warpsock.h"
#include "server.h"

#define SERV_PORT 8888
#define SERV_ADDR "127.0.0.1"
#define LISTENQ 128   // APUE page 489

int main(int argc, char* argv[])
{
    int clilen, childpid;
    int listenfd;

    struct sockaddr_in servaddr, cliaddr;

    listenfd = Socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERV_PORT);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

    Bind(listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr));

    Listen(listenfd, LISTENQ);
    printf("will input for loop\n");
    for ( ; ; ) {
        clilen = sizeof(cliaddr);
        int connfd = Accept(listenfd, (struct sockaddr *) &cliaddr, &clilen);
        if ( (childpid = fork()) == 0) {
            printf("child process start\n");
            close(listenfd);
            service(connfd);
            printf("child process end\n");
            exit(0);
        }
        close(connfd);
    }

}