//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT    5000
#define BUFFER  1024

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, status;
    socklen_t clilen;
    char buffer[BUFFER];
    struct sockaddr_in serv_addr, cli_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR: Could not create socket");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    status = bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
    if (status < 0) {
        perror("ERROR: Could not bind socket");
        exit(1);
    }

    listen(sockfd, 5);

    printf("Server is listening on port %d...\n", PORT);

    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0) {
        perror("ERROR: Could not accept connection");
        exit(1);
    }

    printf("Client connected from %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

    while (1) {
        memset(buffer, 0, BUFFER);
        status = read(newsockfd, buffer, BUFFER - 1);
        if (status < 0) {
            perror("ERROR: Could not read from socket");
            exit(1);
        }

        printf("Received message from client: %s\n", buffer);

        if (strcmp(buffer, "quit") == 0) {
            break;
        }

        status = write(newsockfd, "OK", 2);
        if (status < 0) {
            perror("ERROR: Could not write to socket");
            exit(1);
        }

        printf("Sent message to client: OK\n");
    }

    printf("Closing connection...\n");

    close(newsockfd);
    close(sockfd);

    return 0;
}