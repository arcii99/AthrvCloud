//FormAI DATASET v1.0 Category: Networking ; Style: unmistakable
// This program demonstrates a simple client-server network communication using TCP protocol
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 9001  // Port to use for communication

// Function to handle errors
void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main() {
    int sockfd, newsockfd, client_len;
    char buffer[1024];
    struct sockaddr_in server_address, client_address;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);  // Create the socket
    if (sockfd < 0) {
        error("Error opening socket");
    }

    // Set the server address
    bzero((char*) &server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind the socket to the address
    if (bind(sockfd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        error("Error binding socket");
    }

    // Listen for incoming connections
    listen(sockfd, 5);

    printf("Waiting for client connection...\n");

    client_len = sizeof(client_address);
    // Accept incoming connection
    newsockfd = accept(sockfd, (struct sockaddr *) &client_address, &client_len);
    if (newsockfd < 0) {
        error("Error accepting connection");
    }

    printf("Client connected successfully...\n");

    // Start communication with client
    while(1) {
        bzero(buffer, 1024);
        // Read data from the client socket
        int n = read(newsockfd, buffer, 1024);
        if (n < 0) {
            error("Error reading from socket");
        }

        // Print the message received from the client
        printf("[CLIENT] %s", buffer);

        // Send message to the client
        printf("[SERVER] Enter message to send to client: ");
        bzero(buffer, 1024);
        fgets(buffer, 1024, stdin);
        n = write(newsockfd, buffer, strlen(buffer));
        if (n < 0) {
            error("Error writing to socket");
        }
    }

    close(newsockfd);
    close(sockfd);

    return 0;
}