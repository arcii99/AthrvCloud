//FormAI DATASET v1.0 Category: Chat server ; Style: genious
// This is a genius-style C Chat server program that allows multiple clients to connect and send messages to each other.

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

int client_count = 0;
int client_sockets[MAX_CLIENTS];
char usernames[MAX_CLIENTS][BUFFER_SIZE];

void broadcast(char *message, int sender) {
    pthread_mutex_lock(&lock);
    for (int i = 0; i < client_count; i++) {
        if (client_sockets[i] != sender) {
            char buffer[BUFFER_SIZE];
            sprintf(buffer, "[%s]: %s\n", usernames[sender], message);
            send(client_sockets[i], buffer, strlen(buffer), 0);
        }
    }
    pthread_mutex_unlock(&lock);
}

void *handle_client(void *arg) {
    int socket = *(int *)arg;
    char username[BUFFER_SIZE];
    
    send(socket, "Enter your username: ", strlen("Enter your username: "), 0);
    recv(socket, username, BUFFER_SIZE, 0);
    username[strcspn(username, "\n")] = 0;
    
    pthread_mutex_lock(&lock);
    client_sockets[client_count] = socket;
    strcpy(usernames[client_count], username);
    client_count++;
    pthread_mutex_unlock(&lock);
    
    printf("[%s] connected...\n", username);
    
    char buffer[BUFFER_SIZE];
    int read_bytes;
    while ((read_bytes = recv(socket, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[read_bytes - 1] = '\0'; // Replace newline with null-termination
        broadcast(buffer, socket);
    }
    
    pthread_mutex_lock(&lock);
    for (int i = 0; i < client_count; i++) {
        if (client_sockets[i] == socket) {
            for (int j = i; j < client_count - 1; j++) {
                client_sockets[j] = client_sockets[j+1];
                strcpy(usernames[j], usernames[j+1]);
            }
            client_count--;
        }
    }
    pthread_mutex_unlock(&lock);
    
    printf("[%s] disconnected...\n", username);
    close(socket);
    return NULL;
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    
    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    
    // Set socket options
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }
    
    // Bind socket to address and port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    if (bind(server_socket, (struct sockaddr *)&address, addrlen) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    
    // Listen for clients
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }
    
    printf("Server is listening on port %d...\n", PORT);
    
    while (1) {
        // Accept client connection
        if ((client_socket = accept(server_socket, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }
        
        // Handle client in a separate thread
        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, handle_client, &client_socket) < 0) {
            perror("pthread_create failed");
            exit(EXIT_FAILURE);
        }
    }
    
    return 0;
}