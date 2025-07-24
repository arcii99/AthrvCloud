//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, newsockfd;
    socklen_t cli_addr_len;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    //create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }

    //initialize socket address
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    //bind socket to address
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error binding socket");
        exit(1);
    }

    //listen for incoming connections
    if (listen(sockfd, 5) < 0) {
        perror("Error listening for connections");
        exit(1);
    }

    printf("Server has started listening for incoming connections.\n");

    //accept incoming connections
    cli_addr_len = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &cli_addr_len);
    if (newsockfd < 0) {
        perror("Error accepting incoming connection");
        exit(1);
    }

    printf("Server has accepted an incoming connection.\n");

    //read and write messages
    while (1) {
        bzero(buffer, BUFFER_SIZE);
        n = read(newsockfd, buffer, BUFFER_SIZE);
        if (n < 0) {
            perror("Error reading from socket");
            exit(1);
        }
        printf("Received message from client: %s\n", buffer);

        n = write(newsockfd, buffer, strlen(buffer));
        if (n < 0) {
            perror("Error writing to socket");
            exit(1);
        }
        printf("Sent message to client: %s\n", buffer);
    }

    //close sockets
    close(newsockfd);
    close(sockfd);

    return 0;
}