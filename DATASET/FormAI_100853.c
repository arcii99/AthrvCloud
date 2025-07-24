//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_MESSAGE_SIZE 1024

int main() {
    int server_socket_fd, new_socket_fd;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[MAX_MESSAGE_SIZE] = {0};

    // Creating socket file descriptor
    if ((server_socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Configure settings of the server address struct
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to the IP address and port specified in address
    if (bind(server_socket_fd, (struct sockaddr *) &address, sizeof(address)) < 0) {
        perror("Binding failed");
        exit(EXIT_FAILURE);
    }

    // Listen for connections from clients
    if (listen(server_socket_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    while (true) {
        // Accept incoming connection from client
        if ((new_socket_fd = accept(server_socket_fd, (struct sockaddr *) &address, (socklen_t *) &addrlen)) < 0) {
            perror("Failed to accept connection from client");
            exit(EXIT_FAILURE);
        }

        printf("New client connection accepted: %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

        // Read data from the client
        int bytes_read = read(new_socket_fd, buffer, MAX_MESSAGE_SIZE);

        if (bytes_read < 0) {
            perror("Failed to read data from client");
            exit(EXIT_FAILURE);
        }

        printf("Data received from client (%d bytes): %s\n", bytes_read, buffer);

        // Send message back to client
        const char* message = "Hello from server!";
        send(new_socket_fd, message, strlen(message), 0);

        printf("Message sent to client: %s\n", message);

        // Close the client socket connection
        close(new_socket_fd);
    }

    // Close the server socket
    close(server_socket_fd);

    return 0;
}