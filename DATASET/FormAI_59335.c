//FormAI DATASET v1.0 Category: Networking ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080

int main(int argc, char const *argv[]) {

    int sockfd, connfd;
    struct sockaddr_in servaddr, clientaddr;
    char buffer[1024];

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    memset(&clientaddr, 0, sizeof(clientaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(sockfd, 2) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    socklen_t len = sizeof(clientaddr);
    if ((connfd = accept(sockfd, (struct sockaddr *)&clientaddr, &len)) < 0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    char *welcome = "Welcome to the server!";
    send(connfd, welcome, strlen(welcome), 0);

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        int n = recv(connfd, buffer, sizeof(buffer), 0);
        if (n < 0) {
            perror("Receive failed");
            exit(EXIT_FAILURE);
        } else if (n == 0) {
            printf("Connection closed\n");
            break;
        }
        printf("Message received: %s\n", buffer);
        send(connfd, buffer, strlen(buffer), 0);
    }

    close(connfd);
    close(sockfd);
    return 0;
}