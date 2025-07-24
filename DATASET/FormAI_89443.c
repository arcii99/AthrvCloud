//FormAI DATASET v1.0 Category: Networking ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void error_handler(char* message) {
    perror(message);
    exit(EXIT_FAILURE);
}

int main(int argc, char* argv[]) {
    int server_socket, client_socket, read_size;
    char buffer[BUFFER_SIZE], message[BUFFER_SIZE];
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len;
    
    // Create server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0)
        error_handler("Failed to create server socket");

    // Prepare server address struct
    memset(&server_addr, 0, sizeof(server_addr)); // Clear server address struct
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080); // Set port
    
    // Bind server socket to server address
    if (bind(server_socket, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0)
        error_handler("Failed to bind server socket to address");
        
    // Start listening for connections
    if (listen(server_socket, 5) < 0)
        error_handler("Failed to start listening for connections");
        
    printf("Server started on port 8080. Waiting for connections...\n");
    
    // Accept incoming connections
    client_addr_len = sizeof(client_addr);
    client_socket = accept(server_socket, (struct sockaddr*) &client_addr, &client_addr_len);
    if (client_socket < 0)
        error_handler("Failed to accept incoming connection");
        
    printf("Client connected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
    
    // Read data from client
    do {
        read_size = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (read_size < 0)
            error_handler("Failed to read from socket");
            
        printf("Data received from client: %s\n", buffer);
    } while (read_size > 0);
    
    // Write data to client
    sprintf(message, "Thank you for connecting!");
    if (send(client_socket, message, strlen(message), 0) < 0)
        error_handler("Failed to send data to client");
        
    close(client_socket);
    close(server_socket);
    
    return 0;
}