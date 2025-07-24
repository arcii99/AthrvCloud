//FormAI DATASET v1.0 Category: Chat server ; Style: irregular
// This C Chat server example program implements an irregular style
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main(void) {
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};
    char message[1024] = {0};
    
    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Socket creation error");
        exit(EXIT_FAILURE);
    }

    // Set server address parameters
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind socket to server address
    if (bind(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sock, 3) < 0) {
        printf("Listen failed");
        exit(EXIT_FAILURE);
    }
    
    // Accept incoming connections
    int client_socket = accept(sock, (struct sockaddr *)&serv_addr, (socklen_t*)&serv_addr);
    
    // Print welcome message to client
    strcpy(message, "Welcome to this C Chat Server Example Program\0");
    send(client_socket, message, strlen(message), 0);
    
    // Loop for server chat functionality
    while (1) {
        memset(buffer, 0, sizeof(buffer)); // Clear buffer
        memset(message, 0, sizeof(message)); // Clear message
        
        // Receive message from client
        valread = read(client_socket, buffer, 1024);

        // Check for client quit message
        if (strcmp(buffer, "quit") == 0) {
            send(client_socket, buffer, strlen(buffer), 0);
            break;
        }
        
        // Format and send server message
        sprintf(message, "Server message: %s", buffer);
        send(client_socket, message, strlen(message),0);
    }

    // Close socket
    close(sock);
    return 0;
}