//FormAI DATASET v1.0 Category: Chat server ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8080
#define MAX_CLIENTS 5
#define BUF_SIZE 1024

int main(int argc, char const *argv[]) {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUF_SIZE] = {0};
    char *welcome_message = "Welcome to the secure chat server!\n";
    
    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    
    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    
    // Set address info
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    // Bind socket to address
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    
    // Listen for connections
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }
    
    // Accept incoming connection
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }
    
    // Send welcome message to client
    send(new_socket, welcome_message, strlen(welcome_message), 0);
    
    // Run chat server
    while (1) {
        // Clear buffer
        memset(buffer, 0, BUF_SIZE);
        
        // Read incoming message from client
        valread = read(new_socket, buffer, BUF_SIZE);
        
        // Check for errors or client disconnect
        if (valread == 0) {
            printf("Client disconnected\n");
            close(new_socket);
            break;
        } else if (valread < 0) {
            perror("read failed");
        } else {
            // Echo message back to client
            send(new_socket, buffer, strlen(buffer), 0);
        }
    }
    
    // Close socket
    close(server_fd);
    
    return 0;
}