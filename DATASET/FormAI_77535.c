//FormAI DATASET v1.0 Category: Chat server ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#define MAX_CONNECTIONS 10
#define BUFFER_SIZE 1024

int main(int argc, char* argv[]) {

    // Create the socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    // Configure the server address and port
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8080);

    // Bind the socket to the address and port
    int bind_result = bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address));
    if (bind_result < 0) {
        perror("Failed to bind socket");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    int listen_result = listen(server_socket, MAX_CONNECTIONS);
    if (listen_result < 0) {
        perror("Failed to listen");
        exit(EXIT_FAILURE);
    }

    // Start accepting connections
    printf("Listening for incoming connections...\n");
    while (1) {
        struct sockaddr_in client_address;
        socklen_t client_address_size = sizeof(client_address);
        int client_socket = accept(server_socket, (struct sockaddr*)&client_address, &client_address_size);
        if (client_socket < 0) {
            perror("Failed to accept connection");
            continue;
        }

        // Client connected
        printf("Client connected\n");

        // Handle the client
        char buffer[BUFFER_SIZE];
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (bytes_received < 0) {
            perror("Failed to receive data");
            close(client_socket);
            continue;
        }

        // Echo the message back to the client
        int bytes_sent = send(client_socket, buffer, bytes_received, 0);
        if (bytes_sent < 0) {
            perror("Failed to send data");
        }

        // Close the connection
        close(client_socket);
        printf("Client disconnected\n");
    }

    // Close the server socket
    close(server_socket);
    return 0;
}