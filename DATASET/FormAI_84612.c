//FormAI DATASET v1.0 Category: Simple Web Server ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
 
int main(int argc, char *argv[]) {
    // Create a TCP socket
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock == -1) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }
 
    // Set socket options
    int opt = 1;
    if (setsockopt(server_sock, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Failed to set socket options");
        exit(EXIT_FAILURE);
    }
 
    // Bind socket to a specific IP and port
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);
     
    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to bind socket");
        exit(EXIT_FAILURE);
    }
 
    // Listen for incoming connections
    if (listen(server_sock, 5) < 0) {
        perror("Failed to listen for incoming connections");
        exit(EXIT_FAILURE);
    }
 
    while (1) {
        // Accept incoming connections
        int client_sock = accept(server_sock, NULL, NULL);
        if (client_sock < 0) {
            perror("Failed to accept incoming connection");
            exit(EXIT_FAILURE);
        }
 
        // Read client request
        char buffer[1024] = {0};
        int read_bytes = read(client_sock, buffer, 1024);
        printf("%s", buffer);
 
        // Send response to client
        char *http_response = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<html><body><h1>Hello, World!</h1></body></html>";
        send(client_sock, http_response, strlen(http_response), 0);
 
        // Close client connection
        close(client_sock);
    }
 
    return 0;
}