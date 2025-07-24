//FormAI DATASET v1.0 Category: Simple Web Server ; Style: Sherlock Holmes
/* The Adventure of the Simple Web Server */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char *argv[]) {

    int sockfd, newsockfd, portno, clilen, n;
    char buffer[1024];

    struct sockaddr_in serv_addr, cli_addr;

    if (argc < 2) {
        fprintf(stderr,"ERROR, no port provided\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    listen(sockfd,5);
    clilen = sizeof(cli_addr);

    printf("The Adventure of the Simple Web Server\n\n");

    while (1) {

        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0) {
            perror("ERROR on accept");
            exit(1);
        }

        bzero(buffer,1024);

        n = read(newsockfd,buffer,1023);
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }

        printf("Request: %s\n",buffer);

        char response[2048];
        sprintf(response,"HTTP/1.0 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE html>\n<html>\n<head>\n<title>The Adventure of the Simple Web Server</title>\n</head>\n<body>\n<h1>The Adventure of the Simple Web Server</h1>\n<p>We've got a request for: %s</p>\n<p>But unfortunately, we haven't implemented that yet. Please come back later.</p>\n</body>\n</html>\n",buffer);

        n = write(newsockfd,response,strlen(response));
        if (n < 0) {
            perror("ERROR writing to socket");
            exit(1);
        }

        close(newsockfd);
    }

    close(sockfd);

    return 0;
}