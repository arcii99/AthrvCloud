//FormAI DATASET v1.0 Category: Simple Web Server ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_MESSAGE_LEN 1024

int main(int argc, char **argv) {
    int port = 8080;
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char message[MAX_MESSAGE_LEN] = {0};
    char *response = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello World!";

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options (reuse address)
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // Bind socket to address and port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    // Loop to handle incoming connections
    while (1) {
        // Accept incoming connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        // Read message from client
        if (read(new_socket, message, MAX_MESSAGE_LEN) < 0) {
            perror("Read failed");
            exit(EXIT_FAILURE);
        }

        // Print message to console
        printf("Received message: %s\n", message);

        // Send response back to client
        if (send(new_socket, response, strlen(response), 0) != strlen(response)) {
            perror("Send failed");
            exit(EXIT_FAILURE);
        }

        // Close socket and reset message buffer
        close(new_socket);
        memset(message, 0, MAX_MESSAGE_LEN);
    }

    return 0;
}