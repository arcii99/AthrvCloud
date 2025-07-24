//FormAI DATASET v1.0 Category: Client Server Application ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define PORT 5000
#define MAX_MSG_LENGTH 2048

void handle_connection(int client_socket) {
    char buffer[MAX_MSG_LENGTH];
    int bytes_received;

    while (1) {
        // Receive message from client
        memset(buffer, 0, MAX_MSG_LENGTH);
        bytes_received = recv(client_socket, buffer, MAX_MSG_LENGTH, 0);

        if (bytes_received <= 0) {
            // Client disconnected
            break;
        }

        printf("Received message: %s\n", buffer);

        // Echo message back to client
        send(client_socket, buffer, strlen(buffer), 0);
    }

    close(client_socket);
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    // Create server socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Failed to create server socket");
        exit(EXIT_FAILURE);
    }

    // Bind server socket to port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Failed to bind server socket");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 3) < 0) {
        perror("Error while listening for incoming connections");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d\n", PORT);

    while (1) {
        // Accept incoming connection and handle it in a new thread
        if ((client_socket = accept(server_socket, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
            perror("Failed to accept incoming connection");
            exit(EXIT_FAILURE);
        }

        printf("New client connection: %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

        if (!fork()) {
            // Child process
            handle_connection(client_socket);
            _exit(EXIT_SUCCESS);
        }
    }

    return 0;
}