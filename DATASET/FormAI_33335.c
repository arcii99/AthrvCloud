//FormAI DATASET v1.0 Category: Client Server Application ; Style: complete
// This program is a simple client-server application that allows the client to send a message to the server, and the server responds with the message received.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define PORT 8080
#define MAX_BUFFER_SIZE 1024

// Helper function to handle errors
void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main() {
    int server_fd, client_fd;
    socklen_t client_size;
    struct sockaddr_in server_address, client_address;
    char buffer[MAX_BUFFER_SIZE] = {0};

    // Create a socket for the server
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        error("Socket creation failed");
    }

    // Configure the server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind the socket to the server address
    if (bind(server_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        error("Socket binding failed");
    }

    // Listen for incoming connections
    if (listen(server_fd, 1) < 0) {
        error("Failed to start listening for connections");
    }

    printf("Server is listening on port %d...\n", PORT);

    // Accept incoming client connections
    client_size = sizeof(client_address);
    if ((client_fd = accept(server_fd, (struct sockaddr *)&client_address, &client_size)) < 0) {
        error("Failed to accept client connection");
    }

    // Receive message from client
    if (recv(client_fd, buffer, MAX_BUFFER_SIZE, 0) < 0) {
        error("Failed to receive message from client");
    }

    printf("Received message from client: %s\n", buffer);

    // Send message back to client
    if (send(client_fd, buffer, strlen(buffer), 0) < 0) {
        error("Failed to send message to client");
    }

    printf("Message sent back to client\n");

    // Close the client and server sockets
    close(client_fd);
    close(server_fd);

    return 0;
}