//FormAI DATASET v1.0 Category: Client Server Application ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define MAX_BUFFER_SIZE 1024

int main(int argc, char const *argv[]) {
    int socket_fd, new_socket, client_length;
    struct sockaddr_in server_address, client_address;
    char buffer[MAX_BUFFER_SIZE] = {0};
    char *message = "Hello from server!";

    // Create socket file descriptor
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    // Set server address parameters
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind the socket to the server address
    if (bind(socket_fd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Failed to bind the socket to the server address");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(socket_fd, 3) < 0) {
        perror("Failed to listen for incoming connections");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connection
    client_length = sizeof(client_address);
    if ((new_socket = accept(socket_fd, (struct sockaddr *) &client_address, (socklen_t *) &client_length)) < 0) {
        perror("Failed to accept incoming connection");
        exit(EXIT_FAILURE);
    }

    // Read incoming data from client
    int read_result = read(new_socket, buffer, MAX_BUFFER_SIZE);
    if (read_result < 0) {
        perror("Failed to read from socket");
        exit(EXIT_FAILURE);
    }

    printf("Received message from client: %s\n", buffer);

    // Send the message to the client
    send(new_socket, message, strlen(message), 0);
    printf("Message sent to client: %s\n", message);

    // Close the socket
    close(socket_fd);

    return 0;
}