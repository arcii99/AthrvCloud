//FormAI DATASET v1.0 Category: Chat server ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

#define PORTNO 8000
#define BUFFER_SIZE 256

int main(){
    int sockfd, newsockfd, clilen;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUFFER_SIZE];

    // initialize socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0){
        perror("Error creating socket");
        exit(1);
    }

    // set up server address
    bzero((char *)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORTNO);
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    // bind socket to server address
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0){
        perror("Error binding socket");
        exit(1);
    }

    listen(sockfd, 5);

    clilen = sizeof(cli_addr);

    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
    if (newsockfd < 0){
        perror("Error accepting connection");
        exit(1);
    }

    bzero(buffer, BUFFER_SIZE);

    int n = read(newsockfd, buffer, BUFFER_SIZE);
    if (n < 0){
        perror("Error reading from socket");
        exit(1);
    }

    printf("Here is the message: %s", buffer);

    n = write(newsockfd, "I got your message", 18);
    if (n < 0){
        perror("Error writing to socket");
        exit(1);
    }

    close(newsockfd);
    close(sockfd);

    return 0;
}