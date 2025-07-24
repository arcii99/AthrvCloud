//FormAI DATASET v1.0 Category: Simple Web Server ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>

// Main function
int main() {
    int server_socket, client_socket;
    socklen_t length;
    char response[1024], request[1024];
    struct sockaddr_in server_address, client_address;
    int port = 8080;
    
    // Create the socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        printf("Error creating socket.\n");
        exit(1);
    }
    printf("Socket created successfully.\n");
    
    // Set up the server address
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    server_address.sin_addr.s_addr = INADDR_ANY;
    
    // Bind the socket to the server address
    if (bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address)) < 0) {
        printf("Error binding socket.\n");
        exit(1);
    }
    printf("Socket bound successfully.\n");

    // Listen for incoming connections
    if (listen(server_socket, 10) < 0) {
        printf("Error listening for connections.\n");
        exit(1);
    }
    printf("Server listening on port %d...\n", port);
    
    while(1) {
        // Accept incoming connection
        length = sizeof(client_address);
        client_socket = accept(server_socket, (struct sockaddr*) &client_address, &length);
        if (client_socket < 0) {
            printf("Error accepting connection.\n");
            exit(1);
        }
        printf("Connection accepted.\n");
        
        // Receive request from client
        bzero(request, 1024);
        read(client_socket, request, 1024);
        printf("Client request: %s\n", request);
        
        // Send response to client
        sprintf(response, "HTTP/1.1 200 OK\r\nContent-Length: 12\r\n\r\nHello World!");
        write(client_socket, response, strlen(response));
        close(client_socket);
    }

    return 0;
}