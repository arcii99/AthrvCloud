//FormAI DATASET v1.0 Category: Client Server Application ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int socketid, new_socket, valread;
    struct sockaddr_in server_address, client_address;
    int opt = 1;
    int address_length = sizeof(server_address);
    char buffer[BUFFER_SIZE] = {0};
    char *hello = "Hello from the server";
    
    // Creating socket
    if ((socketid = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }
    
    // Setting socket options
    if (setsockopt(socketid, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // Setting server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons( PORT );

    // Binding the socket to a port
    if (bind(socketid, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }
    
    // Start listening for incoming connections
    if (listen(socketid, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }
    
    while (1) {
        // Accept incoming connection
        if ((new_socket = accept(socketid, (struct sockaddr *)&client_address, (socklen_t*)&address_length))<0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }
        
        // Read incoming message from client
        valread = read(new_socket, buffer, BUFFER_SIZE);
        printf("Client: %s\n", buffer);
        
        // Send response message to client
        send(new_socket, hello, strlen(hello), 0);
        printf("Hello message sent\n");
    }
    return 0;
}