//FormAI DATASET v1.0 Category: Simple Web Server ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char const *argv[]) {
    int socket_fd, new_socket_fd;
    struct sockaddr_in server_address, client_address;
    int opt = 1;
    int address_size = sizeof(server_address);

    // Creating socket file descriptor
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket option for address reuse
    if (setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // Set server address properties
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind socket to server address
    if (bind(socket_fd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(socket_fd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connection from client
    while (1) {
        if ((new_socket_fd = accept(socket_fd, (struct sockaddr *) &client_address, (socklen_t *) &address_size)) < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        // Read HTTP request from client
        char buffer[BUFFER_SIZE] = { 0 };
        read(new_socket_fd, buffer, BUFFER_SIZE);

        // Generate HTTP response
        char *response = "HTTP/1.1 200 OK\nContent-Type: text/plain\n\nHello, World!";

        // Send HTTP response to client
        send(new_socket_fd, response, strlen(response), 0);

        // Close connection
        close(new_socket_fd);
    }

    return 0;
}