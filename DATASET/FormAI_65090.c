//FormAI DATASET v1.0 Category: Simple Web Server ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define DEFAULT_PORT 8080

// Function to handle incoming client connections
void handle_connection(int client_socket) {
    char buffer[1024] = {0};
    read(client_socket, buffer, 1024);
    printf("%s\n", buffer);
    
    // Send HTTP response message to client
    char *message = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<!DOCTYPE html>\n<html>\n<head><title>Simple Web Server</title></head>\n<body>Hello World!</body>\n</html>";
    write(client_socket, message, strlen(message));
    
    // Close client socket
    close(client_socket);
}

int main(int argc, char const *argv[]) {
    int server_socket, opt = 1;
    struct sockaddr_in server_address, client_address;
    int addrlen = sizeof(server_address);
    
    // Create socket file descriptor
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    // Attach socket to the port
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(DEFAULT_PORT);
    
    // Bind socket to the address and port
    if (bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }
    
    // Listen for incoming requests from clients
    if (listen(server_socket, 5) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }
    printf("Server is listening on port %d...\n", DEFAULT_PORT);
    
    // Accept incoming client connections
    while (1) {
        int client_socket = accept(server_socket, (struct sockaddr*)&client_address, (socklen_t*)&addrlen);
        if (client_socket < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }
        handle_connection(client_socket);
    }
    return 0;
}