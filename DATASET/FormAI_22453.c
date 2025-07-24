//FormAI DATASET v1.0 Category: Client Server Application ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define MAX_BUFFER_SIZE 1024

// Function to handle client connections
void handle_client(int socket_fd)
{
    char buffer[MAX_BUFFER_SIZE];
    memset(buffer, 0, MAX_BUFFER_SIZE);

    int bytes_received = read(socket_fd, buffer, MAX_BUFFER_SIZE - 1);
    if (bytes_received < 0) 
    {
        perror("Error reading from socket");
    }
    else if (bytes_received == 0) 
    {
        printf("Client disconnected.\n");
    }
    else 
    {
        printf("Received message from client: %s\n", buffer);
        write(socket_fd, buffer, strlen(buffer));
    }
    
    close(socket_fd);
    printf("Connection closed.\n");
}

int main(int argc, char const *argv[]) 
{
    int server_socket_fd, client_socket_fd;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_length = sizeof(client_address);

    // Create server socket
    if ((server_socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
    {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }
    
    // Set server address properties
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind server socket to address
    if (bind(server_socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) 
    {
        perror("Error binding socket to address");
        exit(EXIT_FAILURE);
    }
    
    // Listen for incoming connections
    if (listen(server_socket_fd, 3) < 0)
    {
        perror("Error listening for incoming connections");
        exit(EXIT_FAILURE);
    }

    printf("Server running on port %d...\n", PORT);

    // Continuously accept incoming client connections
    while (1)
    {
        if ((client_socket_fd = accept(server_socket_fd, (struct sockaddr *)&client_address, &client_address_length)) < 0)
        {
            perror("Error accepting incoming connection");
            exit(EXIT_FAILURE);
        }

        // Print client IP address and port number
        printf("Client connected: %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
        
        // Handle client connection
        handle_client(client_socket_fd);
    }

    close(server_socket_fd);
    return 0;
}