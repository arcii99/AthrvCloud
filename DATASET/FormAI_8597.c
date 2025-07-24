//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define MAX_BUFFER_SIZE 1024

int main() {
    int server_socket_fd, client_socket_fd, socket_len, read_size;
    struct sockaddr_in server_address, client_address;
    char buffer[MAX_BUFFER_SIZE] = {0};

    // Create the server socket
    if ((server_socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Prepare the server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind the socket to the address
    if (bind(server_socket_fd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    // Accept incoming connections
    socket_len = sizeof(client_address);
    if ((client_socket_fd = accept(server_socket_fd, (struct sockaddr *) &client_address, (socklen_t *) &socket_len)) < 0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    // Read incoming data and respond with an acknowledgement message
    while ((read_size = read(client_socket_fd, buffer, MAX_BUFFER_SIZE)) > 0) {
        printf("Received message from client: %s\n", buffer);

        char *acknowledgement = "Message received";
        if (send(client_socket_fd, acknowledgement, strlen(acknowledgement), 0) < 0) {
            perror("Send failed");
            exit(EXIT_FAILURE);
        }

        memset(buffer, 0, MAX_BUFFER_SIZE); // Clear the buffer
    }

    if (read_size == 0) {
        printf("Client disconnected\n");
    } else if (read_size == -1) {
        perror("Receive failed");
    }

    close(client_socket_fd);
    close(server_socket_fd);

    return 0;
}