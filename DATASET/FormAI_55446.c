//FormAI DATASET v1.0 Category: Networking ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 1024
#define DEFAULT_PORT 8080

void error(char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[MAX_BUFFER_SIZE];
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    /* Create a TCP socket */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");

    /* Initialize server address information */
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = DEFAULT_PORT;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    /* Bind socket to server address */
    if (bind(sockfd, (struct sockaddr *) &serv_addr,
            sizeof(serv_addr)) < 0) 
        error("ERROR on binding");

    /* Start listening for incoming connections */
    listen(sockfd, 5);
    printf("Waiting for client connections...\n");

    clilen = sizeof(cli_addr);
    /* Accept incoming connection */
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0) 
        error("ERROR on accept");

    printf("Client connected from %s:%d\n",
           inet_ntoa(cli_addr.sin_addr),
           ntohs(cli_addr.sin_port));

    /* Clear buffer */
    bzero(buffer, MAX_BUFFER_SIZE);
    /* Read data from client */
    n = read(newsockfd, buffer, MAX_BUFFER_SIZE);
    if (n < 0) 
        error("ERROR reading from socket");

    printf("Message received from client: %s\n", buffer);

    /* Send data to client */
    n = write(newsockfd, "I got your message", 18);
    if (n < 0) 
        error("ERROR writing to socket");

    /* Close sockets */
    close(newsockfd);
    close(sockfd);

    return 0;
}