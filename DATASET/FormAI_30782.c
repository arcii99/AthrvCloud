//FormAI DATASET v1.0 Category: Client Server Application ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 9000
#define BUFFER_SIZE 1024

int main() {
    // Create socket for server
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Error creating socket");
        exit(-1);
    }

    // Set socket address
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind socket to address
    if (bind(server_socket, (struct sockaddr*) &server_addr, sizeof(server_addr)) == -1) {
        perror("Error binding socket");
        exit(-1);
    }

    // Listen for client connections
    if (listen(server_socket, 5) == -1) {
        perror("Error listening");
        exit(-1);
    }

    // Accept client connections
    int client_socket;
    struct sockaddr_in client_addr;
    socklen_t client_addr_size = sizeof(client_addr);
    client_socket = accept(server_socket, (struct sockaddr*) &client_addr, &client_addr_size);

    if (client_socket < 0) {
        perror("Error accepting client connection");
        exit(-1);
    }

    // Receive message from client
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    if (recv(client_socket, buffer, BUFFER_SIZE, 0) == -1) {
        perror("Error receiving message from client");
        exit(-1);
    }

    // Print message received from client
    printf("Received message from client: %s\n", buffer);

    // Send response to client
    char* response = "Message received!";
    if (send(client_socket, response, strlen(response), 0) == -1) {
        perror("Error sending response to client");
        exit(-1);
    }

    // Close sockets
    close(client_socket);
    close(server_socket);

    return 0;
}