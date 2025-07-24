//FormAI DATASET v1.0 Category: Networking ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 5000
#define MAX_BUFFER_SIZE 1024

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[MAX_BUFFER_SIZE] = {0};

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed!");
        exit(EXIT_FAILURE);
    }

    // Setting socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Error setting socket options!");
        exit(EXIT_FAILURE);
    }

    // Setting server address properties
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Binding the socket to the port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("Socket binding failed!");
        exit(EXIT_FAILURE);
    }

    // Start listening for connections
    if (listen(server_fd, 3) < 0) {
        perror("Error while trying to listen for connections!");
        exit(EXIT_FAILURE);
    }

    // Accept a client's connection request
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
        perror("Error while trying to accept connection!");
        exit(EXIT_FAILURE);
    }

    // Receive message from client
    if (read(new_socket, buffer, MAX_BUFFER_SIZE) == -1) {
        perror("Error while trying to read message from client!");
        exit(EXIT_FAILURE);
    }

    // Print message received from client
    printf("Client: %s\n", buffer);

    // Send a message to the client
    char *msg = "Hello from the server!";
    if (send(new_socket, msg, strlen(msg), 0) == -1) {
        perror("Error while trying to send message to client!");
        exit(EXIT_FAILURE);
    }

    return 0;
}