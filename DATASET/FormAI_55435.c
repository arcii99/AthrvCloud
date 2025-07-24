//FormAI DATASET v1.0 Category: Client Server Application ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

// Define server parameters
#define PORT 8080
#define MAX_CONN 10

// Define server response message
char *server_message = "Hello client! Welcome to the server.";

// Handle client requests
void *handle_client(void *arg) {
    int client_socket = *(int *)arg;
    char buffer[1024];

    // Read and display client request
    read(client_socket, buffer, 1024);
    printf("Message from client: %s\n", buffer);

    // Send response to client
    write(client_socket, server_message, strlen(server_message));

    // Close client socket
    close(client_socket);

    pthread_exit(NULL);
}

int main() {
    int server_socket, client_socket, addr_len;
    struct sockaddr_in server_address, client_address;

    // Create server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // Initialize server parameters
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind server socket to specified address and port
    bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address));

    // Listen for incoming client connections
    listen(server_socket, MAX_CONN);
    printf("Server running on port %d...\n", PORT);

    while (1) {
        // Accept incoming client connection
        addr_len = sizeof(client_address);
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, (socklen_t *)&addr_len);

        // Create new thread to handle client request
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void *)&client_socket);
    }

    return 0;
}