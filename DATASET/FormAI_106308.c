//FormAI DATASET v1.0 Category: Networking ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>

#define BUFFER_SIZE 1024

int server_socket_fd;

/**
 * Handle CTRL+C or SIGINT signal
 */
void handle_signal(int signal_number) {
    printf("\nReceived CTRL+C or SIGINT signal\n");
    close(server_socket_fd);
    exit(EXIT_SUCCESS);
}

int main() {
    char buffer[BUFFER_SIZE];

    // Create server socket
    server_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket_fd < 0) {
        printf("Failed to create server socket\n");
        exit(EXIT_FAILURE);
    }

    // Set server socket options
    int reuse_addr = 1;
    if (setsockopt(server_socket_fd, SOL_SOCKET, SO_REUSEADDR, &reuse_addr, sizeof(reuse_addr)) < 0) {
        perror("Failed to set server socket options");
        exit(EXIT_FAILURE);
    }

    // Bind server socket to port 8888
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8888);
    server_address.sin_addr.s_addr = INADDR_ANY;
    if (bind(server_socket_fd, (struct sockaddr*) &server_address, sizeof(server_address)) < 0) {
        printf("Failed to bind server socket to port 8888\n");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming client connections
    if (listen(server_socket_fd, 5) < 0) {
        printf("Failed to listen for incoming client connections\n");
        exit(EXIT_FAILURE);
    }

    // Handle CTRL+C or SIGINT signal
    signal(SIGINT, handle_signal);

    printf("Server is listening for incoming client connections...\n");

    // Accept incoming client connections
    while (1) {
        struct sockaddr_in client_address;
        socklen_t client_address_len = sizeof(client_address);

        int client_socket_fd = accept(server_socket_fd, (struct sockaddr*) &client_address, &client_address_len);
        if (client_socket_fd < 0) {
            printf("Failed to accept incoming client connection\n");
            continue;
        }

        printf("Accepted incoming client connection from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        // Receive message from client
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(client_socket_fd, buffer, BUFFER_SIZE, 0);
        if (bytes_received < 0) {
            printf("Failed to receive message from client\n");
            close(client_socket_fd);
            continue;
        }

        printf("Received message from client: %s\n", buffer);

        // Send message to client
        char* message = "Hello, client!";
        int bytes_sent = send(client_socket_fd, message, strlen(message), 0);
        if (bytes_sent < 0) {
            printf("Failed to send message to client\n");
            close(client_socket_fd);
            continue;
        }

        printf("Sent message to client: %s\n", message);

        // Close client socket
        close(client_socket_fd);
    }

    return EXIT_SUCCESS;
}