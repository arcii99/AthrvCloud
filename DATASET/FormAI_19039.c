//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 32768

// function to handle client requests
void handle_client_request(int client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_received = 0;
    int bytes_sent = 0;
    int server_socket;
    
    // clear the buffer
    memset(buffer, 0, BUFFER_SIZE);
    
    // receive request from client
    bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
    
    if (bytes_received < 0) {
        perror("Error receiving request from client");
        exit(1);
    }
    
    // connect to server
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(80);
    server_address.sin_addr.s_addr = inet_addr("192.168.1.1");
    
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Error creating server socket");
        exit(1);
    }
    
    if (connect(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }
    
    // send request to server
    bytes_sent = send(server_socket, buffer, bytes_received, 0);
    
    if (bytes_sent < 0) {
        perror("Error sending request to server");
        exit(1);
    }
    
    // receive response from server and send to client
    memset(buffer, 0, BUFFER_SIZE);
    
    while ((bytes_received = recv(server_socket, buffer, BUFFER_SIZE, 0)) > 0) {
        bytes_sent = send(client_socket, buffer, bytes_received, 0);
        
        if (bytes_sent < 0) {
            perror("Error sending response to client");
            exit(1);
        }
        
        memset(buffer, 0, BUFFER_SIZE);
    }
    
    if (bytes_received < 0) {
        perror("Error receiving response from server");
        exit(1);
    }
    
    close(server_socket);
    close(client_socket);
}

int main() {
    int server_socket;
    int client_socket;
    int port_number = 8080;
    struct sockaddr_in server_address;
    struct sockaddr_in client_address;
    socklen_t client_address_length = sizeof(client_address);
    
    // create server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Error creating server socket");
        exit(1);
    }
    
    // set server address
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port_number);
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    
    // bind server socket to server address
    if (bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        perror("Error binding server socket to server address");
        exit(1);
    }
    
    // listen for client requests
    if (listen(server_socket, 5) < 0) {
        perror("Error listening for client requests");
        exit(1);
    }
    
    printf("HTTP proxy server running on port %d\n", port_number);
    
    while (1) {
        // accept client request
        client_socket = accept(server_socket, (struct sockaddr*)&client_address, &client_address_length);
        
        if (client_socket < 0) {
            perror("Error accepting client request");
            exit(1);
        }
        
        // handle client request
        handle_client_request(client_socket);
    }
    
    close(server_socket);
    
    return 0;
}