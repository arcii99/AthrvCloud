//FormAI DATASET v1.0 Category: Simple Web Server ; Style: lively
// Welcome to the Simple Web Server program!
// This program sets up a server on localhost and listens to incoming requests

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 1024
#define PORT_NUMBER 8080

// Main function
int main() {
    int server_socket_fd, new_socket_fd, read_size, err;
    struct sockaddr_in server_addr, client_addr;
    char buffer[MAX_BUFFER_SIZE] = {0};
     
    // Create the socket
    server_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket_fd == -1) {
        printf("Error creating socket\n");
        return -1;
    }
     
    // Set server address parameters
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT_NUMBER);
     
    // Bind socket to address
    err = bind(server_socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (err < 0) {
        printf("Error binding socket to address\n");
        return -1;
    }
    printf("Server is listening on port %d\n", PORT_NUMBER);
     
    // Listen for incoming connections
    err = listen(server_socket_fd, 5);
    if (err < 0) {
        printf("Error listening for incoming connections\n");
        return -1;
    }
     
    // Accept incoming connections
    int client_addr_size = sizeof(client_addr);
    new_socket_fd = accept(server_socket_fd, (struct sockaddr *)&client_addr, (socklen_t*)&client_addr_size);
    if (new_socket_fd < 0) {
        printf("Error accepting incoming connection\n");
        return -1;
    }
     
    // Read data from socket and send response
    read_size = read(new_socket_fd, buffer, MAX_BUFFER_SIZE);
    if (read_size > 0) {
        printf("Received message: %s\n", buffer);
        const char *response_msg = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello World!";
        write(new_socket_fd, response_msg, strlen(response_msg));
    }
     
    // Close sockets
    close(new_socket_fd);
    close(server_socket_fd);
     
    return 0;
}