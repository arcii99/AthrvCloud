//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define MAX_PENDING 5
#define BUFFER_SIZE 1024

int main() {
    int server_fd, new_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    char buffer[BUFFER_SIZE] = {0};
    const char *response = "Hello from server!";

    // Create socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Prepare server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind socket to address and port
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error binding to address and port");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, MAX_PENDING) == -1) {
        perror("Error listening for incoming connections");
        exit(EXIT_FAILURE);
    }

    while (1) {
        // Accept incoming connection
        new_socket = accept(server_fd, (struct sockaddr *)&client_addr, &client_addr_len);
        if (new_socket == -1) {
            perror("Error accepting incoming connection");
            exit(EXIT_FAILURE);
        }

        // Read data from client
        if (recv(new_socket, buffer, BUFFER_SIZE, 0) == -1) {
            perror("Error receiving data from client");
            close(new_socket);
            continue;
        }

        printf("Received data from client: %s\n", buffer);

        // Send response to client
        if (send(new_socket, response, strlen(response), 0) == -1) {
            perror("Error sending response to client");
            close(new_socket);
            continue;
        }

        printf("Sent response to client: %s\n", response);

        // Close connection with client
        close(new_socket);
    }

    // Close server socket
    close(server_fd);

    return 0;
}