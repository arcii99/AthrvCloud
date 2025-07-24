//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>

#define BUFSIZE 2048

void err_sys(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in servaddr;
    char sendbuff[BUFSIZE], recvbuff[BUFSIZE + 1];
 
    if (argc != 2) {
        printf("usage: %s <IP address>\n", argv[0]);
        exit(1);
    }
    
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        err_sys("socket error");

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(8000);

    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0)
        err_sys("inet_pton error");

    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0)
        err_sys("connect error");

    strcpy(sendbuff, "GET / HTTP/1.0\r\n\r\n");
    write(sockfd, sendbuff, strlen(sendbuff));

    while ((n = read(sockfd, recvbuff, BUFSIZE)) > 0) {
        recvbuff[n] = '\0';
        printf("%s", recvbuff);
    }
    
    if (n < 0)
        err_sys("read error");

    close(sockfd);
    return 0;
}