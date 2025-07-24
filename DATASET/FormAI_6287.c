//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 256
#define PORT 8080

int main(int argc, char *argv[]) {
    int sockfd, csockfd, ret;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUF_SIZE];

    // Create server socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating server socket");
        exit(EXIT_FAILURE);
    }

    // Bind server socket to port
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    ret = bind(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr));
    if (ret < 0) {
        perror("Error binding server socket");
        exit(EXIT_FAILURE);
    }

    // Listen for client connections
    listen(sockfd, 5);
    printf("Waiting for incoming connections on port %d...\n", PORT);

    // Accept incoming client connection
    socklen_t client_size = sizeof(client_addr);
    csockfd = accept(sockfd, (struct sockaddr *) &client_addr, &client_size);
    if (csockfd < 0) {
        perror("Error accepting client connection");
        exit(EXIT_FAILURE);
    }

    // Receive and print message from client
    bzero(buffer, BUF_SIZE);
    ret = recv(csockfd, buffer, BUF_SIZE, 0);
    if (ret < 0) {
        perror("Error receiving message from client");
        exit(EXIT_FAILURE);
    }
    printf("Received message from client: %s\n", buffer);

    // Send response message to client
    char *response = "Hello from server!";
    ret = send(csockfd, response, strlen(response), 0);
    if (ret < 0) {
        perror("Error sending message to client");
        exit(EXIT_FAILURE);
    }

    // Close socket connections
    close(csockfd);
    close(sockfd);

    return 0;
}