//FormAI DATASET v1.0 Category: Networking ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 3000

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main() {
    int sockfd, newsockfd, n;
    socklen_t cli_len;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    memset((char*) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR on binding");
    }

    listen(sockfd, 5);

    printf("Server started, waiting for connections...\n");

    cli_len = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr*) &cli_addr, &cli_len);
    if (newsockfd < 0) {
        error("ERROR on accept");
    }

    printf("Connection established with client %s\n", inet_ntoa(cli_addr.sin_addr));

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        n = recv(newsockfd, buffer, sizeof(buffer), 0);
        if (n < 0) {
            error("ERROR reading from socket");
        }
        if (n == 0) {
            printf("Client %s disconnected\n", inet_ntoa(cli_addr.sin_addr));
            break;
        }
        printf("Received message from client %s: %s", inet_ntoa(cli_addr.sin_addr), buffer);
    }

    close(newsockfd);
    close(sockfd);
    return 0;
}