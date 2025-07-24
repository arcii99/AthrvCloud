//FormAI DATASET v1.0 Category: Client Server Application ; Style: realistic
// Unique C Client Server Application Example Program
// By: [Your Name]

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

static int clients_count = 0; // Counter to keep track of clients connected to the server.

static int server_socket; // The socket that the server listens to.

static int clients[MAX_CLIENTS]; // Array to hold the sockets of clients connected to the server.

void handle_client_connection(int client_socket) {
    // This function handles client connections to the server.

    char buffer[BUFFER_SIZE]; // Buffer to hold incoming messages.

    while (1) {
        // Receive incoming message from client.
        memset(buffer, 0, BUFFER_SIZE); // Clear the buffer before use.
        int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);

        if (bytes_received == -1) {
            // An error occurred while trying to receive the message.
            printf("Error receiving message from client.\n");
            break;
        }

        if (bytes_received == 0) {
            // Client has closed the connection.
            printf("Client disconnected.\n");
            break;
        }

        // Print the received message.
        printf("Received message: %s\n", buffer);

        // Echo the received message back to the client.
        if (send(client_socket, buffer, bytes_received, 0) == -1) {
            // An error occurred while trying to send the message.
            printf("Error echoing message to client.\n");
            break;
        }
    }

    // Close the socket when connection is closed.
    close(client_socket);
    clients_count--;
    pthread_exit(NULL);
}

int main() {
    // Create the server socket.
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket == -1) {
        // An error occurred while creating the socket.
        printf("Error creating socket.\n");
        exit(EXIT_FAILURE);
    }

    // Configure the server address and port.
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(PORT);

    // Bind the server socket to the configured address and port.
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        // An error occurred while trying to bind the socket.
        printf("Error binding socket.\n");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming client connections.
    if (listen(server_socket, MAX_CLIENTS) == -1) {
        // An error occurred while trying to listen on the socket.
        printf("Error listening on socket.\n");
        exit(EXIT_FAILURE);
    }

    // Accept incoming client connections.
    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);

        if (client_socket == -1) {
            // An error occurred while accepting the connection.
            printf("Error accepting connection.\n");
            continue;
        }

        // Check if we have reached the maximum number of clients.
        if (clients_count == MAX_CLIENTS) {
            // We have reached the maximum number of clients, so reject the connection.
            printf("Rejecting connection. Maximum number of clients reached.\n");
            close(client_socket);
            continue;
        }

        // Add the client socket to the clients array.
        clients[clients_count] = client_socket;

        // Spin off a new thread to handle the client connection.
        pthread_t thread;
        if (pthread_create(&thread, NULL, (void *)handle_client_connection, (void *)client_socket) != 0) {
            // An error occurred while trying to create the thread.
            printf("Error creating thread.\n");
            break;
        }

        clients_count++;
    }

    // Close the server socket when done.
    close(server_socket);

    return 0;
}