//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8000
#define BUF_SIZE 1024

void error(char *msg)
{
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(void)
{
    int sockfd, connfd;
    socklen_t addrlen;
    struct sockaddr_in address, client_addr;
    char buf[BUF_SIZE];
    int opt = 1;
    int n;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        error("socket() failed");
    }

    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        error("setsocketopt() failed");
    }

    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *) &address, sizeof(address)) == -1) {
        error("bind() failed");
    }

    if (listen(sockfd, 5) == -1) {
        error("listen() failed");
    }

    printf("Waiting for client to connect...\n");

    addrlen = sizeof(client_addr);
    if ((connfd = accept(sockfd, (struct sockaddr *) &client_addr, &addrlen)) == -1) {
        error("accept() failed");
    }

    printf("Connection established with %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    while (1) {
        memset(buf, 0, sizeof(buf));
        n = recv(connfd, buf, sizeof(buf), 0);

        if (n == -1) {
            error("recv() failed");
        } else if (n == 0) {
            printf("Client disconnected\n");
            break;
        }

        printf("Received from client: %s\n", buf);

        if (send(connfd, buf, strlen(buf), 0) == -1) {
            error("send() failed");
        }
    }

    close(connfd);
    close(sockfd);

    return 0;
}