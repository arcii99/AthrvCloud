//FormAI DATASET v1.0 Category: Client Server Application ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    char buffer[BUFFER_SIZE];

    // Create server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Error creating server socket");
        exit(EXIT_FAILURE);
    }

    // Initialize server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(8080);

    // Bind server socket to server address
    if (bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        perror("Error binding server socket to address");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming client connections
    if (listen(server_socket, 1) < 0) {
        perror("Error listening for incoming client connections");
        exit(EXIT_FAILURE);
    }

    printf("Waiting for incoming client connections...\n");

    while (1) {
        socklen_t client_address_length = sizeof(client_address);

        // Accept incoming client connection
        client_socket = accept(server_socket, (struct sockaddr*)&client_address, &client_address_length);
        if (client_socket < 0) {
            perror("Error accepting incoming client connection");
            exit(EXIT_FAILURE);
        }

        printf("Received connection from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        // Receive data from client
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (bytes_received < 0) {
            perror("Error receiving data from client");
            exit(EXIT_FAILURE);
        }

        printf("Received data from client: %s", buffer);

        // Send data to client
        const char* message = "Hello from server!\n";
        int bytes_sent = send(client_socket, message, strlen(message), 0);
        if (bytes_sent < 0) {
            perror("Error sending data to client");
            exit(EXIT_FAILURE);
        }

        printf("Sent data to client: %s", message);

        // Close client socket
        close(client_socket);
    }

    // Close server socket
    close(server_socket);

    return 0;
}