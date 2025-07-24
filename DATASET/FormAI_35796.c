//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 6000
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    char buffer[BUFFER_SIZE];
    int opt = 1;
    socklen_t client_address_length = sizeof(client_address);

    // Creating server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error: Failed to create server socket.\n");
        exit(EXIT_FAILURE);
    }

    // Setting socket options for reuse of address and port
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Error: setsockopt");
        exit(EXIT_FAILURE);
    }

    // Setting server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Binding server socket to server address
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        printf("Error: Failed to bind server socket to server address.\n");
        exit(EXIT_FAILURE);
    }

    // Listening for client connections
    if (listen(server_socket, 3) < 0) {
        printf("Error: Failed to listen for client connections.\n");
        exit(EXIT_FAILURE);
    }

    printf("Server is running on %s:%d.\n", inet_ntoa(server_address.sin_addr), ntohs(server_address.sin_port));
    printf("Waiting for client connections.\n");

    while (1) {
        // Accepting client connection
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_length);
        if (client_socket < 0) {
            printf("Error: Failed to accept client connection.\n");
            exit(EXIT_FAILURE);
        }

        printf("Client connected from %s:%d.\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        // Receiving data from client
        memset(buffer, 0, BUFFER_SIZE);
        int data_size = read(client_socket, buffer, BUFFER_SIZE);
        if (data_size < 0) {
            printf("Error: Failed to receive data from client.\n");
            exit(EXIT_FAILURE);
        }

        printf("Data received from client: %s\n", buffer);

        // Sending response to client
        char response[BUFFER_SIZE] = "Hello from server!";
        int response_size = send(client_socket, response, strlen(response), 0);
        if (response_size < 0) {
            printf("Error: Failed to send response to client.\n");
            exit(EXIT_FAILURE);
        }

        printf("Response sent to client: %s\n", response);

        // Closing client socket
        close(client_socket);
        printf("Client disconnected.\n");
    }

    // Closing server socket
    close(server_socket);

    return 0;
}