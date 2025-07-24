//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 4096
#define PORT 8080

int main(int argc, char const *argv[]) {

    int server_socket_fd, client_socket_fd;
    struct sockaddr_in server_address, client_address;
    unsigned int client_address_length = sizeof(client_address);

    // Create server socket
    server_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket_fd < 0) {
        perror("Error creating socket: ");
        return 1;
    }

    // Set server socket address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind server socket to the specified address and port
    if (bind(server_socket_fd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Error binding socket: ");
        return 1;
    }

    // Listen for incoming client connections
    if (listen(server_socket_fd, 10) < 0) {
        perror("Error listening for connections: ");
        return 1;
    }

    printf("Proxy server is now listening on port %d...\n", PORT);

    // Accept incoming client connections
    while (1) {
        client_socket_fd = accept(server_socket_fd, (struct sockaddr *) &client_address, &client_address_length);
        if (client_socket_fd < 0) {
            perror("Error accepting client connection: ");
            continue;
        }

        printf("Accepted a new client connection.\n");

        // Read client request
        char buffer[BUFFER_SIZE];
        ssize_t bytes_read = recv(client_socket_fd, buffer, BUFFER_SIZE, 0);
        if (bytes_read < 0) {
            perror("Error receiving data from client: ");
            close(client_socket_fd);
            continue;
        }

        printf("Received %ld bytes from client.\n", bytes_read);

        // Create connection to server
        int server_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
        if (server_socket_fd < 0) {
            perror("Error creating socket to server: ");
            close(client_socket_fd);
            continue;
        }

        // Set server socket address
        struct sockaddr_in server_address;
        server_address.sin_family = AF_INET;
        server_address.sin_port = htons(80);
        inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr);

        // Connect to server
        if (connect(server_socket_fd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
            perror("Error connecting to server: ");
            close(client_socket_fd);
            continue;
        }

        printf("Connected to server.\n");

        // Forward client request to server
        ssize_t bytes_sent = send(server_socket_fd, buffer, bytes_read, 0);
        if (bytes_sent < 0) {
            perror("Error sending data to server: ");
            close(client_socket_fd);
            close(server_socket_fd);
            continue;
        }

        printf("Sent %ld bytes to server.\n", bytes_sent);

        // Read server response
        bytes_read = recv(server_socket_fd, buffer, BUFFER_SIZE, 0);
        if (bytes_read < 0) {
            perror("Error receiving data from server: ");
            close(client_socket_fd);
            close(server_socket_fd);
            continue;
        }

        printf("Received %ld bytes from server.\n", bytes_read);

        // Forward server response to client
        bytes_sent = send(client_socket_fd, buffer, bytes_read, 0);
        if (bytes_sent < 0) {
            perror("Error sending data to client: ");
            close(client_socket_fd);
            close(server_socket_fd);
            continue;
        }

        printf("Sent %ld bytes to client.\n", bytes_sent);

        // Close client and server sockets
        close(client_socket_fd);
        close(server_socket_fd);
    }

    return 0;
}