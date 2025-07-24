//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUFSIZE 512
#define SERVER_ADDR "127.0.0.1"
#define SERVER_PORT 8000
#define PROXY_PORT 9000

void error_handler(char *message) {
    perror(message);
    exit(1);
}

void proxy(int connfd) {
    struct sockaddr_in servaddr;
    char buf[BUFSIZE];
    int sockfd, clilen, n;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
        error_handler("Failed to create socket");

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(SERVER_ADDR);
    servaddr.sin_port = htons(SERVER_PORT);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1)
        error_handler("Could not connect to server");

    while ((n = read(connfd, buf, BUFSIZE)) > 0) {
        if (write(sockfd, buf, n) == -1)
            error_handler("Failed to write to server");

        memset(buf, 0, BUFSIZE);

        if ((n = read(sockfd, buf, BUFSIZE)) > 0) {
            if (write(connfd, buf, n) == -1)
                error_handler("Failed to write to client");
        }
    }

    close(sockfd);
    close(connfd);
}

int main(int argc, char *argv[]) {
    struct sockaddr_in servaddr, cliaddr;
    int listenfd, connfd, clilen;

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd == -1)
        error_handler("Failed to create socket");

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PROXY_PORT);

    if (bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1)
        error_handler("Failed to bind");

    if (listen(listenfd, 5) == -1)
        error_handler("Failed to listen");

    while (1) {
        clilen = sizeof(cliaddr);
        connfd = accept(listenfd, (struct sockaddr *)&cliaddr, &clilen);
        if (connfd >= 0)
            proxy(connfd);
    }

    close(listenfd);

    return 0;
}