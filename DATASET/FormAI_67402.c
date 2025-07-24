//FormAI DATASET v1.0 Category: Networking ; Style: Linus Torvalds
// This is a program for a simple chat server which can communicate with multiple clients simultaneously.
// Written in the style of Linus Torvalds
// Created by Chatbot
// Date: 16 August, 2021

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/select.h>

// Constants
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

// Function Prototypes
void add_client(int client_fd, int *clients, int *max_clients);
void remove_client(int client_fd, int *clients, int *max_clients);
void broadcast_message(char *message, int *clients, int max_clients, int sender_fd);

// Main Function
int main(int argc, char *argv[]) {
    printf("Starting Chat Server...\n");
    
    // Initialize Server Address and Port Number
    int port_num = 8888;
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port_num);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Create Socket
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("Error: Socket Creation Failed");
        exit(EXIT_FAILURE);
    }
    printf("Socket created successfully...\n");

    // Bind Socket to Address and Port
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error: Socket Binding Failed");
        exit(EXIT_FAILURE);
    }
    printf("Socket bound successfully...\n");

    // Listen for Incoming Connections
    if (listen(server_fd, MAX_CLIENTS) == -1) {
        perror("Error: Listening Failed");
        exit(EXIT_FAILURE);
    }
    printf("Now listening for incoming connections...\n");

    // Initialize Client Sockets and Maximum Clients
    int clients[MAX_CLIENTS];
    int max_clients = 0;
    for (int i = 0; i < MAX_CLIENTS; i++) {
        clients[i] = -1;
    }

    // Set of Sockets for Select Function
    fd_set read_sockets;
    while (1) {
        // Clear the Set of Sockets
        FD_ZERO(&read_sockets);
        FD_SET(server_fd, &read_sockets);
        int max_socket_fd = server_fd;

        // Add Client Sockets to Set of Sockets
        for (int i = 0; i < max_clients; i++) {
            int client_fd = clients[i];
            if (client_fd != -1) {
                FD_SET(client_fd, &read_sockets);
                if (client_fd > max_socket_fd) {
                    max_socket_fd = client_fd;
                }
            }
        }

        // Wait for Activity on Any of the Sockets
        if (select(max_socket_fd + 1, &read_sockets, NULL, NULL, NULL) == -1) {
            perror("Error: Select Failed");
            exit(EXIT_FAILURE);
        }

        // Check for Incoming Connections on Server Socket
        if (FD_ISSET(server_fd, &read_sockets)) {
            // Accept Incoming Connection
            struct sockaddr_in client_addr;
            socklen_t client_addr_len = sizeof(client_addr);
            int client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_addr_len);
            if (client_fd == -1) {
                perror("Error: Accept Failed");
                exit(EXIT_FAILURE);
            }
            printf("New client connected from %s:%d...\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

            // Add Client to List of Clients
            add_client(client_fd, clients, &max_clients);
        }

        // Check for Data on Client Sockets
        for (int i = 0; i < max_clients; i++) {
            int client_fd = clients[i];
            if (FD_ISSET(client_fd, &read_sockets)) {
                // Read Data from Client Socket
                char buffer[BUFFER_SIZE] = {0};
                int num_bytes = read(client_fd, buffer, BUFFER_SIZE);
                if (num_bytes == -1) {
                    perror("Error: Read Failed");
                    exit(EXIT_FAILURE);
                } else if (num_bytes == 0) {
                    // Client Disconnected
                    remove_client(client_fd, clients, &max_clients);
                    printf("Client disconnected...\n");
                } else {
                    // Broadcast Data to Other Client Sockets
                    printf("Message received: %s", buffer);
                    broadcast_message(buffer, clients, max_clients, client_fd);
                }
            }
        }
    }

    // Close Server Socket
    close(server_fd);

    return 0;
}

// Function to Add Client to List of Clients
void add_client(int client_fd, int *clients, int *max_clients) {
    // Find Empty Slot in List of Clients
    int i;
    for (i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i] == -1) {
            clients[i] = client_fd;
            break;
        }
    }

    // Check if List of Clients is Full
    if (i == MAX_CLIENTS) {
        fprintf(stderr, "Error: Maximum number of clients reached...\n");
        exit(EXIT_FAILURE);
    }

    // Increment Maximum Clients
    (*max_clients)++;
}

// Function to Remove Client from List of Clients
void remove_client(int client_fd, int *clients, int *max_clients) {
    // Find and Remove Client from List of Clients
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i] == client_fd) {
            clients[i] = -1;
            break;
        }
    }

    // Decrement Maximum Clients
    (*max_clients)--;
}

// Function to Broadcast Message to Other Client Sockets
void broadcast_message(char *message, int *clients, int max_clients, int sender_fd) {
    for (int i = 0; i < max_clients; i++) {
        int client_fd = clients[i];
        if (client_fd != -1 && client_fd != sender_fd) {
            if (write(client_fd, message, strlen(message)) == -1) {
                perror("Error: Write Failed");
                exit(EXIT_FAILURE);
            }
        }
    }
}