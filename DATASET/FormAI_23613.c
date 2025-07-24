//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENTS 20
#define BUFFER_SIZE 1024

int server_fd;
int client_fds[MAX_CLIENTS] = {0};
struct sockaddr_in server_address, client_address;
socklen_t client_address_len = sizeof(client_address);

void handle_disconnect(int client_index) {
    printf("Client %d disconnected\n", client_index);
    close(client_fds[client_index]);
    client_fds[client_index] = 0;
}

void handle_message(int client_index, char* message) {
    printf("Received message from client %d: %s\n", client_index, message);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (client_fds[i] && i != client_index) {
            send(client_fds[i], message, strlen(message), 0);
        }
    }
}

void signal_handler(int signal) {
    printf("Received signal %d, closing server...\n", signal);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (client_fds[i]) {
            close(client_fds[i]);
        }
    }
    close(server_fd);
    exit(0);
}

int main() {
    signal(SIGINT, signal_handler); // Handle SIGINT signal to gracefully shutdown server
    
    // Create TCP socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }
    
    // Configure server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8080);
    
    // Bind socket and address
    if (bind(server_fd, (struct sockaddr*) &server_address, sizeof(server_address)) < 0) {
        perror("Failed to bind socket");
        exit(EXIT_FAILURE);
    }
    
    // Listen for incoming connections
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("Failed to listen for connections");
        exit(EXIT_FAILURE);
    }
    
    printf("Server listening on port 8080...\n");
    
    while (1) {
        // Wait for a client to connect
        int client_fd;
        if ((client_fd = accept(server_fd, (struct sockaddr*) &client_address, &client_address_len)) < 0) {
            perror("Failed to accept connection");
            exit(EXIT_FAILURE);
        }
        
        // Add client to list of active clients
        int client_index = -1;
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (!client_fds[i]) {
                client_fds[i] = client_fd;
                client_index = i;
                break;
            }
        }
        if (client_index == -1) {
            printf("Maximum number of clients reached, closing new connection");
            close(client_fd);
            continue;
        }
        
        printf("Client %d connected from %s:%d\n", client_index, inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
        
        // Start receiving messages from client
        char buffer[BUFFER_SIZE] = {0};
        while (1) {
            int read_size = recv(client_fd, buffer, BUFFER_SIZE, 0);
            if (read_size == 0) { // Client disconnected
                handle_disconnect(client_index);
                break;
            } else if (read_size < 0) { // Error receiving message
                perror("Error receiving message from client");
                handle_disconnect(client_index);
                break;
            } else { // Message received, handle it
                handle_message(client_index, buffer);
                memset(buffer, 0, BUFFER_SIZE); // Clear buffer for next message
            }
        }
    }
}