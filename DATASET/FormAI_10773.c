//FormAI DATASET v1.0 Category: Chat server ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10

// Global variables
int client_count = 0;
int client_socket_list[MAX_CLIENTS];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Function declarations
void send_message(char *message, int sender_socket);
void remove_client(int client_socket);
void *handle_client(void *arg);

int main() {
    int server_socket;
    struct sockaddr_in server_address, client_address;
    int client_socket;
    socklen_t address_len = sizeof(client_address);
    pthread_t thread_id;

    // Create server socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Failed to create server socket");
        exit(EXIT_FAILURE);
    }

    // Setup server address
    memset(&server_address, '0', sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind server socket to address and port
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Failed to bind server socket");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Failed to listen for incoming connections");
        exit(EXIT_FAILURE);
    }

    // Loop to accept and handle incoming connections
    while (1) {
        // Accept incoming connection
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_address, (socklen_t *)&address_len)) < 0) {
            perror("Failed to accept incoming connection");
            exit(EXIT_FAILURE);
        }

        // Add client socket to list
        pthread_mutex_lock(&mutex);
        client_socket_list[client_count++] = client_socket;
        pthread_mutex_unlock(&mutex);

        // Create thread to handle client socket
        if (pthread_create(&thread_id, NULL, handle_client, (void *)&client_socket) < 0) {
            perror("Failed to create thread for client");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}

// Function to send message to all clients except the sender
void send_message(char *message, int sender_socket) {
    pthread_mutex_lock(&mutex);
    for (int i = 0; i < client_count; i++) {
        if (client_socket_list[i] != sender_socket) {
            send(client_socket_list[i], message, strlen(message), 0);
        }
    }
    pthread_mutex_unlock(&mutex);
}

// Function to remove client from list and close socket
void remove_client(int client_socket) {
    pthread_mutex_lock(&mutex);
    for (int i = 0; i < client_count; i++) {
        if (client_socket_list[i] == client_socket) {
            client_count--;
            for (int j = i; j < client_count; j++) {
                client_socket_list[j] = client_socket_list[j+1];
            }
            break;
        }
    }
    pthread_mutex_unlock(&mutex);
    close(client_socket);
}

// Function to handle client messages
void *handle_client(void *arg) {
    int client_socket = *((int *)arg);
    char buffer[1024];
    int read_size;

    // Send welcome message to client
    char *welcome_message = "Welcome to the chat server!";
    send(client_socket, welcome_message, strlen(welcome_message), 0);

    // Loop to receive messages from client
    while ((read_size = recv(client_socket, buffer, sizeof(buffer), 0)) > 0) {
        buffer[read_size] = '\0';
        send_message(buffer, client_socket);
    }

    // Remove client from list and close socket
    remove_client(client_socket);

    return NULL;
}