//FormAI DATASET v1.0 Category: Networking ; Style: minimalist
// Minimalist C Networking Example Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MESSAGE_BUFFER_SIZE 1024
#define SERVER_PORT 8080

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    char message_buffer[MESSAGE_BUFFER_SIZE];

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Error: Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Bind socket
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(SERVER_PORT);
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Error: Socket binding failed");
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(server_socket, 3) < 0) {
        perror("Error: Socket listening failed");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d\n", SERVER_PORT);

    // Accept incoming connections
    socklen_t client_address_size = sizeof(client_address);
    client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_size);
    if (client_socket < 0) {
        perror("Error: Could not accept client connection");
        exit(EXIT_FAILURE);
    }

    // Receive message from client
    memset(message_buffer, 0, MESSAGE_BUFFER_SIZE);
    int message_length = read(client_socket, message_buffer, MESSAGE_BUFFER_SIZE);
    if (message_length < 0) {
        perror("Error: Could not receive message from client");
        exit(EXIT_FAILURE);
    }
    printf("Received message from client: %s\n", message_buffer);

    // Send message to client
    char *server_message = "Hello from server!";
    int server_message_length = strlen(server_message);
    int send_status = send(client_socket, server_message, server_message_length, 0);
    if (send_status < 0) {
        perror("Error: Could not send message to client");
        exit(EXIT_FAILURE);
    }

    // Close sockets
    close(client_socket);
    close(server_socket);

    return 0;
}