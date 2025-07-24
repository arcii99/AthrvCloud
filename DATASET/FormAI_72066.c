//FormAI DATASET v1.0 Category: Simple Web Server ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080
#define MAX_CONNECTIONS 5
#define MAX_REQUEST_SIZE 2048

void handle_request(int client_socket) {
    char buffer[MAX_REQUEST_SIZE];
    recv(client_socket, buffer, MAX_REQUEST_SIZE, 0);
    printf("Received Request: %s\n", buffer);
    char response[] = "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\nHello, World!\r\n";
    send(client_socket, response, strlen(response), 0);
    close(client_socket);
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    int address_size = sizeof(client_address);
    
    // Create Socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Failed to create socket\n");
        return -1;
    }
    
    // Bind Socket to Port 8080
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);
    if (bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address)) < 0) {
        printf("Failed to bind socket to port %d\n", PORT);
        return -1;
    }
    
    // Listen for Incoming Connections
    if (listen(server_socket, MAX_CONNECTIONS) < 0) {
        printf("Failed to listen for incoming connections\n");
        return -1;
    }
    printf("Server listening on port %d\n", PORT);
    
    // Handle Incoming Connections
    while (1) {
        client_socket = accept(server_socket, (struct sockaddr*) &client_address, (socklen_t*) &address_size);
        if (client_socket < 0) {
            printf("Failed to accept incoming connection\n");
            continue;
        }
        handle_request(client_socket);
    }
    return 0;
}