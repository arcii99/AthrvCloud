//FormAI DATASET v1.0 Category: Socket programming ; Style: Dennis Ritchie
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<stdbool.h>

#define PORT 8081

int main(int argc, char const *argv[]) {
    
    int socket_fd, new_socket_fd, valread;
    struct sockaddr_in server_address;
    int addrlen = sizeof(server_address);
    
    // Create socket file descriptor
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    // Attach socket to port
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons( PORT );
    
    if (bind(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Socket binding failed");
        exit(EXIT_FAILURE);
    }
    
    // Listen for incoming connections
    if (listen(socket_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }
    
    // Accept incoming connections
    if ((new_socket_fd = accept(socket_fd, (struct sockaddr *)&server_address, (socklen_t*)&addrlen)) < 0) {
        perror("Socket acceptance failed");
        exit(EXIT_FAILURE);
    }
    
    // Read incoming message
    char message[1024] = {0};
    valread = read( new_socket_fd , message, 1024);
    printf("Incoming message: %s\n", message);
    
    // Send response back to the client
    char * response = "Hello from server!";
    send(new_socket_fd , response , strlen(response) , 0 );
    printf("Response sent\n");
    return 0;
}