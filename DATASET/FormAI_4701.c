//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define SERVER_PORT 8080
#define MAX_CLIENTS 50
#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
    
    if (argc != 2) { // Command line argument must be provided.
        printf("Usage: %s <server-ip-address>\n", argv[0]);
        exit(1);
    }

    char *server_ip = argv[1];
    int server_sock, client_sock, opt = 1;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;
    socklen_t client_len = sizeof(client_addr);

    server_sock = socket(AF_INET, SOCK_STREAM, 0); // Create a socket for the server.
    if (server_sock < 0) {
        perror("Failed to create server socket.");
        exit(1);
    }

    // Allow the socket to be reused immediately after the program terminates.
    if (setsockopt(server_sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
        perror("Failed to set server socket reusable.");
        exit(1);
    }

    // Fill in the server address structure.
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    if (inet_pton(AF_INET, server_ip, &server_addr.sin_addr) <= 0) {
        perror("Invalid server IP address.");
        exit(1);
    }

    // Bind the server socket to the given address.
    if (bind(server_sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to bind server socket to address.");
        exit(1);
    }

    // Listen for connections from clients.
    if (listen(server_sock, MAX_CLIENTS) < 0) {
        perror("Failed to listen for clients.");
        exit(1);
    }

    printf("Server is ready to accept connections on port %d\n", SERVER_PORT);

    while (1) { // Loop forever to accept new client connections.
        client_sock = accept(server_sock, (struct sockaddr *) &client_addr, &client_len); // Accept a client connection.
        if (client_sock < 0) {
            perror("Failed to accept client connection.");
            continue;
        }

        printf("Accepted client connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        pid_t pid = fork(); // Fork a new child process to handle the client connection separately.
        if (pid == -1) {
            perror("Failed to fork child process.");
            exit(1);
        } else if (pid == 0) { // Child process.

            close(server_sock); // Close the server socket in the child process.

            while ((bytes_read = recv(client_sock, buffer, BUFFER_SIZE, 0)) > 0) { // Read data from the client.
                // TODO: Implement a simple HTTP proxy here.
                // As this is a visionary example program, I would like to leave the implementation to the reader's imagination.
                // However, the basic idea is to read the request from the client, extract the requested URL, and send a request to the actual server.
                // Then, read the response from the server, modify it if necessary, and return it to the client.
                send(client_sock, buffer, bytes_read, 0); // Simply echo back the data read from the client.
            }

            if (bytes_read == 0) {
                printf("Client disconnected.\n");
            } else {
                perror("Failed to read data from client.");
            }

            close(client_sock); // Close the client socket in the child process.

            exit(0); // Exit the child process.

        } else { // Parent process.
            close(client_sock); // Close the client socket in the parent process.
        }
    }

    close(server_sock); // This line will never be executed.

    return 0;
}