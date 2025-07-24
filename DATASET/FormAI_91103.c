//FormAI DATASET v1.0 Category: Networking ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MSG_MAX_LENGTH 1024
#define SERVER_PORT 9000

void error(char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    int sockfd, newsockfd, n;
    socklen_t clilen;
    char buffer[MSG_MAX_LENGTH];
    struct sockaddr_in serv_addr, cli_addr;

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    // set server address
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(SERVER_PORT);

    // bind socket
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR on binding");

    // listen for incoming connections
    listen(sockfd, 5);

    printf("Server running on port %d...\n", SERVER_PORT);

    // handle incoming connections
    clilen = sizeof(cli_addr);
    while (1) {
        // accept new connection
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0)
            error("ERROR on accept");

        // handle incoming message
        bzero(buffer, MSG_MAX_LENGTH);
        n = read(newsockfd, buffer, MSG_MAX_LENGTH-1);
        if (n < 0)
            error("ERROR reading from socket");

        printf("Received message: %s\n", buffer);

        // send response
        n = write(newsockfd, "Server received your message", 28);
        if (n < 0)
            error("ERROR writing to socket");

        // close connection
        close(newsockfd);
    }

    // close socket
    close(sockfd);

    return 0;
}