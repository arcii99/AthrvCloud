//FormAI DATASET v1.0 Category: Simple Web Server ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BUFSIZE 1024

int main() {
    int sockfd, newsockfd, n;
    char buffer[BUFSIZE];
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t cli_len = sizeof(cli_addr);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Failed to create socket");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Failed to bind");
        exit(1);
    }

    listen(sockfd, 5);
    printf("Listening on port %d...\n", PORT);

    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &cli_len);
        if (newsockfd < 0) {
            perror("Failed to accept connection");
            exit(1);
        }

        printf("Connection accepted!\n");

        bzero(buffer, BUFSIZE);
        n = read(newsockfd, buffer, BUFSIZE - 1);
        if (n < 0) {
            perror("Failed to read from socket");
            exit(1);
        }

        printf("Received request:\n%s\n", buffer);

        char *response = "HTTP/1.1 200 OK\nContent-Length: 9\n\nHello, C!\n";
        n = write(newsockfd, response, strlen(response));
        if (n < 0) {
            perror("Failed to write to socket");
            exit(1);
        }

        printf("Response sent!\n");
        close(newsockfd);
    }

    close(sockfd);
    return 0;
}