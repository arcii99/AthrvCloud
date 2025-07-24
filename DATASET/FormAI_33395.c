//FormAI DATASET v1.0 Category: Chat server ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<pthread.h>

// Define the maximum number of clients that can connect to the server
#define MAX_CLIENTS 10

// Struct to hold data for individual clients
typedef struct {
    int client_socket;
    char* client_name;
} client_data;

// Array to store individual client data
client_data clients[MAX_CLIENTS];

// Mutex lock to ensure thread-safe access to clients array
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to handle individual client connections
void* handle_client(void* arg) {
    int client_socket = *(int*) arg;
    char message[256];
    char client_name[20];
    
    // Ask client for their name
    write(client_socket, "Enter your name:", 16);
    read(client_socket, client_name, 20);
    
    // Add client data to clients array
    pthread_mutex_lock(&mutex);
    for(int i = 0; i < MAX_CLIENTS; i++) {
        if(clients[i].client_socket == -1) {
            clients[i].client_socket = client_socket;
            clients[i].client_name = strdup(client_name);
            break;
        }
    }
    pthread_mutex_unlock(&mutex);
    
    // Handle client messages until they disconnect
    while(read(client_socket, message, 256) > 0) {
        // Format message with client name
        sprintf(message, "%s: %s", client_name, message);
        // Send message to all other clients
        pthread_mutex_lock(&mutex);
        for(int i = 0; i < MAX_CLIENTS; i++) {
            if(clients[i].client_socket != -1 && clients[i].client_socket != client_socket) {
                write(clients[i].client_socket, message, strlen(message) + 1);
            }
        }
        pthread_mutex_unlock(&mutex);
    }
    
    // Remove client data from clients array
    pthread_mutex_lock(&mutex);
    for(int i = 0; i < MAX_CLIENTS; i++) {
        if(clients[i].client_socket == client_socket) {
            clients[i].client_socket = -1;
            free(clients[i].client_name);
            break;
        }
    }
    pthread_mutex_unlock(&mutex);
    
    // Close client socket
    close(client_socket);
    return NULL;
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    pthread_t thread_id;
    
    // Initialize clients array with empty client sockets
    for(int i = 0; i < MAX_CLIENTS; i++) {
        clients[i].client_socket = -1;
    }
    
    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    
    // Bind socket to IP address and port
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8080);
    bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));
    
    // Listen for client connections
    listen(server_socket, 5);
    while(1) {
        // Accept client connection
        int client_address_length = sizeof(client_address);
        client_socket = accept(server_socket, (struct sockaddr*) &client_address, &client_address_length);
        if(client_socket == -1) {
            continue;
        }
        
        // Spin off thread to handle client connection
        pthread_create(&thread_id, NULL, handle_client, &client_socket);
        pthread_detach(thread_id);
    }
    
    // Close server socket
    close(server_socket);
    return 0;
}