//FormAI DATASET v1.0 Category: Client Server Application ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

// Function to handle connections
void handle_connection(int socket_fd) {
    char buffer[BUFFER_SIZE];
    int read_length;

    // Read the message from the client
    while ((read_length = read(socket_fd, buffer, BUFFER_SIZE)) > 0) {
        buffer[read_length] = '\0';
        printf("[Client]: %s", buffer);

        // Echo the message back to the client
        if (write(socket_fd, buffer, strlen(buffer)) < 0) {
            perror("Error writing to socket");
            exit(EXIT_FAILURE);
        }
    }

    // Close the socket
    close(socket_fd);
}

int main(int argc, char const *argv[]) {
    int server_fd, client_fd;
    struct sockaddr_in server_address, client_address;
    unsigned int address_length = sizeof(client_address);

    // Create the socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Initialize server address structure
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind the socket to the address and port
    if (bind(server_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Error binding socket");
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(server_fd, 5) < 0) {
        perror("Error listening for connections");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    // Handle incoming connections
    while (1) {
        // Accept the connection
        if ((client_fd = accept(server_fd, (struct sockaddr *)&client_address, &address_length)) < 0) {
            perror("Error accepting connection");
            exit(EXIT_FAILURE);
        }

        printf("Client connected: %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        // Handle the connection
        handle_connection(client_fd);
    }

    return 0;
}