//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main() {

    // Create a socket
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (sock_fd == -1) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to a port
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);

    if (bind(sock_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen on the socket
    if (listen(sock_fd, SOMAXCONN) == -1) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port 8080\n");

    // Accept incoming connections
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);

    int client_fd = accept(sock_fd, (struct sockaddr*)&client_addr, &client_len);

    if (client_fd == -1) {
        perror("Failed to accept incoming connection");
        exit(EXIT_FAILURE);
    }

    // Handle incoming data
    char buffer[1024];
    int bytes_read;

    while ((bytes_read = read(client_fd, buffer, 1024)) != -1) {
        buffer[bytes_read] = '\0';
        printf("Received: %s", buffer);

        if (strcmp(buffer, "quit\n") == 0) {
            break;
        }
    }

    // Close sockets
    close(client_fd);
    close(sock_fd);

    return 0;
}