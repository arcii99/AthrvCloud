//FormAI DATASET v1.0 Category: Networking ; Style: thoughtful
/*
 * This is a networking program that communicates between client and server.
 * The server broadcasts a message to all connected clients and clients can respond directly to the server.
 * The server operates on port 8080.
 * The client can connect to the server by specifying the server IP address and port number.
 * When a client connects, it sends a message to the server which is then broadcasted to all connected clients.
 * The clients can then respond to the broadcasted message directly to the server.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define SERVER_PORT 8080

void *receive_broadcast(void *args);

int main(int argc, char *argv[]) {
    // Create socket
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }
    
    // Bind socket to port 8080
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(SERVER_PORT);
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind error");
        exit(EXIT_FAILURE);
    }
    
    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen error");
        exit(EXIT_FAILURE);
    }
    printf("Server started on port %d\n", SERVER_PORT);
    
    // Accept incoming connections
    int client_socket;
    struct sockaddr_in client_address;
    int addrlen = sizeof(client_address);
    if ((client_socket = accept(server_fd, (struct sockaddr *)&client_address, (socklen_t *)&addrlen)) < 0) {
        perror("Accept error");
        exit(EXIT_FAILURE);
    }
    
    printf("Connection established with client %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
    
    // Broadcast message to all connected clients
    char *message = "Broadcast message from server";
    send(client_socket, message, strlen(message), 0);
    
    // Start a separate thread to receive broadcasts from other clients
    pthread_t thread;
    int result = pthread_create(&thread, NULL, receive_broadcast, (void *)&client_socket);
    if (result != 0) {
        perror("Thread creation error");
        exit(EXIT_FAILURE);
    }
    
    // Read message from client and respond directly
    char buffer[1024] = {0};
    while (1) {
        int bytes_read = read(client_socket, buffer, 1024);
        if (bytes_read <= 0) {
            break;
        }
        printf("Received message from client: %s", buffer);
        
        // Respond to client
        char *response = "Response to client from server";
        send(client_socket, response, strlen(response), 0);
    }
    
    // Close client socket
    close(client_socket);
    printf("Client disconnected\n");
    
    // Close server socket
    close(server_fd);
    
    return 0;
}

void *receive_broadcast(void *args) {
    int client_socket = *(int *)args;
    char buffer[1024] = {0};
    while (1) {
        int bytes_read = read(client_socket, buffer, 1024);
        if (bytes_read <= 0) {
            break;
        }
        printf("Received broadcast from client: %s", buffer);
    }
    pthread_exit(NULL);
}