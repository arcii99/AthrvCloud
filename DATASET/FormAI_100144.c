//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define SERVER_PORT 8888
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int server_socket_fd, client_socket_fd;
    socklen_t client_len;
    char buf[BUF_SIZE];

    // Create a new socket for the server
    if ((server_socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Failed to create server socket");
        exit(EXIT_FAILURE);
    }

    // Set up the server address
    struct sockaddr_in server_addr = {0};
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(SERVER_PORT);

    // Bind the socket to the server address
    if (bind(server_socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to bind server socket");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket_fd, SOMAXCONN) < 0) {
        perror("Failed to listen for incoming connections");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", SERVER_PORT);

    while (1) {
        // Accept a new client connection
        struct sockaddr_in client_addr = {0};
        client_len = sizeof(client_addr);
        client_socket_fd = accept(server_socket_fd, (struct sockaddr *)&client_addr, &client_len);
        if (client_socket_fd < 0) {
            perror("Failed to accept client connection");
            continue;
        }

        // Receive data from the client
        int num_bytes = recv(client_socket_fd, buf, BUF_SIZE, 0);
        if (num_bytes < 0) {
            perror("Failed to receive data from client");
            continue;
        }

        // Print the received data
        printf("Received %d bytes from client:\n", num_bytes);
        printf("%.*s\n", num_bytes, buf);

        // Send a response back to the client
        char *response = "Hello, world!";
        int response_len = strlen(response);
        if (send(client_socket_fd, response, response_len, 0) < 0) {
            perror("Failed to send response to client");
            continue;
        }

        // Close the client socket
        close(client_socket_fd);
    }

    return 0;
}