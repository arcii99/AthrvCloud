//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in servaddr;
    char sendbuf[BUF_SIZE], recvbuf[BUF_SIZE];
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(80);
    inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect error");
        exit(1);
    }
    memset(sendbuf, 0, sizeof(sendbuf));
    sprintf(sendbuf, "GET / HTTP/1.1\r\nHost: www.example.com\r\nConnection: close\r\n\r\n");
    if (send(sockfd, sendbuf, strlen(sendbuf), 0) < 0) {
        perror("send error");
        exit(1);
    }
    while (1) {
        memset(recvbuf, 0, sizeof(recvbuf));
        int n = recv(sockfd, recvbuf, sizeof(recvbuf), 0);
        if (n < 0) {
            perror("recv error");
            exit(1);
        } else if (n == 0) {
            break;
        } else {
            printf("%s", recvbuf);
        }
    }
    close(sockfd);
    return 0;
}