//FormAI DATASET v1.0 Category: Client Server Application ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080

int main() {
    int socket_fd, new_socket;
    struct sockaddr_in server_addr, client_addr;
    char buffer[1024] = {0};
    char *response = "Hello from Server!";
    int addrlen = sizeof(server_addr);

    // Create socket
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    // Set server information
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to bind the socket");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(socket_fd, 3) < 0) {
        perror("Failed to listen for incoming connections");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connection
    new_socket = accept(socket_fd, (struct sockaddr *)&client_addr, (socklen_t*)&addrlen);
    if (new_socket < 0) {
        perror("Failed to accept incoming connection");
        exit(EXIT_FAILURE);
    }

    // Send response to client
    send(new_socket, response, strlen(response), 0);

    // Read data from client
    read(new_socket, buffer, 1024);

    // Print client data
    printf("Client: %s\n", buffer);

    // Close socket
    close(socket_fd);

    return 0;
}