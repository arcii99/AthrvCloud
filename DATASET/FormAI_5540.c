//FormAI DATASET v1.0 Category: Networking ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT_NUMBER 8080
#define MAX_MSG_SIZE 1024

int main() {
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    char message[MAX_MSG_SIZE] = {0};
    int addrlen = sizeof(server_addr);

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("Socket creation failed\n");
        exit(EXIT_FAILURE);
    }

    // Set server address parameters
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT_NUMBER);

    // Bind socket to address and port
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Socket bind failed\n");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        printf("Listen failed\n");
        exit(EXIT_FAILURE);
    }

    while (1) {
        // Accept incoming connection and get client socket
        if ((client_fd = accept(server_fd, (struct sockaddr *)&server_addr, (socklen_t*)&addrlen)) < 0) {
            printf("Accept failed\n");
            exit(EXIT_FAILURE);
        }

        // Receive message from client
        if (read(client_fd, message, MAX_MSG_SIZE) < 0) {
            printf("Read failed\n");
            exit(EXIT_FAILURE);
        }

        // Print received message
        printf("Message received: %s\n", message);

        // Send response to client
        char* response = "Received message!";
        if (write(client_fd, response, strlen(response)) < 0) {
            printf("Write failed\n");
            exit(EXIT_FAILURE);
        }

        // Clear message buffer for next iteration
        memset(message, 0, sizeof(message));
    }

    return 0;
}