//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAX_MSG_SIZE 1024

int main() {
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[MAX_MSG_SIZE];
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    bzero((char*) &serv_addr, sizeof(serv_addr));
    portno = 8080;

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if(bind(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    listen(sockfd, 5);

    printf("Listening on port %d...\n", portno);

    while(1) {
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr*) &cli_addr, &clilen);

        if(newsockfd < 0) {
            perror("ERROR on accept");
            exit(1);
        }

        printf("Connection received from %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        bzero(buffer, MAX_MSG_SIZE);
        n = read(newsockfd, buffer, MAX_MSG_SIZE);
        if(n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }

        printf("Received message: %s\n", buffer);

        n = write(newsockfd, "I received your message", 23);
        if(n < 0) {
            perror("ERROR writing to socket");
            exit(1);
        }

        close(newsockfd);
    }

    close(sockfd);
    return 0;
}