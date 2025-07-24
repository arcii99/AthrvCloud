//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024
#define PORT 8080

void handle_connection(int client_fd) {

    char buffer[BUFFER_SIZE] = {0};

    // Receive data from client
    int valread = read(client_fd, buffer, BUFFER_SIZE);
    if (valread <= 0) {
        return;
    }

    // Print received data
    printf("Received data: %s\n", buffer);

    // Send response back to client
    char* response = "Hello from server!";
    send(client_fd, response, strlen(response), 0);

    // Recursively handle more connections
    handle_connection(client_fd);
}

int main() {

    // Create socket
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        printf("Error creating socket\n");
        exit(EXIT_FAILURE);
    }

    // Set server address
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind socket to address
    if (bind(server_fd, (struct sockaddr*) &server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 1) == -1) {
        printf("Error listening for connections\n");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", PORT);

    // Accept incoming connections
    int client_fd = accept(server_fd, NULL, NULL);
    if (client_fd == -1) {
        printf("Error accepting connection\n");
        exit(EXIT_FAILURE);
    }

    // Recursively handle connections
    handle_connection(client_fd);

    // Close socket
    close(server_fd);

    return 0;
}