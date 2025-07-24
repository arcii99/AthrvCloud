//FormAI DATASET v1.0 Category: Socket programming ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, n;
    struct sockaddr_in servaddr, cliaddr;
    socklen_t clilen;
    char buffer[1024];

    // creating socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        error("ERROR opening socket");
    }

    // clear the server address structure
    bzero((char *) &servaddr, sizeof(servaddr));

    // assigning IP, port and address family
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    // binding server socket
    if (bind(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        error("ERROR on binding");
    }

    // listen on the server socket
    listen(sockfd, 5);

    clilen = sizeof(cliaddr);

    // accept connection from a client
    if ((newsockfd = accept(sockfd, (struct sockaddr *) &cliaddr, &clilen)) < 0) {
        error("ERROR on accept");
    }

    // read data from the client
    bzero(buffer, 1024);
    if ((n = recv(newsockfd, buffer, 1024, 0)) < 0) {
        error("ERROR reading from socket");
    }

    // display the data received from the client
    printf("Here is the message: %s\n", buffer);

    // send response to the client
    char* response = "Thank you for your message";
    if ((n = send(newsockfd, response, strlen(response), 0)) < 0) {
        error("ERROR writing to socket");
    }

    // close sockets
    close(newsockfd);
    close(sockfd);

    return 0;
}