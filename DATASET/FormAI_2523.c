//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#define PORT 8080
#define MAX_MESSAGE_LEN 1024

int main() {
    int sockfd, newsockfd, clilen, n;
    char buffer[MAX_MESSAGE_LEN];
    struct sockaddr_in serv_addr, cli_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error on binding");
        exit(1);
    }

    listen(sockfd, 1);
    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0) {
        perror("Error on accept");
        exit(1);
    }

    printf("Connection established! Say hello to your new friend.\n");

    while (1) {
        bzero(buffer, MAX_MESSAGE_LEN);
        n = read(newsockfd, buffer, MAX_MESSAGE_LEN);
        if (n < 0) {
            perror("Error reading from socket");
            exit(1);
        }
        printf("Client: %s\n", buffer);
        printf("Server: ");
        bzero(buffer, MAX_MESSAGE_LEN);
        fgets(buffer, MAX_MESSAGE_LEN, stdin);
        n = write(newsockfd, buffer, strlen(buffer));
        if (n < 0) {
            perror("Error writing to socket");
            exit(1);
        }
        if (strncmp(buffer, "bye", 3) == 0)
            break;
    }

    close(newsockfd);
    close(sockfd);

    return 0;
}