//FormAI DATASET v1.0 Category: Networking ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

    int server_socket, client_socket, read_size;
    struct sockaddr_in server, client;
    char client_message[BUFFER_SIZE];

    // Create a socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Error creating socket.");
        exit(EXIT_FAILURE);
    }

    // Initialize the server sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8080);

    // Bind the socket to the address and port
    if (bind(server_socket, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Error binding socket to address.");
        exit(EXIT_FAILURE);
    }

    printf("Server running on port %d...\n", ntohs(server.sin_port));

    // Listen for incoming connections
    if (listen(server_socket, 3) < 0) {
        perror("Error listening for connections.");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connections
    int addr_len = sizeof(struct sockaddr_in);
    client_socket = accept(server_socket, (struct sockaddr *)&client, (socklen_t*)&addr_len);
    if (client_socket < 0) {
        perror("Error accepting connection.");
        exit(EXIT_FAILURE);
    }

    printf("Connection accepted from %s:%d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));

    // Receive data from client
    while ((read_size = recv(client_socket, client_message, BUFFER_SIZE, 0)) > 0) {
        printf("Message received from client: %s\n", client_message);

        // Echo back the message to the client
        if (send(client_socket, client_message, strlen(client_message), 0) < 0) {
            perror("Error sending message to client.");
            exit(EXIT_FAILURE);
        }

        // Clear the buffer
        memset(client_message, 0, BUFFER_SIZE);
    }

    if (read_size == 0) {
        printf("Client disconnected.\n");
        fflush(stdout);
    }
    else if (read_size == -1) {
        perror("Error receiving message from client.");
        exit(EXIT_FAILURE);
    }

    close(client_socket);
    close(server_socket);

    return 0;
}