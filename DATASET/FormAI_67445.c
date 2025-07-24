//FormAI DATASET v1.0 Category: Simple Web Server ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    int port = 8080;
    int sockfd, newsockfd, status, yes = 1;
    socklen_t clilen;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[1024];
    char *response = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<html><header><title>Hello World</title></header><body><h1>Hello World!</h1></body></html>";
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error on binding");
        exit(1);
    }
    if (listen(sockfd, 5) < 0) {
        perror("Error on listen");
        exit(1);
    }
    printf("Server listening on port %d...\n", port);
    while (1) {
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0) {
            perror("Error on accept");
            exit(1);
        }
        bzero(buffer, 1024);
        status = read(newsockfd, buffer, 1023);
        if (status < 0) {
            perror("Error reading from socket");
            exit(1);
        }
        if (strstr(buffer, "GET / ") != NULL) {
            write(newsockfd, response, strlen(response));
        } else {
            write(newsockfd, response, strlen(response));
        }
        close(newsockfd);
    }
    close(sockfd);
    return 0;
}