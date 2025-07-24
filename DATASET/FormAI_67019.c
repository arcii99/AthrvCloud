//FormAI DATASET v1.0 Category: Client Server Application ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PENDING 10
#define MAX_LINE 1024
#define PORT 8080

/* Error handling function */
void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main() {
    int sockfd, newsockfd, n;
    socklen_t clilen;
    char buffer[MAX_LINE];
    struct sockaddr_in serv_addr, cli_addr;

    /* Create a TCP socket */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    /* Set up the server address structure */
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    /* Bind the socket to the port */
    if (bind(sockfd, (struct sockaddr *) &serv_addr,
             sizeof(serv_addr)) < 0)
        error("ERROR on binding");

    /* Listen for incoming connections */
    listen(sockfd, MAX_PENDING);

    /* Wait for a client to connect */
    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0)
        error("ERROR on accept");

    /* Read client message */
    bzero(buffer, MAX_LINE);
    n = read(newsockfd, buffer, MAX_LINE);
    if (n < 0)
        error("ERROR reading from socket");
    printf("Message from client: %s\n", buffer);

    /* Write response to the client */
    n = write(newsockfd, "I got your message", 18);
    if (n < 0)
        error("ERROR writing to socket");

    /* Close the socket */
    close(newsockfd);
    close(sockfd);

    return 0;
}