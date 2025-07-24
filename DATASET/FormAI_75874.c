//FormAI DATASET v1.0 Category: Socket programming ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int server_socket, client_socket, read_size;
    struct sockaddr_in server_address, client_address;
    char buffer[BUFFER_SIZE];

    // Create socket
    server_socket = socket(AF_INET , SOCK_STREAM , 0);
    if (server_socket == -1) {
        perror("Error creating socket");
        return EXIT_FAILURE;
    }

    // Set server address
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8080);

    // Bind socket to address
    if (bind(server_socket, (struct sockaddr *)&server_address , sizeof(server_address)) == -1) {
        perror("Error binding socket");
        return EXIT_FAILURE;
    }

    // Listen for incoming connections
    if (listen(server_socket, 3) == -1) {
        perror("Error listening for connections");
        return EXIT_FAILURE;
    }

    // Accept incoming connection
    client_socket = accept(server_socket, (struct sockaddr *)&client_address, (socklen_t*)&client_address);

    if (client_socket == -1) {
        perror("Error accepting connection");
        return EXIT_FAILURE;
    }

    // Read message from client
    while ((read_size = recv(client_socket , buffer , BUFFER_SIZE , 0)) > 0) {
        // Process message
        printf("Received message: %s", buffer);

        // Send response
        write(client_socket , "I received your message", strlen("I received your message"));

        // Clear buffer
        memset(buffer, 0, sizeof(buffer));
    }

    if (read_size == 0) {
        puts("Client disconnected");
    } else if (read_size == -1) {
        perror("Error receiving message");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}