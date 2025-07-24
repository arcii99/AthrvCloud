//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8080
#define MAX_BUFFER_SIZE 1024

int main() {
    int socket_fd, connection_fd;
    struct sockaddr_in server_address, client_address;
    char buffer[MAX_BUFFER_SIZE] = {0};
    char *response = "Hello! Welcome to my world. How are you doing?";

    // Creating socket file descriptor
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Setting server address properties
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind socket to server address
    if (bind(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address))<0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening for client connections
    if (listen(socket_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Waiting for client connection...\n");

    // Accept client connection
    int address_length = sizeof(client_address);
    if ((connection_fd = accept(socket_fd, (struct sockaddr *)&client_address, (socklen_t*)&address_length))<0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    printf("Client connected: %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

    // Send message to client
    send(connection_fd, response, strlen(response), 0);
    printf("Response sent: %s\n", response);

    // Read message from client
    int read_size = read(connection_fd, buffer, MAX_BUFFER_SIZE);
    printf("Message from client: %s\n", buffer);

    // Close socket connections
    close(connection_fd);
    close(socket_fd);

    return 0;
}