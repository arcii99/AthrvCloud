//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define PORT 8080
#define MAX_BUFFER_SIZE 1024

int main()
{
    int sockfd, newsockfd, clilen, n;
    char buffer[MAX_BUFFER_SIZE];
    struct sockaddr_in serv_addr, cli_addr;
 
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("Error opening socket");
        exit(1);
    }
 
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);
 
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("Error on binding");
        exit(1);
    }
 
    listen(sockfd, 5);
    clilen = sizeof(cli_addr);
 
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0)
    {
        perror("Error on accept");
        exit(1);
    }
 
    bzero(buffer, MAX_BUFFER_SIZE);
    n = read(newsockfd, buffer, MAX_BUFFER_SIZE - 1);
    if (n < 0)
    {
        perror("Error reading from socket");
        exit(1);
    }
 
    printf("Received message: %s\n", buffer);
 
    n = write(newsockfd, "I got your message", 18);
    if (n < 0)
    {
        perror("Error writing to socket");
        exit(1);
    }

    close(newsockfd);
    close(sockfd);

    return 0;
}