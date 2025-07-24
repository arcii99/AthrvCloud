//FormAI DATASET v1.0 Category: Socket programming ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFF_SIZE 1024

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFF_SIZE] = {0};
    char *message = "Hello from the server!";

    // Create the server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(-1);
    }

    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                   &opt, sizeof(opt))) {
        perror("Set socket option failed");
        exit(-1);
    }

    // Bind socket to address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);

    if (bind(server_fd, (struct sockaddr*) &address, sizeof(address)) < 0) {
        perror("Socket bind failed");
        exit(-1);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(-1);
    }

    printf("Server listening on port 8080...\n");

    // Accept incoming connections
    if ((new_socket = accept(server_fd, (struct sockaddr*) &address,
                             (socklen_t*) &addrlen)) < 0) {
        perror("Accept failed");
        exit(-1);
    }

    printf("Connection accepted!\n");

    // Send message to client
    send(new_socket, message, strlen(message), 0);
    printf("Hello message sent\n");

    // Receive client message
    read(new_socket, buffer, BUFF_SIZE);
    printf("Client: %s\n", buffer);

    // Close sockets
    close(new_socket);
    close(server_fd);

    return 0;
}