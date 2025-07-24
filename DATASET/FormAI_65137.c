//FormAI DATASET v1.0 Category: Socket programming ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8888      // Port number
#define MAX_CLIENTS 10 // Maximum number of clients that can connect to the server

void handle_client(int client_socket);

int main(int argc, char *argv[]) {
    int server_socket, client_socket, opt = 1;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    // Create a socket for the server
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Allow multiple connections to the same port
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // Configure server address and bind the socket to it
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) == -1) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server started on port %d\n", PORT);

    // Accept incoming connections from clients
    while ((client_socket = accept(server_socket, (struct sockaddr *) &client_addr, &client_addr_len)) != -1) {
        printf("Client connected from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Handle client requests in a separate thread
        if (fork() == 0) {
            handle_client(client_socket);
            exit(EXIT_SUCCESS);
        }
    }

    // Error handling
    if (client_socket == -1) {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }

    // Clean up
    close(server_socket);
    return 0;
}

void handle_client(int client_socket) {
    char buffer[1024];
    int bytes;

    do {
        // Read data from the client
        bytes = read(client_socket, buffer, sizeof(buffer));
        if (bytes == -1) {
            perror("read failed");
            break;
        }

        if (bytes == 0) {
            printf("Client disconnected\n");
            break;
        }

        // Print the received message and send it back to the client
        printf("Received message from client: %.*s", bytes, buffer);

        if (write(client_socket, buffer, bytes) == -1) {
            perror("write failed");
            break;
        }
    } while (1);

    // Clean up
    close(client_socket);
}