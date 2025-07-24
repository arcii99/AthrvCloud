//FormAI DATASET v1.0 Category: Simple Web Server ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    char buffer[BUFFER_SIZE];

    // Create a socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Set the server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind the socket to the address
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Error binding socket");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_socket, 1) < 0) {
        perror("Error listening on socket");
        exit(1);
    }

    printf("Server running on port %d...\n", PORT);

    // Accept incoming connections
    socklen_t client_address_size = sizeof(client_address);
    client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_size);

    // Read the request from the client
    memset(buffer, 0, BUFFER_SIZE);
    if (read(client_socket, buffer, BUFFER_SIZE) < 0) {
        perror("Error reading from socket");
        exit(1);
    }

    printf("Request from client:\n%s\n", buffer);

    // Parse the request and send the response
    char *response = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<html><body><h1>Hello, world!</h1></body></html>";
    if (send(client_socket, response, strlen(response), 0) < 0) {
        perror("Error sending response");
        exit(1);
    }

    // Close the sockets
    close(client_socket);
    close(server_socket);

    return 0;
}