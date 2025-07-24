//FormAI DATASET v1.0 Category: Chat server ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

// Function to process client requests
void process_client_request(int client_socket) {
    char buffer[BUFFER_SIZE] = {0};
    int read_size;

    // Read client request
    while ((read_size = read(client_socket, buffer, BUFFER_SIZE)) > 0) {
        printf("[CLIENT] %s\n", buffer);

        // Prepare server response
        char *response = "Server received client request!";

        // Send response to client
        write(client_socket, response, strlen(response));
        printf("[SERVER] %s\n", response);

        // Clear buffer
        memset(buffer, 0, BUFFER_SIZE);
    }

    // Client disconnected
    printf("[CLIENT DISCONNECTED]\n");
}

int main(int argc, char const *argv[]) {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    bool is_client_connected = false;

    // Create server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket < 0) {
        perror("Failed to create server socket!");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind server socket to the configured address and port
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Failed to bind server socket to port!");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming client connections
    if (listen(server_socket, 3) < 0) {
        perror("Failed to start listening for incoming client connections!");
        exit(EXIT_FAILURE);
    }

    // Accept incoming client connections
    while (true) {
        printf("[SERVER] Waiting for incoming client connection...\n");

        socklen_t client_address_length = sizeof(client_address);
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_length);

        if (client_socket < 0) {
            perror("Failed to accept incoming client connection!");
            exit(EXIT_FAILURE);
        }

        printf("[SERVER] Client connected: %s:%d\n", 
                inet_ntoa(client_address.sin_addr), 
                ntohs(client_address.sin_port));

        // Process client requests
        process_client_request(client_socket);

        // Close client socket
        close(client_socket);
    }

    return 0;
}