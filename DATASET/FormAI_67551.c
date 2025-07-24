//FormAI DATASET v1.0 Category: Client Server Application ; Style: ephemeral
//Ephemeral Style C Client Server Application Example
//Author: Chatbot

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 5000

void handle_client(int sockfd) {
    char buffer[1024];
    int n;
    bzero(buffer,1024);
    n = read(sockfd, buffer, 1024);
    if (n < 0) {
        perror("ERROR reading from socket");
        return;
    }
    printf("Client sent: %s\n", buffer);
    n = write(sockfd, "I received your message", 23);
    if (n < 0) {
        perror("ERROR writing to socket");
        return;
    }
}

int main(int argc, char **argv) {
    int sockfd, connfd;
    struct sockaddr_in servaddr, cli;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(EXIT_FAILURE);
    }
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);
    if ((bind(sockfd, (struct sockaddr *)&servaddr,sizeof(servaddr))) != 0) {
        perror("ERROR on binding");
        exit(EXIT_FAILURE);
    }
    if ((listen(sockfd, 5)) != 0) {
        perror("ERROR on listen");
        exit(EXIT_FAILURE);
    }
    printf("Server started on port %d\n", PORT);
    while (1) {
        int len = sizeof(cli);
        connfd = accept(sockfd, (struct sockaddr *)&cli, &len);
        if (connfd < 0) {
            perror("ERROR on accept");
            continue;
        }
        printf("Connection accepted from %s:%d\n", inet_ntoa(cli.sin_addr), ntohs(cli.sin_port));
        handle_client(connfd);
        close(connfd);
    }
    close(sockfd);
    return 0;
}