#include "customer.h"
#include "warpsock.h"

#define SERV_PORT 8888
#define SERV_ADDR "127.0.0.1"

void customer_login()
{
    int sockfd = Socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    struct sockaddr_in servaddr;
    bzero(&servaddr, sizezof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERV_PORT);
    Inet_pton(AF_INET, SERV_ADDR, &servaddr, sizeof(servaddr));

    Connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr));

    // dispose

}



