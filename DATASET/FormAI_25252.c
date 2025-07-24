//FormAI DATASET v1.0 Category: Chat server ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define MAX_MSG_LENGTH 1024

// Structures for easy handling of clients
typedef struct {
    int sock_fd;
    int should_listen;
} client_socket;

// Global variables
static int server_socket; // Server socket
static int client_count = 0; // Number of connected clients
static client_socket clients[MAX_CLIENTS]; // Array of connected clients
static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // Mutex for thread-safe access to clients array

/**
 * Perform cleanup and exit program
 */
void exit_server() {
    close(server_socket);
    for (int i = 0; i < client_count; i++) {
        close(clients[i].sock_fd);
    }
    pthread_mutex_destroy(&mutex);
    exit(0);
}

/**
 * Handle incoming messages from client
 */
void *handle_client(void *socket_ptr) {
    int sock_fd = *((int *) socket_ptr);
    char msg[MAX_MSG_LENGTH];
    int read_size;

    while ((read_size = recv(sock_fd, msg, MAX_MSG_LENGTH, 0)) > 0) {
        // Lock mutex to prevent race conditions when accessing shared client array
        pthread_mutex_lock(&mutex);

        // Broadcast message to all clients
        for (int i = 0; i < client_count; i++) {
            if (clients[i].sock_fd != sock_fd) {
                send(clients[i].sock_fd, msg, read_size, 0);
            }
        }

        // Unlock mutex
        pthread_mutex_unlock(&mutex);
    }

    // Remove client from array
    int found_client = 0;
    for (int i = 0; i < client_count; i++) {
        if (clients[i].sock_fd == sock_fd) {
            found_client = 1;
            for (int j = i; j < client_count - 1; j++) {
                clients[j] = clients[j+1];
            }
            client_count--;
            break;
        }
    }

    // Close socket and exit thread
    if (found_client) {
        close(sock_fd);
    }
    pthread_exit(NULL);
}

int main(int argc, char const *argv[]) {
    int port_number = 8888;

    // Create server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        fprintf(stderr, "Failed to create socket!\n");
        exit_server();
    }

    // Bind socket to port number
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET; // Use IPv4
    server_addr.sin_addr.s_addr = INADDR_ANY; // Accept connections from any IP address
    server_addr.sin_port = htons(port_number); // Convert port number to network byte order
    if (bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        fprintf(stderr, "Failed to bind to port %d!\n", port_number);
        exit_server();
    }

    // Start listening for incoming connections
    if (listen(server_socket, 5) < 0) { // Allow 5 queued connections
        fprintf(stderr, "Failed to listen for incoming connections!\n");
        exit_server();
    }

    // Wait for incoming connections
    struct sockaddr_in client_addr;
    int client_sock;
    socklen_t client_len = sizeof(client_addr);
    while (1) {
        client_sock = accept(server_socket, (struct sockaddr *) &client_addr, &client_len);
        if (client_sock < 0) {
            fprintf(stderr, "Failed to accept incoming connection!\n");
            continue;
        }

        // Add client to array
        pthread_mutex_lock(&mutex);
        if (client_count < MAX_CLIENTS) {
            clients[client_count].sock_fd = client_sock;
            clients[client_count].should_listen = 1;

            // Start thread to handle client messages
            pthread_t tid;
            if (pthread_create(&tid, NULL, handle_client, (void *) &client_sock) != 0) {
                fprintf(stderr, "Failed to start client thread!\n");
            }

            client_count++;
        } else {
            fprintf(stderr, "Maximum number of clients reached! Rejecting connection.\n");
            close(client_sock);
        }
        pthread_mutex_unlock(&mutex);
    }

    exit_server();
    return 0;
}