//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

// Global variables
int server_fd;
struct sockaddr_in address;
int addrlen = sizeof(address);
int client_count = 0;
int client_sockets[MAX_CLIENTS];
pthread_t threads[MAX_CLIENTS];

void *serve_client(void *arg) {
    int client_socket = *(int *)arg;
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    
    // Receive data from client
    int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
    if (bytes_received <= 0) {
        printf("Error while receiving data from client.\n");
        close(client_socket);
        return NULL;
    }
    printf("Received from client: %s\n", buffer);
    
    // Send data to client
    char message[] = "Hello from server.";
    int bytes_sent = send(client_socket, message, strlen(message), 0);
    if (bytes_sent < 0) {
        printf("Error while sending data to client.\n");
        close(client_socket);
        return NULL;
    }
    printf("Sent to client: %s\n", message);
    
    close(client_socket);
    return NULL;
}

int main(int argc, char const *argv[]) {
    // Initialize server socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        printf("Error creating server socket.\n");
        return 0;
    }
    
    // Bind server socket to defined port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        printf("Error binding server socket.\n");
        return 0;
    }
    
    // Start listening for client connections
    if (listen(server_fd, 5) < 0) {
        printf("Error starting server.\n");
        return 0;
    }
    
    printf("Server is listening on port %d...\n", PORT);

    while (1) {
        // Accept client connections
        int client_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen);
        if (client_socket < 0) {
            printf("Error accepting client connection.\n");
            continue;
        }
        
        // Add client to list of active clients
        if (client_count == MAX_CLIENTS) {
            printf("Maximum number of clients reached.\n");
            close(client_socket);
            continue;
        }
        client_sockets[client_count] = client_socket;
        
        // Create new thread to serve new client
        if (pthread_create(&threads[client_count], NULL, serve_client, &client_sockets[client_count]) != 0) {
            printf("Error creating new thread.\n");
            close(client_socket);
            continue;
        }
        printf("New client connected. Assigned to thread %ld.\n", threads[client_count]);
        client_count++;
    }

    return 0;
}