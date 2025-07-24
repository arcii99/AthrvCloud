//FormAI DATASET v1.0 Category: Networking ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

// Global variables
int server_socket;
int client_socket[10];
pthread_t threads[10];

// Function to handle client requests
void *client_handler(void *arg) {
    int client_socket = *(int *)arg;
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));
    while(1) {
        // Receive message from client
        int msg_size = recv(client_socket, buffer, sizeof(buffer), 0);
        if (msg_size == 0) {
            // Client disconnected
            printf("Client disconnected: %d\n", client_socket);
            fflush(stdout);
            break;
        } else if (msg_size == -1) {
            // Receive error occured
            printf("Error occured while receiving from client: %d\n", client_socket);
            fflush(stdout);
            break;
        } else {
            // Process received message
            printf("Message received from client %d: %s\n", client_socket, buffer);
            fflush(stdout);
            // Send confirmation message to client
            send(client_socket, "Message received", 16, 0);
            memset(buffer, 0, sizeof(buffer));
        }
    }
    // Close client socket
    close(client_socket);
}

int main() {
    // Create server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        printf("Error creating server socket\n");
        fflush(stdout);
        exit(1);
    }
    printf("Server socket created successfully\n");
    fflush(stdout);

    // Prepare server address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(5000);
    server_address.sin_addr.s_addr = INADDR_ANY;

    // Bind server socket to server address
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        printf("Error binding server socket to server address\n");
        fflush(stdout);
        exit(1);
    }
    printf("Server socket binded to server address successfully\n");
    fflush(stdout);

    // Listen for incoming connections
    if (listen(server_socket, 10) < 0) {
        printf("Error listening for incoming connections\n");
        fflush(stdout);
        exit(1);
    }
    printf("Server listening for incoming connections\n");
    fflush(stdout);

    // Accept incoming connections and handle clients in threads
    int client_counter = 0;
    while(1) {
        // Accept incoming connection
        struct sockaddr_in client_address;
        int client_address_size = sizeof(client_address);
        client_socket[client_counter] = accept(server_socket, (struct sockaddr *)&client_address, (socklen_t *)&client_address_size);
        if (client_socket[client_counter] < 0) {
            printf("Error accepting incoming connection\n");
            fflush(stdout);
            continue;
        }

        // Start client handler thread
        if (pthread_create(&threads[client_counter], NULL, client_handler, (void *)&client_socket[client_counter]) != 0) {
            printf("Error creating thread for client: %d\n", client_socket[client_counter]);
            fflush(stdout);
            continue;
        }
        printf("Thread created for client: %d\n", client_socket[client_counter]);
        fflush(stdout);

        client_counter++;
    }

    // Close server socket
    close(server_socket);

    return 0;
}