//FormAI DATASET v1.0 Category: Socket programming ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    // Check if port number is provided
    if (argc < 2) {
        fprintf(stderr, "Port number not provided. Program terminated.\n");
        exit(1);
    }

    int sockfd, newsockfd, portno, n;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t clilen;

    // Create new socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("Error opening socket.");

    // Set server address
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    // Bind socket to address
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) 
        error("Error on binding.");

    // Listen for incoming connections
    listen(sockfd, 10);
    clilen = sizeof(cli_addr);

    // Accept incoming connections
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0) 
        error("Error on accept.");

    // Send and receive data
    bzero(buffer, 256);
    n = read(newsockfd, buffer, 255);
    if (n < 0) error("Error reading from socket.");
    printf("Message received: %s\n", buffer);
    n = write(newsockfd, "I got your message", 18);
    if (n < 0) error("Error writing to socket.");

    close(newsockfd);
    close(sockfd);

    return 0;
}