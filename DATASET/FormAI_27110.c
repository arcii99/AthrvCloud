//FormAI DATASET v1.0 Category: Simple Web Server ; Style: imaginative
/* 
I present to you the "Magical Web Server" - a C program that will leave you enchanted! 
This program is a complete web server that listens to incoming HTTP requests and serves web pages to clients. 
It's not just a simple program, it is magical!

Disclaimer: This program is designed for educational purposes only. Do not use it for production-ready applications.

Author: The Enchanting Coder
Date: 14th June, 2022
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_CLIENTS 5
#define BUFFER_SIZE 1024

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE], *response;
    
    // Read the HTTP request from client
    recv(client_socket, buffer, BUFFER_SIZE, 0);
    
    // Prepare the response
    response = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n\
                <html><body><h1>Welcome to the Magical Web Server!</h1><p>You have been enchanted by the magic of C programming.</p></body></html>";
    
    // Send the response to client
    send(client_socket, response, strlen(response), 0);
    
    // Close the client socket
    close(client_socket);
}

int main() {
    int server_socket, client_socket, addr_len;
    struct sockaddr_in server_addr, client_addr;
    
    // Create the server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Error creating the socket");
        exit(EXIT_FAILURE);
    }
    
    // Prepare the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);
    
    // Bind the socket to server address
    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error binding the socket");
        exit(EXIT_FAILURE);
    }
    
    // Listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) == -1) {
        perror("Error listening for connections");
        exit(EXIT_FAILURE);
    }
    
    printf("The magical web server is listening on port %d...\n", ntohs(server_addr.sin_port));
    
    // Accept incoming connections and handle each client
    while (1) {
        addr_len = sizeof(client_addr);
        client_socket = accept(server_socket, (struct sockaddr*)&client_addr, (socklen_t*)&addr_len);
        
        if (client_socket == -1) {
            perror("Error accepting connection");
            continue;
        }
        
        handle_client(client_socket);
    }
    
    // Close the server socket
    close(server_socket);
    
    return 0;
}