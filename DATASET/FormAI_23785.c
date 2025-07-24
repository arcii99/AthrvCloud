//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char const *argv[])
{
    int server_fd, client_fd;
    struct sockaddr_in address;
    int opt = 1;
    int address_len = sizeof(address);
    char buffer[MAX_BUFFER_SIZE] = {0};
    char *message = "Hello from server!";
    
    // Create server socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }
    
    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("Set socket options failed");
        exit(EXIT_FAILURE);
    }
    
    // Configure server address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);
    
    // Bind socket to address
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }
    
    // Listen for incoming connections
    if (listen(server_fd, 3) < 0)
    {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }
    
    // Accept incoming connection
    if ((client_fd = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&address_len)) < 0)
    {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }
    
    // Send message to client
    if (send(client_fd, message, strlen(message), 0) != strlen(message))
    {
        perror("Send failed");
    }
    printf("Hello message sent to client\n");
    
    // Receive message from client
    if (recv(client_fd, buffer, MAX_BUFFER_SIZE, 0) <= 0)
    {
        perror("Receive failed");
    }
    printf("Client message: %s\n", buffer);
    
    // Close file descriptors
    close(client_fd);
    close(server_fd);
    
    return 0;
}