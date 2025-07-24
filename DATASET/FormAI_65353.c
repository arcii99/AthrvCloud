//FormAI DATASET v1.0 Category: Simple Web Server ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>

int main()
{
    int sockfd, newsockfd, portno, clilen;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[1024];
    pid_t pid;
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
    if (bind(sockfd, (struct sockaddr *) &serv_addr,
             sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }
    listen(sockfd,5);
    clilen = sizeof(cli_addr);
    while(1) {
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0) {
            perror("ERROR on accept");
            exit(1);
        }
        pid = fork();
        if (pid < 0) {
            perror("ERROR on fork");
            exit(1);
        }
        if (pid == 0) {
            close(sockfd);
            bzero(buffer,1024);
            n = read(newsockfd,buffer,1024);
            if (n < 0) {
                perror("ERROR reading from socket");
                exit(1);
            }
            printf("Here is the request:\n%s\n",buffer);
            n = write(newsockfd,"HTTP/1.1 200 OK\nContent-Type: text/html\n\n<!DOCTYPE html><html><body><h1>Welcome to my Simple Web Server!</h1></body></html>",122);
            if (n < 0) {
                perror("ERROR writing to socket");
                exit(1);
            }
            exit(0);
        }
        else {
            close(newsockfd);
        }
    }
    return 0;
}