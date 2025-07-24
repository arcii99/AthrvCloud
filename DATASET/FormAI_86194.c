//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>

#define PROXY_PORT 8080   // Change this to the desired port number
#define MAX_BUFFER 8192   // Maximum size of buffer

void proxy(int client_socket_fd)
{
    int server_socket_fd, num_bytes;
    char buffer[MAX_BUFFER];
    struct sockaddr_in server_address;
    
    // Create a new socket for the server
    server_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket_fd < 0)
    {
        perror("Error: Failed to create socket");
        exit(EXIT_FAILURE);
    }
    
    // Set the server address information
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");   // Change this to the desired server IP address
    server_address.sin_port = htons(80);   // Change this to the desired server port number
    
    // Connect the socket to the server
    if (connect(server_socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
    {
        perror("Error: Failed to connect to server");
        exit(EXIT_FAILURE);
    }
    
    // Forward the request to the server
    num_bytes = recv(client_socket_fd, buffer, MAX_BUFFER, 0);
    if (num_bytes < 0)
    {
        perror("Error: Failed to receive data from client");
        exit(EXIT_FAILURE);
    }
    
    if (send(server_socket_fd, buffer, num_bytes, 0) < 0)
    {
        perror("Error: Failed to send data to server");
        exit(EXIT_FAILURE);
    }
    
    // Receive the response from the server and forward it to the client
    num_bytes = recv(server_socket_fd, buffer, MAX_BUFFER, 0);
    if (num_bytes < 0)
    {
        perror("Error: Failed to receive data from server");
        exit(EXIT_FAILURE);
    }
    
    if (send(client_socket_fd, buffer, num_bytes, 0) < 0)
    {
        perror("Error: Failed to send data to client");
        exit(EXIT_FAILURE);
    }
    
    // Close the sockets
    close(client_socket_fd);
    close(server_socket_fd);
}

int main()
{
    int proxy_socket_fd, client_socket_fd, cli_len;
    struct sockaddr_in proxy_address, cli_address;
    
    // Create a new socket for the proxy server
    proxy_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy_socket_fd < 0)
    {
        perror("Error: Failed to create socket");
        exit(EXIT_FAILURE);
    }
    
    // Set the proxy server address information
    memset(&proxy_address, 0, sizeof(proxy_address));
    proxy_address.sin_family = AF_INET;
    proxy_address.sin_addr.s_addr = INADDR_ANY;
    proxy_address.sin_port = htons(PROXY_PORT);
    
    // Bind the socket to the proxy server address
    if (bind(proxy_socket_fd, (struct sockaddr *)&proxy_address, sizeof(proxy_address)) < 0)
    {
        perror("Error: Failed to bind socket");
        exit(EXIT_FAILURE);
    }
    
    // Listen for incoming connections
    if (listen(proxy_socket_fd, 1) < 0)
    {
        perror("Error: Failed to listen for client connections");
        exit(EXIT_FAILURE);
    }
    
    printf("Proxy server running on port %d...\n", PROXY_PORT);
    
    // Accept incoming connections and handle them in a new process
    while (1)
    {
        cli_len = sizeof(cli_address);
        client_socket_fd = accept(proxy_socket_fd, (struct sockaddr *)&cli_address, (socklen_t *)&cli_len);
        if (client_socket_fd < 0)
        {
            perror("Error: Failed to accept client connection");
            continue;
        }
        
        if (!fork())
        {
            close(proxy_socket_fd);
            proxy(client_socket_fd);
            exit(EXIT_SUCCESS);
        }
        
        close(client_socket_fd);
    }
    
    return 0;
}