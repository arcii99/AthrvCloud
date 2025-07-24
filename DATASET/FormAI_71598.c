//FormAI DATASET v1.0 Category: Chat server ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

// Macro definitions
#define PORT 8080
#define BUFFER_SIZE 1024
#define MAX_CLIENTS 10

// Function prototypes
void handle_new_connection(int socket_fd, fd_set* active_fd_set, int* client_fds, int* max_fd);
void handle_client_request(int client_fd, fd_set* active_fd_set, int* client_fds, int* max_fd);
void close_client_connection(int client_fd, fd_set* active_fd_set, int* client_fds, int* max_fd);

// Main function
int main() {
    int server_fd, client_fds[MAX_CLIENTS];
    struct sockaddr_in address;

    // Create TCP socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("Error setting socket options");
        exit(EXIT_FAILURE);
    }

    // Bind socket to port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("Error binding socket to port");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("Error listening for incoming connections");
        exit(EXIT_FAILURE);
    }

    // Create set of active file descriptors
    fd_set active_fd_set;
    FD_ZERO(&active_fd_set);
    FD_SET(server_fd, &active_fd_set);

    // Initialize array of client file descriptors and max file descriptor
    int max_fd = server_fd;
    memset(client_fds, -1, MAX_CLIENTS * sizeof(int));

    printf("Server is listening on port %d\n", PORT);

    while (true) {
        // Wait for activity on any file descriptor in the set
        fd_set read_fd_set = active_fd_set;
        if (select(max_fd + 1, &read_fd_set, NULL, NULL, NULL) < 0) {
            perror("Error waiting for activity on file descriptors");
            exit(EXIT_FAILURE);
        }

        // Check each file descriptor for activity
        for (int fd = 0; fd <= max_fd; fd++) {
            if (FD_ISSET(fd, &read_fd_set)) {
                if (fd == server_fd) {
                    // New connection request
                    handle_new_connection(server_fd, &active_fd_set, client_fds, &max_fd);
                } else {
                    // Client activity
                    handle_client_request(fd, &active_fd_set, client_fds, &max_fd);
                }
            }
        }
    }

    // Close server socket
    close(server_fd);

    return 0;
}

// Handle new connection request
void handle_new_connection(int socket_fd, fd_set* active_fd_set, int* client_fds, int* max_fd) {
    struct sockaddr_in client_address;
    int client_address_len = sizeof(client_address);

    // Accept the new connection
    int client_fd = accept(socket_fd, (struct sockaddr*)&client_address, (socklen_t*)&client_address_len);
    if (client_fd < 0) {
        perror("Error accepting connection");
        exit(EXIT_FAILURE);
    }

    // Add client file descriptor to active set and client array
    FD_SET(client_fd, active_fd_set);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (client_fds[i] == -1) {
            client_fds[i] = client_fd;
            break;
        }
    }

    // Update max file descriptor
    if (client_fd > *max_fd) {
        *max_fd = client_fd;
    }

    printf("New connection from %s:%d (socket_fd=%d)\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port), client_fd);
}

// Handle client request
void handle_client_request(int client_fd, fd_set* active_fd_set, int* client_fds, int* max_fd) {
    char buffer[BUFFER_SIZE] = {0};
    int message_len;

    // Receive client message
    if ((message_len = recv(client_fd, buffer, BUFFER_SIZE, 0)) <= 0) {
        // Client closed connection or error occurred, close client connection
        close_client_connection(client_fd, active_fd_set, client_fds, max_fd);
    } else {
        // Display client message
        printf("[%d]: %s", client_fd, buffer);

        // Send message to all other clients
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (client_fds[i] != -1 && client_fds[i] != client_fd) {
                send(client_fds[i], buffer, message_len, 0);
            }
        }
    }
}

// Close client connection
void close_client_connection(int client_fd, fd_set* active_fd_set, int* client_fds, int* max_fd) {
    // Remove client file descriptor from active set and client array
    FD_CLR(client_fd, active_fd_set);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (client_fds[i] == client_fd) {
            client_fds[i] = -1;
            break;
        }
    }

    // Update max file descriptor
    if (client_fd == *max_fd) {
        while (client_fds[*max_fd - 1] == -1 && *max_fd > 0) {
            (*max_fd)--;
        }
    }

    printf("Client %d has disconnected\n", client_fd);

    // Close client socket
    close(client_fd);
}