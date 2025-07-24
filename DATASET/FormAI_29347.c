//FormAI DATASET v1.0 Category: Firewall ; Style: irregular
/*
 * A unique C Firewall example program by Codegenie
 * This program filters incoming traffic on port 80 and blocks any external connections from the local network
 * It also blocks connections from a specific IP address specified in the code
 * WARNING: This program is for educational purposes only and should not be used in a production environment.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 80
#define BLOCKED_IP "192.168.1.100"

int main() {
    int sockfd, connfd;
    struct sockaddr_in serveraddr, clientaddr;
    socklen_t len = sizeof(clientaddr);
    char buffer[1024];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serveraddr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr*)&serveraddr, sizeof(serveraddr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(sockfd, 5) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    while (1) {
        connfd = accept(sockfd, (struct sockaddr*)&clientaddr, &len);
        if (connfd < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        inet_ntop(AF_INET, &(clientaddr.sin_addr), buffer, INET_ADDRSTRLEN);

        if (strcmp(buffer, BLOCKED_IP) == 0) {
            printf("Blocked IP address %s attempting to connect\n", BLOCKED_IP);
            close(connfd);
            continue;
        }

        if (ntohs(clientaddr.sin_port) == 80) {
            printf("Incoming HTTP connection from %s:%d\n", buffer, ntohs(clientaddr.sin_port));
            char *message = "HTTP/1.1 200 OK \nContent-Type: text/plain\nContent-Length: 12\n\nHello World!";
            write(connfd, message, strlen(message));
            close(connfd);
            continue;
        }

        printf("Incoming connection from %s:%d\n", buffer, ntohs(clientaddr.sin_port));
        close(connfd);
    }

    close(sockfd);
    return 0;
}