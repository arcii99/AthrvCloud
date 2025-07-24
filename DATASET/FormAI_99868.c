//FormAI DATASET v1.0 Category: Client Server Application ; Style: secure
// Secure C Client-Server Application Example
// This program will create a TCP connection between a client and a server, send a message from client to server and receive a response from the server.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

#define SERVER_PORT 8080

// Function to handle error messages
void error(char *msg) {
    perror(msg);
    exit(1);
}

// Main function
int main() {
    int sockfd, connfd;
    struct sockaddr_in server_addr;
    char buffer[1024];
    char *message = "Hello from client";

    // Create socket file descriptor
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        error("Error creating socket");
    }

    // Initialize server address
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(SERVER_PORT);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        error("Error connecting to server");
    }

    // Send message to server
    if (send(sockfd, message, strlen(message), 0) < 0) {
        error("Error sending message to server");
    }

    // Receive response from server
    if (recv(sockfd, buffer, 1024, 0) < 0) {
        error("Error receiving response from server");
    }

    printf("Response from server: %s", buffer);

    // Close socket file descriptor
    close(sockfd);

    return 0;
}