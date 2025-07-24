//FormAI DATASET v1.0 Category: Simple Web Server ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 8080

void error(char *msg)
{
    perror(msg);
    exit(1);
}

int main()
{
    int sockfd, newsockfd, clilen, childpid, n;
    char buffer[255];
    struct sockaddr_in serv_addr, cli_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("Error opening socket");

    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        error("Error on binding");

    listen(sockfd,5);

    clilen = sizeof(cli_addr);

    while(1) {
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0)
            error("Error on accept");

        childpid = fork();
        if (childpid < 0)
            error("Error creating child process");

        if (childpid == 0) {
            close(sockfd);

            bzero(buffer,255);

            n = read(newsockfd,buffer,255);
            if (n < 0)
                error("Error reading from socket");

            printf("Here is the message: %s\n",buffer);

            n = write(newsockfd,"HTTP/1.1 200 OK\nContent-Type: text/html\n\n<html><body><h1>Hello, world!</h1></body></html>",127);
            if (n < 0)
                error("Error writing to socket");

            close(newsockfd);
            exit(0);
        }
        else
            close(newsockfd);
    }

    return 0;
}