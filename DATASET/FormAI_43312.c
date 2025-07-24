//FormAI DATASET v1.0 Category: Client Server Application ; Style: authentic
/* A simple C Client Server Application example program */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
 
#define BUFFER_SIZE 1024
 
int main() {
    int sockfd, newsockfd, portno, clientlen;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUFFER_SIZE];
 
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }
 
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = 5000;
 
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
 
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }
 
    listen(sockfd, 5);
    clientlen = sizeof(cli_addr);
 
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clientlen);
    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }
 
    bzero(buffer, BUFFER_SIZE);
    int n = read(newsockfd, buffer, BUFFER_SIZE - 1);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
 
    printf("Here is the message: %s\n", buffer);
 
    n = write(newsockfd, "I got your message\n", 19);
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }
 
    close(newsockfd);
    close(sockfd);
 
    return 0;
}