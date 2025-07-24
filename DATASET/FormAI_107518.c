//FormAI DATASET v1.0 Category: Socket programming ; Style: shocked
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h> 
#include <unistd.h> 

int main() { 
    int server_sock, client_sock; 
    int server_port = 8080; 

    struct sockaddr_in server_addr, client_addr; 

    // Create server socket 
    server_sock = socket(AF_INET, SOCK_STREAM, 0); 
    if (server_sock < 0) { 
        perror("Failed to create server socket"); 
        exit(EXIT_FAILURE); 
    } 

    // Set server address 
    server_addr.sin_family = AF_INET; 
    server_addr.sin_port = htons(server_port); 
    server_addr.sin_addr.s_addr = INADDR_ANY; 

    // Bind server socket to specified address & port 
    if (bind(server_sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) { 
        perror("Failed to bind server socket"); 
        exit(EXIT_FAILURE); 
    } 

    // Listen for incoming connections 
    if (listen(server_sock, 1) < 0) { 
        perror("Failed to listen for incoming connections"); 
        exit(EXIT_FAILURE); 
    } 

    printf("Server listening on port %d...\n", server_port); 

    // Accept incoming connections 
    socklen_t client_len = sizeof(client_addr); 
    client_sock = accept(server_sock, (struct sockaddr *) &client_addr, &client_len); 
    if (client_sock < 0) { 
        perror("Failed to accept incoming connection"); 
        exit(EXIT_FAILURE); 
    } 

    printf("Client connected from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port)); 

    // Receive data from client 
    char buffer[256]; 
    int bytes_received = recv(client_sock, buffer, sizeof(buffer), 0); 
    if (bytes_received < 0) { 
        perror("Failed to receive data from client"); 
        exit(EXIT_FAILURE); 
    } 

    printf("Received %d bytes: %s\n", bytes_received, buffer); 

    // Send response to client 
    char response[] = "Hello, client!"; 
    int bytes_sent = send(client_sock, response, sizeof(response), 0); 
    if (bytes_sent < 0) { 
        perror("Failed to send response to client"); 
        exit(EXIT_FAILURE); 
    } 

    printf("Sent %d bytes: %s\n", bytes_sent, response); 

    // Close sockets 
    close(client_sock); 
    close(server_sock); 

    return 0; 
}