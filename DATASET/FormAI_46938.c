//FormAI DATASET v1.0 Category: Networking ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

    int server_fd, new_socket;
    struct sockaddr_in server_address, client_address;
    int client_address_length = sizeof(client_address);
    char buffer[BUFFER_SIZE] = {0};
    char *response = "Hello from Server!";

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Socket options set failed");
        exit(EXIT_FAILURE);
    }

    // Prepare server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind socket to address
    if (bind(server_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connection
    if ((new_socket = accept(server_fd, (struct sockaddr *)&client_address, (socklen_t *)&client_address_length)) < 0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    // Handle incoming message
    int message_length = read(new_socket, buffer, BUFFER_SIZE);
    if (message_length <= 0) {
        perror("Message receive failed");
        exit(EXIT_FAILURE);
    }

    // Print incoming message
    printf("Received message: %s\n", buffer);

    // Send response
    send(new_socket, response, strlen(response), 0);
    printf("Response sent: %s\n", response);

    // Clean up
    close(new_socket);
    close(server_fd);

    return 0;
}