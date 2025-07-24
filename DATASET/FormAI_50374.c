//FormAI DATASET v1.0 Category: Client Server Application ; Style: high level of detail
// This is a basic example of a C Client-Server Application 
// that uses the socket programming library

// Header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

// Constants
#define PORT 8080
#define BUFFER_SIZE 1024

// Function to handle errors
void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main() {

    // Variables
    int sockfd, connfd;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in serv_addr, cli_addr;
    int opt = 1;
    int addr_len = sizeof(cli_addr);

    // Creating socket file descriptor
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket.");
    }

    // Setting socket options
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                   &opt, sizeof(opt))) {
        error("Error setting socket options.");
    }

    // Setting up server address structure
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    // Binding socket to server address
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("Error binding socket to server address.");
    }

    // Listening for incoming connections
    if (listen(sockfd, 1) < 0) {
        error("Error while listening for incoming connections.");
    }

    printf("Server listening on port %d...\n", PORT);

    // Accepting incoming connections
    connfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t*)&addr_len);
    if (connfd < 0) {
        error("Error while accepting incoming connection.");
    }

    // Receiving message from client
    bzero(buffer, BUFFER_SIZE);
    read(connfd, buffer, BUFFER_SIZE);

    printf("Client: %s\n", buffer);

    // Sending response to client
    bzero(buffer, BUFFER_SIZE);
    strcpy(buffer, "Hello from server.");
    write(connfd, buffer, strlen(buffer));

    // Closing connections
    close(connfd);
    close(sockfd);

    return 0;
}