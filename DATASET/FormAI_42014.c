//FormAI DATASET v1.0 Category: Socket programming ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024
#define PORT 8080

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE];

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    int option = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &option, sizeof(option))) {
        perror("Setting socket options failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to specified address and port
    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("Socket binding failed");
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(server_fd, 5) < 0) {
        perror("Server listening failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", PORT);

    // Accept incoming connections
    if ((new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen)) < 0) {
        perror("Accepting incoming connection failed");
        exit(EXIT_FAILURE);
    }

    printf("New client connected\n");

    // Run the server continuously until it receives the termination signal
    while (1) {
        // Wait for data from client
        memset(buffer, 0, BUFFER_SIZE);
        if (read(new_socket, buffer, BUFFER_SIZE) <= 0) {
            printf("Client disconnected\n");
            break;
        }

        // Process the data from client
        printf("Data received from client: %s", buffer);

        // Prepare the response
        char response[BUFFER_SIZE];
        strncpy(response, "Server response: ", BUFFER_SIZE);
        strncat(response, buffer, BUFFER_SIZE);

        // Send response back to client
        if (send(new_socket, response, strlen(response), 0) < 0) {
            perror("Sending response to client failed");
            exit(EXIT_FAILURE);
        }

        printf("Response sent to client: %s\n", response);
    }

    close(new_socket);
    close(server_fd);

    return 0;
}