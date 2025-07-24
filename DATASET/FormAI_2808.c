//FormAI DATASET v1.0 Category: Simple Web Server ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>

// Function prototype for handling HTTP requests
void handle_request(int client_socket);

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t address_length = sizeof(server_address);
    
    // Create the socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Failed to create server socket.");
        exit(EXIT_FAILURE);
    }
    
    // Bind the socket to the IP address and port
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8080);
    if (bind(server_socket, (struct sockaddr*) &server_address, address_length) < 0) {
        perror("Failed to bind server socket.");
        exit(EXIT_FAILURE);
    }
    
    // Listen for connections
    if (listen(server_socket, 10) < 0) {
        perror("Failed to listen for connections.");
        exit(EXIT_FAILURE);
    }
    
    printf("Server running on port 8080...\n");
    
    // Accept incoming connections and handle them
    while (1) {
        client_socket = accept(server_socket, (struct sockaddr*) &client_address, &address_length);
        if (client_socket < 0) {
            perror("Failed to accept client connection.");
            continue;
        }
        // Handle the HTTP request
        handle_request(client_socket);
        // Close the client socket
        close(client_socket);
    }
    
    // Close the server socket
    close(server_socket);
    return 0;
}

void handle_request(int client_socket) {
    char buffer[1024];
    ssize_t bytes_read;
    
    // Read the HTTP request
    bytes_read = read(client_socket, buffer, 1024);
    if (bytes_read < 0) {
        perror("Failed to read HTTP request.");
        return;
    }
    
    // Construct the HTTP response
    const char* response_header = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n";
    const char* response_body = "<html><head><title>Peaceful Web Server</title></head><body><h1>Welcome to my calm and peaceful web server</h1><p>Take a deep breath, relax, and enjoy this server's tranqulity.</p></body></html>";
    
    // Write the response header to the client socket
    write(client_socket, response_header, strlen(response_header));
    
    // Write the response body to the client socket
    write(client_socket, response_body, strlen(response_body));
}