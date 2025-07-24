//FormAI DATASET v1.0 Category: Simple Web Server ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

int main(){
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[1024];
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = 8080;

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    while(1){
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);

        if(newsockfd < 0) {
            perror("ERROR on accept");
            exit(1);
        }

        bzero(buffer, 1024);
        n = read(newsockfd, buffer, 1023);

        if(n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }

        char http_response[1024];
        bzero(http_response, 1024);
        sprintf(http_response, "HTTP/1.1 200 OK\r\nContent-Length: %d\r\nContent-Type: text/html\r\n\r\n<html><body><h1>Hello! This is a simple web server example.</h1></body></html>", strlen("<html><body><h1>Hello! This is a simple web server example.</h1></body></html>"));

        n = write(newsockfd, http_response, strlen(http_response));
        if (n < 0) {
            perror("ERROR writing to socket");
            exit(1);
        }

        close(newsockfd);
    }

    close(sockfd);
    return 0;
}