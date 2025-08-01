//FormAI DATASET v1.0 Category: Client Server Application ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void error(char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

int main() {
    char buffer[BUFFER_SIZE] = {0};
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    int address_len = sizeof(server_address);
    
    // Create server socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        error("socket failed");
    }
    
    // Set server socket settings
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);
    
    // Bind socket to address
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        error("bind failed");
    }
    
    // Listen to incoming connections
    if (listen(server_socket, 1) < 0) {
        error("listen failed");
    }
    printf("Server listening on port %d...\n", PORT);
    
    // Accept incoming connection
    if ((client_socket = accept(server_socket, (struct sockaddr *)&client_address, (socklen_t*)&address_len)) < 0) {
        error("accept failed");
    }
    printf("Client connected from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
    
    // Send message to client
    char *message = "Hello client!";
    if (send(client_socket, message, strlen(message), 0) < 0) {
        error("send failed");
    }
    
    // Receive message from client
    int bytes_received;
    if ((bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0)) < 0) {
        error("recv failed");
    }
    buffer[bytes_received] = '\0';
    printf("Client said: %s\n", buffer);
    
    // Close sockets
    close(client_socket);
    close(server_socket);
    
    return EXIT_SUCCESS;
}