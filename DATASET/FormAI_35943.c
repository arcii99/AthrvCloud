//FormAI DATASET v1.0 Category: Socket programming ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(void) {
    int sockfd, newsockfd;
    socklen_t clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    /* create a socket */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }

    /* set up the server address */
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY; // use any available address
    serv_addr.sin_port = htons(8080); // listen on port 8080

    /* bind the socket to the address */
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error binding socket");
        exit(1);
    }

    /* listen for incoming connections */
    listen(sockfd, 5);

    clilen = sizeof(cli_addr);

    /* accept an incoming connection */
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0) {
        perror("Error on accept");
        exit(1);
    }

    /* read client message */
    bzero(buffer, 256);
    n = read(newsockfd, buffer, 255);
    if (n < 0) {
        perror("Error reading from socket");
        exit(1);
    }

    printf("Client message: %s\n", buffer);

    /* send message to client */
    n = write(newsockfd, "Acknowledge message received", 28);
    if (n < 0) {
        perror("Error writing to socket");
        exit(1);
    }

    /* close sockets */
    close(newsockfd);
    close(sockfd);

    return 0;
}