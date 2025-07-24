//FormAI DATASET v1.0 Category: Simple Web Server ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT    8080
#define BUF_SIZE    1024

int main(int argc, char *argv[]) {

    int sockfd, newsockfd;
    socklen_t clilen;
    char buffer[BUF_SIZE];
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);

        if (newsockfd < 0) {
            perror("ERROR on accept");
            exit(1);
        }

        bzero(buffer, BUF_SIZE);
        
        n = read(newsockfd, buffer, BUF_SIZE);

        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }

        printf("Received a request from client: %s\n", buffer);

        // HTTP response message
        char *response = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<html><body><h1>Hello World!</h1></body></html>\r\n";

        n = write(newsockfd, response, strlen(response));
        if (n < 0) { 
            perror("ERROR writing to socket");
            exit(1);
        }

        close(newsockfd);
    }

    close(sockfd);
    return 0;
}