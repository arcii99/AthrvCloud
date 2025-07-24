//FormAI DATASET v1.0 Category: Chat server ; Style: Romeo and Juliet
// Romeo and Juliet C Chat Server
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <fcntl.h>
#include <arpa/inet.h>

#define MAX_CLIENTS 100

// Define our chat structure
typedef struct {
    int client_sock;
    struct sockaddr_in client_addr;
    char name[20];
} client_info;

client_info clients[MAX_CLIENTS];
int num_clients = 0;

// Function to add a new client to the chat
void add_client(int client_sock, struct sockaddr_in client_addr) {
    // Check if we have space for a new client
    if(num_clients >= MAX_CLIENTS) {
        printf("Chat is full!\n");
        return;
    }
    
    // Create a new client_info object and add it to the clients array
    client_info new_client;
    new_client.client_sock = client_sock;
    new_client.client_addr = client_addr;
    strcpy(new_client.name, "Anonymous");
    clients[num_clients++] = new_client;
    
    // Welcome the new client to the chat
    printf("Welcome to the chat, %s\n", new_client.name);
}

// Function to remove a client from the chat
void remove_client(int client_index) {
    // Make sure the index is valid
    if(client_index < 0 || client_index >= num_clients) {
        return;
    }
    
    // Close the client socket
    close(clients[client_index].client_sock);
    
    // Remove the client from the clients array
    if(client_index < num_clients - 1) {
        clients[client_index] = clients[num_clients - 1];
    }
    num_clients--;
}

// Function to handle incoming client connections
void handle_client_connect(int server_sock) {
    // Accept the new client connection
    struct sockaddr_in client_addr;
    unsigned int client_addr_len = sizeof(client_addr);
    int client_sock = accept(server_sock, (struct sockaddr*)&client_addr, &client_addr_len);
    if(client_sock < 0) {
        perror("Error accepting client connection");
        return;
    }
    
    // Add the new client to the chat
    add_client(client_sock, client_addr);
}

// Function to handle incoming client messages
void handle_client_message(int client_index) {
    // Get the client socket
    int client_sock = clients[client_index].client_sock;
    
    // Read the incoming message
    char buffer[1024];
    int bytes_received = recv(client_sock, buffer, sizeof(buffer), 0);
    if(bytes_received <= 0) {
        printf("%s has left the chat\n", clients[client_index].name);
        remove_client(client_index);
        return;
    }
    
    // Process the message
    buffer[bytes_received] = '\0';
    printf("%s: %s", clients[client_index].name, buffer);
    
    // Send the message to all clients except the sender
    for(int i = 0; i < num_clients; i++) {
        if(i != client_index) {
            send(clients[i].client_sock, buffer, bytes_received, 0);
        }
    }
}

// Main function
int main() {
    // Create the server socket
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if(server_sock < 0) {
        perror("Error creating server socket");
        return 1;
    }
    
    // Bind the server socket to a port
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(1234);
    server_addr.sin_addr.s_addr = INADDR_ANY;
    if(bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding server socket");
        return 1;
    }
    
    // Listen for incoming client connections
    listen(server_sock, 5);
    printf("Waiting for clients to connect...\n");
    
    // Main loop
    while(1) {
        // Set up the file descriptor set
        fd_set fds;
        FD_ZERO(&fds);
        FD_SET(STDIN_FILENO, &fds);
        FD_SET(server_sock, &fds);
        for(int i = 0; i < num_clients; i++) {
            FD_SET(clients[i].client_sock, &fds);
        }
        
        // Wait for activity on one of the file descriptors
        int max_fd = server_sock;
        for(int i = 0; i < num_clients; i++) {
            if(clients[i].client_sock > max_fd) {
                max_fd = clients[i].client_sock;
            }
        }
        select(max_fd + 1, &fds, NULL, NULL, NULL);
        
        // Check if there is activity on the server socket
        if(FD_ISSET(server_sock, &fds)) {
            handle_client_connect(server_sock);
        }
        
        // Check if there is activity on any of the client sockets
        for(int i = 0; i < num_clients; i++) {
            if(FD_ISSET(clients[i].client_sock, &fds)) {
                handle_client_message(i);
            }
        }
    }
    
    // Close the server socket
    close(server_sock);
    
    return 0;
}