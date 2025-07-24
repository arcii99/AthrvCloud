//FormAI DATASET v1.0 Category: Chat server ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MESSAGE_SIZE 1024
#define SERVER_PORT 8888

int main() {
    int server_socket, client_socket, addr_len;
    struct sockaddr_in server_addr, client_addr;
    char message[MESSAGE_SIZE];
    
    // Create server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Could not create server socket.\n");
        exit(EXIT_FAILURE);
    }
    
    // Bind server socket to IP address and port
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(SERVER_PORT);
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Could not bind server socket.\n");
        exit(EXIT_FAILURE);
    }
    
    // Listen for incoming connections
    if (listen(server_socket, 5) == -1) {
        perror("Could not listen for incoming connections.\n");
        exit(EXIT_FAILURE);
    }
    
    // Accept incoming connections
    addr_len = sizeof(client_addr);
    client_socket = accept(server_socket, (struct sockaddr *)&client_addr, (socklen_t *)&addr_len);
    if (client_socket == -1) {
        perror("Could not accept incoming connection.\n");
        exit(EXIT_FAILURE);
    }
    
    // Receive messages from client
    while (1) {
        memset(message, 0, MESSAGE_SIZE);
        if (recv(client_socket, message, MESSAGE_SIZE, 0) == -1) {
            perror("Could not receive message from client.\n");
            exit(EXIT_FAILURE);
        }
        printf("Received from client: %s", message);
        
        // Respond to client's message
        strcat(message, " acknowledged.\n");
        if (send(client_socket, message, strlen(message), 0) == -1) {
            perror("Could not send message to client.\n");
            exit(EXIT_FAILURE);
        }
    }
    
    // Close sockets
    close(client_socket);
    close(server_socket);
    
    return 0;
}