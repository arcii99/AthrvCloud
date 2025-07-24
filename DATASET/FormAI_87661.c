//FormAI DATASET v1.0 Category: Chat server ; Style: distributed
/*
* A Chat Server in C using Distributed Architecture
* Author: [Your Name]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <signal.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

// Structure to store client details
struct client {
    struct sockaddr_in address;
    int sock_fd;
    char username[20];
    bool active;
};

// Global variables
struct client clients[MAX_CLIENTS];
pthread_mutex_t lock;

// Function to handle incoming messages from client
void *handle_client(void *data) {
    int client_fd = *(int *)data;
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);

    // Get the client's details
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    if (getpeername(client_fd, (struct sockaddr *)&client_addr, &client_addr_len) == -1) {
        perror("Error getting client details");
        close(client_fd);
        return NULL;
    }

    // Retrieve client data from global array
    struct client *current_client;
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i].active && clients[i].sock_fd == client_fd) {
            current_client = &clients[i];
            break;
        }
    }

    // Receive messages from client
    while (recv(client_fd, buffer, BUFFER_SIZE, 0) > 0) {
        printf("%s: %s\n", current_client->username, buffer);
        memset(buffer, 0, BUFFER_SIZE);
    }

    // Client has disconnected
    printf("%s has disconnected.\n", current_client->username);
    current_client->active = false;
    close(client_fd);
}

int main(int argc, char const *argv[]) {
    // Initialize global variables
    memset(clients, 0, sizeof(clients));
    pthread_mutex_init(&lock, NULL);

    // Create server socket
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("Error creating server socket");
        return EXIT_FAILURE;
    }

    // Configure server address
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);

    // Bind server socket to address
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error binding server socket");
        close(server_fd);
        return EXIT_FAILURE;
    }

    // Listen for incoming connections
    if (listen(server_fd, MAX_CLIENTS) == -1) {
        perror("Error listening for connections");
        close(server_fd);
        return EXIT_FAILURE;
    }

    printf("Server listening on port 8080...\n");

    while (true) {
        // Accept incoming client connection
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_fd == -1) {
            perror("Error accepting client connection");
            continue;
        }

        // Add new client to global array
        pthread_mutex_lock(&lock);
        bool added = false;
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (!clients[i].active) {
                clients[i].address = client_addr;
                clients[i].sock_fd = client_fd;
                clients[i].active = true;
                added = true;

                // Retrieve username from client
                recv(client_fd, clients[i].username, 20, 0);
                printf("%s has connected.\n", clients[i].username);

                pthread_t thread_id;
                pthread_create(&thread_id, NULL, handle_client, &clients[i].sock_fd);
                break;
            }
        }
        pthread_mutex_unlock(&lock);

        if (!added) {
            printf("Maximum number of clients reached. Closing connection.\n");
            close(client_fd);
        }
    }

    // Close server socket and destroy mutex
    close(server_fd);
    pthread_mutex_destroy(&lock);

    return EXIT_SUCCESS;
}