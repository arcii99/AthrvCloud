//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char const *argv[]) {

    // Create socket file descriptor
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    struct sockaddr_in server_address = {
        .sin_family = AF_INET,
        .sin_addr.s_addr = INADDR_ANY,
        .sin_port = htons(PORT)
    };

    // Bind server socket to the address and port
    if (bind(server_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Failed to bind socket");
        exit(EXIT_FAILURE);
    }

    // Listen on the server socket
    if (listen(server_fd, 1) < 0) {
        perror("Failed to listen on socket");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connections
    int client_socket_fd;
    struct sockaddr_in client_address;
    int address_length = sizeof(client_address);
    if ((client_socket_fd = accept(server_fd, (struct sockaddr *)&client_address, (socklen_t*)&address_length)) < 0) {
        perror("Failed to accept incoming connection");
        exit(EXIT_FAILURE);
    }

    printf("Connection accepted from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));


    // Receive data from client
    char buffer[BUFFER_SIZE] = {0};
    ssize_t bytes_received;
    while ((bytes_received = recv(client_socket_fd, buffer, BUFFER_SIZE, 0)) > 0) {
        printf("Received data: %s\n", buffer);

        // Send response to client
        char response[BUFFER_SIZE] = "Hello from server!";
        ssize_t bytes_sent = send(client_socket_fd, response, strlen(response), 0);

        if (bytes_sent == -1) {
            perror("Failed to send response");
            exit(EXIT_FAILURE);
        }
    }

    // Close client socket
    close(client_socket_fd);

    // Close server socket
    close(server_fd);

    return 0;
}