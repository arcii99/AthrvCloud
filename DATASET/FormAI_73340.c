//FormAI DATASET v1.0 Category: Simple Web Server ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8000
#define BUFFER_SIZE 1024

int main(int argc, char const *argv[]) {
    int server_socket, client_socket, read_size;
    struct sockaddr_in server_address, client_address;
    socklen_t addr_size = sizeof(struct sockaddr_in);
    char buffer[BUFFER_SIZE], response[BUFFER_SIZE];

    // Create server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        fprintf(stderr, "Failed to create socket\n");
        exit(EXIT_FAILURE);
    }

    // Configure server socket
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind server socket
    if (bind(server_socket, (struct sockaddr *) &server_address, addr_size) == -1) {
        fprintf(stderr, "Failed to bind socket\n");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) == -1) {
        fprintf(stderr, "Failed to listen for connections\n");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    // Accept incoming connections
    while ((client_socket = accept(server_socket, (struct sockaddr *) &client_address, &addr_size))) {
        // Read incoming request
        read_size = recv(client_socket, buffer, BUFFER_SIZE, 0);
        printf("Received request:\n%s\n", buffer);

        // Generate response
        snprintf(response, BUFFER_SIZE, "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\nHello, World!");

        // Send response
        if (send(client_socket, response, strlen(response), 0) == -1) {
            fprintf(stderr, "Failed to send response\n");
            exit(EXIT_FAILURE);
        }

        // Close client socket
        close(client_socket);
    }

    // Close server socket
    close(server_socket);

    return EXIT_SUCCESS;
}