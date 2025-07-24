//FormAI DATASET v1.0 Category: Simple Web Server ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 80

int main(int argc, char *argv[]) {
    // Define variables
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    char response[] = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<h1>Hello, World!</h1>";

    // Create server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error creating server socket");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind server socket to address and port
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        printf("Error binding server socket");
        exit(EXIT_FAILURE);
    }

    // Listen for client connections
    if (listen(server_socket, 3) < 0) {
        printf("Error listening for client connections");
        exit(EXIT_FAILURE);
    }

    // Accept incoming client connection
    int client_address_size = sizeof(client_address);
    client_socket = accept(server_socket, (struct sockaddr *)&client_address, (socklen_t*)&client_address_size);
    if (client_socket < 0) {
        printf("Error accepting client connection");
        exit(EXIT_FAILURE);
    }

    // Send response to client
    write(client_socket, response, strlen(response));

    // Close client and server sockets
    close(client_socket);
    close(server_socket);

    return 0;
}