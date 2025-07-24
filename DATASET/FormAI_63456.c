//FormAI DATASET v1.0 Category: Simple Web Server ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8000 // Port number to run server on
#define MAX_REQUEST_SIZE 2048 // Maximum size for incoming HTTP requests
#define MAX_RESPONSE_SIZE 1024 // Maximum size for outgoing HTTP response

int main(int argc, char const *argv[])
{
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char request_buffer[MAX_REQUEST_SIZE] = {0}; // Incoming request buffer
    char response_buffer[MAX_RESPONSE_SIZE] = {0}; // Outgoing response buffer
    char *response_body = "<html><h1>Hello, World!</h1></html>"; // Response body content
    
    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }
    
    // Set socket options to reuse address and port
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }
    
    // Bind socket to port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
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
    
    // Accept incoming connections and handle requests
    while(1)
    {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0)
        {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }
        
        // Read incoming request
        valread = read(new_socket, request_buffer, MAX_REQUEST_SIZE);
        fprintf(stdout, "%s\n", request_buffer);
        
        // Send response
        sprintf(response_buffer, "HTTP/1.1 200 OK\nContent-Type: text/html\nContent-Length: %ld\n\n%s", strlen(response_body), response_body);
        send(new_socket, response_buffer, strlen(response_buffer), 0);
        
        // Close socket
        close(new_socket);
    }
    
    return 0;
}