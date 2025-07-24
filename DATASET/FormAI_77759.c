//FormAI DATASET v1.0 Category: Socket programming ; Style: optimized
// This program establishes a socket connection and sends a message to the server
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080

int main(int argc, char *argv[]) {
    int sock_fd, message_size;
    struct sockaddr_in server_address;
    char buffer[1024] = {0};
    char *message = "Hello from client!";

    // Creating socket file descriptor
    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_address, '0', sizeof(server_address));

    // Server information
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    
    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    if (connect(sock_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    // Send message to the server
    message_size = strlen(message);
    if (send(sock_fd, message, message_size, 0) != message_size) {
        perror("Error sending message");
        exit(EXIT_FAILURE);
    }
    printf("Message sent to the server!\n");

    // Receive response from server
    if (read(sock_fd, buffer, 1024) < 0) {
        perror("Error receiving response");
        exit(EXIT_FAILURE);
    }
    printf("Server response: %s\n", buffer);

    return 0;
}