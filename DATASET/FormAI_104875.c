//FormAI DATASET v1.0 Category: Socket programming ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 5000

int main() {
    int server_fd, client_fd, length;
    struct sockaddr_in server_addr, client_addr;
    char buffer[1024], message[100];

    // Create the server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    // Initialize socket address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket to the specified port
    if (bind(server_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Binding error");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen error");
        exit(EXIT_FAILURE);
    }

    printf("Waiting for client connection...\n");

    // Accept incoming client connections
    length = sizeof(client_addr);
    if ((client_fd = accept(server_fd, (struct sockaddr *) &client_addr, (socklen_t *) &length)) < 0) {
        perror("Accept error");
        exit(EXIT_FAILURE);
    }

    printf("Client connected.\n");

    // Receive message from client
    memset(buffer, 0, sizeof(buffer));
    if (recv(client_fd, buffer, 1024, 0) < 0) {
        perror("Receive error");
        exit(EXIT_FAILURE);
    }

    printf("Client: %s\n", buffer);

    // Send message back to client
    printf("Enter a message to send back to client: ");
    fgets(message, 100, stdin);
    message[strcspn(message, "\n")] = '\0'; // Remove trailing newline character
    if (send(client_fd, message, strlen(message), 0) < 0) {
        perror("Send error");
        exit(EXIT_FAILURE);
    }

    // Close socket connections
    close(client_fd);
    close(server_fd);

    return 0;
}