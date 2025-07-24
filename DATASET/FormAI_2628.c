//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 6969
#define BUFFER_SIZE 1024

void *forward_connection(void *arg) {
    int client_socket = *(int*)arg;
    int server_socket;
    struct sockaddr_in server_address;
    char buffer[BUFFER_SIZE];
    int received_bytes;

    // Create a socket for connecting to the server
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Error creating server socket");
        exit(1);
    }

    // Configure the server address
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(SERVER_IP);
    server_address.sin_port = htons(SERVER_PORT);

    // Connect to the server
    if (connect(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Error connecting to the server");
        exit(1);
    }

    // Forward data between client and server
    while ((received_bytes = recv(client_socket, buffer, BUFFER_SIZE, 0)) > 0) {
        send(server_socket, buffer, received_bytes, 0);
        received_bytes = recv(server_socket, buffer, BUFFER_SIZE, 0);
        send(client_socket, buffer, received_bytes, 0);
        memset(buffer, 0, BUFFER_SIZE);
    }

    // Close the sockets
    close(server_socket);
    close(client_socket);

    return NULL;
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_length;
    pthread_t thread_id;

    // Create a socket for listening
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Error creating server socket");
        exit(1);
    }

    // Configure the server address
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(SERVER_PORT);

    // Bind the socket to the server address
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Error binding server socket");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_socket, SOMAXCONN) < 0) {
        perror("Error listening for connections");
        exit(1);
    }

    printf("Server started on port %d\n", SERVER_PORT);

    // Accept incoming connections and start a thread for each connection
    while (1) {
        client_address_length = sizeof(client_address);
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_length);
        if (client_socket < 0) {
            perror("Error accepting connection");
            continue;
        }

        printf("Accepted connection from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        if (pthread_create(&thread_id, NULL, forward_connection, &client_socket) < 0) {
            perror("Error creating thread");
            close(client_socket);
            continue;
        }

        pthread_detach(thread_id);
    }

    // Close the server socket
    close(server_socket);

    return 0;
}