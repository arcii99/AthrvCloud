//FormAI DATASET v1.0 Category: Networking ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_BUFFER_SIZE 1024

int main() {
    int server_fd, new_socket, val_read;
    struct sockaddr_in address;
    int opt = 1;
    int address_length = sizeof(address);
    char buffer[MAX_BUFFER_SIZE] = {0};
    char *welcome_message = "Welcome to my network!";

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // Set server address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind socket to address
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connection
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&address_length)) < 0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    printf("Connection established!\n");

    // Send welcome message to client
    send(new_socket, welcome_message, strlen(welcome_message), 0);
    printf("Welcome message sent!\n");

    // Read data from client
    while ((val_read = read(new_socket, buffer, MAX_BUFFER_SIZE)) > 0) {
        printf("Data received from client: %s\n", buffer);

        // Echo data back to client
        send(new_socket, buffer, strlen(buffer), 0);
    }

    if (val_read == 0) {
        printf("Client disconnected\n");
    } else {
        perror("Read failed");
    }

    return 0;
}