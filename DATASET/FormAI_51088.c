//FormAI DATASET v1.0 Category: Chat server ; Style: real-life
/*
 * Chat Server Example Program in C
 * 
 * This program creates a chat server that allows multiple clients to connect,
 * send and receive messages from each other. 
 *
 * Author: [Your Name]
 * Date: [Current Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define PORT 8080 // Port number for client connections
#define MAX_CLIENTS 50 // Maximum number of client connections allowed at once
#define BUFFER_SIZE 1024 // Maximum message size for send/receive

// Custom struct for client connections
typedef struct {
    int socket_fd; // Socket file descriptor for the client
    struct sockaddr_in address; // Address of the client
    char username[20]; // Username of the client
} client_info;

// Global variables
client_info clients[MAX_CLIENTS]; // Array to hold client information
int num_clients = 0; // Number of currently connected clients

// Function to handle incoming client connections
void *handle_client(void *arg) {
    int client_index = *(int *)arg; // Get the index of the client in the clients array
    char buffer[BUFFER_SIZE]; // Buffer to hold message received from client
    
    // Send a welcome message to the client
    sprintf(buffer, "Welcome to the chat server, %s!\n", clients[client_index].username);
    write(clients[client_index].socket_fd, buffer, strlen(buffer));
    
    while (1) {
        // Receive message from client
        memset(buffer, 0, BUFFER_SIZE); // Clear the buffer
        read(clients[client_index].socket_fd, buffer, BUFFER_SIZE);
        
        // Check if the client has disconnected
        if (strlen(buffer) == 0) {
            printf("Client %s disconnected.\n", clients[client_index].username);
            close(clients[client_index].socket_fd);
            clients[client_index].socket_fd = 0;
            clients[client_index].username[0] = '\0';
            num_clients--;
            pthread_exit(NULL); // Exit thread
        }
        
        // Send message to all connected clients
        sprintf(buffer, "%s: %s", clients[client_index].username, buffer);
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (clients[i].socket_fd != 0 && i != client_index) {
                write(clients[i].socket_fd, buffer, strlen(buffer));
            }
        }
    }
}

int main(int argc, char const *argv[]) {
    int server_fd, new_socket, valread; 
    struct sockaddr_in address; 
    int opt = 1; 
    int addrlen = sizeof(address); 
    char buffer[BUFFER_SIZE] = {0}; 
    
    // Create a socket file descriptor for the server
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) { 
        perror("socket failed"); 
        exit(EXIT_FAILURE); 
    } 
    
    // Set socket options to reuse the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) { 
        perror("setsockopt"); 
        exit(EXIT_FAILURE); 
    } 
    
    // Set up the address structure for the server
    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons( PORT ); 
    
    // Bind the socket to the address and port specified
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) { 
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    } 
    
    // Listen for incoming connections
    if (listen(server_fd, MAX_CLIENTS) < 0) { 
        perror("listen"); 
        exit(EXIT_FAILURE); 
    }
    
    printf("Chat server is running on port %d.\n", PORT);
    
    while (1) {
        // Wait for incoming connection request
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) { 
            perror("accept"); 
            exit(EXIT_FAILURE); 
        }
        
        // Check if maximum number of clients is already connected
        if (num_clients == MAX_CLIENTS) {
            printf("Maximum number of clients reached. Connection rejected.\n");
            close(new_socket);
            continue;
        }
        
        // Receive username from client
        memset(buffer, 0, BUFFER_SIZE); // Clear the buffer
        read(new_socket, buffer, BUFFER_SIZE);
        printf("New connection from %s:%d. Username: %s\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port), buffer);
        
        // Add the client to the array and start a thread to handle their messages
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (clients[i].socket_fd == 0) {
                clients[i].socket_fd = new_socket;
                clients[i].address = address;
                strcpy(clients[i].username, buffer);
                num_clients++;
                int client_index = i;
                pthread_t thread_id;
                pthread_create(&thread_id, NULL, handle_client, (void *)&client_index);
                break;
            }
        }
    }
    
    return 0; 
}