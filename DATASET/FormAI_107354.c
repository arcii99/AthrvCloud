//FormAI DATASET v1.0 Category: Chat server ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {

    int server_fd, new_socket, valread;
    struct sockaddr_in address = {0};
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    char message[BUFFER_SIZE] = {0};
    bool quit_server = false;

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options to reuse address and port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Set address family, IP address, and port of the server
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to the server address
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 1) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Accept client connection
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    // Send welcome message to client
    sprintf(message, "Welcome to the chat server! Type 'quit' at any time to exit.\n");
    send(new_socket, message, strlen(message), 0);

    while (!quit_server) {
        
        // Read incoming message from client
        valread = read(new_socket, buffer, BUFFER_SIZE);

        // Check if client wants to quit
        if (strcmp(buffer, "quit\n") == 0) {
            sprintf(message, "Goodbye!\n");
            send(new_socket, message, strlen(message), 0);
            break;
        }

        // Echo message back to client
        send(new_socket, buffer, strlen(buffer), 0);

        // Clear buffer and message
        memset(buffer, 0, BUFFER_SIZE);
        memset(message, 0, BUFFER_SIZE);

    }

    // Close server and client sockets
    close(new_socket);
    close(server_fd);

    return 0;
    
}