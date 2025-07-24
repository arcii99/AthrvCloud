//FormAI DATASET v1.0 Category: Socket programming ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

// Function to handle socket communication
void socketHandler(int client_socket) {
    char buffer[BUFFER_SIZE];
    char *message = "Welcome to the server!\n";
    send(client_socket, message, strlen(message), 0);
    
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int read_size = recv(client_socket, buffer, BUFFER_SIZE, 0);
        
        if (read_size == 0) {
            printf("Client disconnected\n");
            break;
        }
        
        printf("Client message: %s", buffer);
        send(client_socket, buffer, read_size, 0);
    }
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    char *ip_address = "127.0.0.1";
    int port_number = 8080;
    
    // Create a server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Could not create socket\n");
        return 1;
    }
    
    // Set the server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(ip_address);
    server_address.sin_port = htons(port_number);
    
    // Bind the socket to the server address
    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
        printf("Could not bind socket\n");
        return 1;
    }
    
    // Listen for incoming connections
    if (listen(server_socket, 1) == -1) {
        printf("Could not listen for connections\n");
        return 1;
    }
    
    printf("Server started\n");
    printf("Listening on %s:%d\n", ip_address, port_number);
    
    // Accept incoming connections
    while (1) {
        socklen_t client_address_size = sizeof(client_address);
        client_socket = accept(server_socket, (struct sockaddr *) &client_address, &client_address_size);
        
        if (client_socket == -1) {
            printf("Could not accept connection\n");
            continue;
        }
        
        printf("Client connected: %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
        
        // Fork a new process to handle communication with the client
        pid_t child_pid = fork();
        
        if (child_pid < 0) {
            printf("Could not fork a new process\n");
            return 1;
        } else if (child_pid == 0) {
            // Child process
            close(server_socket);
            socketHandler(client_socket);
            exit(0);
        } else {
            // Parent process
            close(client_socket);
        }
    }
    
    close(server_socket);
    return 0;
}