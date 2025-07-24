//FormAI DATASET v1.0 Category: Socket programming ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    char message[BUFFER_SIZE] = {0};
    
    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed.");
        exit(EXIT_FAILURE);
    }
    
    // Set socket to reuse address and port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt failed.");
        exit(EXIT_FAILURE);
    }
    
    // Set address and port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    // Bind socket to address and port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed.");
        exit(EXIT_FAILURE);
    }
    
    // Listen for connections
    if (listen(server_fd, 2) < 0) {
        perror("listen failed.");
        exit(EXIT_FAILURE);
    }
    
    printf("Server started. Waiting for connections...\n");
    
    // Wait for 2 connections
    for (int i = 0; i < 2; i++) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept failed.");
            exit(EXIT_FAILURE);
        }
        printf("Client %d connected.\n", i+1);
    }
    
    // Loop until interrupted
    while (1) {
        // Wait for message from first client
        if (recv(new_socket, buffer, BUFFER_SIZE, 0) < 0) {
            perror("recv failed.");
            exit(EXIT_FAILURE);
        }
        
        // Print message from first client
        printf("Client 1: %s\n", buffer);
        
        // Send message to second client
        strcpy(message, "You: ");
        strcat(message, buffer);
        if (send(new_socket - 1, message, strlen(message), 0) < 0) {
            perror("send failed.");
            exit(EXIT_FAILURE);
        }
        
        // Wait for message from second client
        if (recv(new_socket - 1, buffer, BUFFER_SIZE, 0) < 0) {
            perror("recv failed.");
            exit(EXIT_FAILURE);
        }
        
        // Print message from second client
        printf("Client 2: %s\n", buffer);
        
        // Send message to first client
        strcpy(message, "You: ");
        strcat(message, buffer);
        if (send(new_socket, message, strlen(message), 0) < 0) {
            perror("send failed.");
            exit(EXIT_FAILURE);
        }
    }
    
    return 0;
}