//FormAI DATASET v1.0 Category: Networking ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8888
#define MAX_MSG 1024

int main() {
    int server_fd, client_fd, err;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(struct sockaddr_in);
    char buffer[MAX_MSG];

    // Create server socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("Failed to create server socket");
        exit(EXIT_FAILURE);
    }

    // Set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind server socket to address
    err = bind(server_fd, (struct sockaddr *)&server_addr, addr_len);
    if (err == -1) {
        perror("Failed to bind server socket");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    err = listen(server_fd, SOMAXCONN);
    if (err == -1) {
        perror("Failed to listen for incoming connections");
        exit(EXIT_FAILURE);
    }
    
    printf("Server started, waiting for clients...\n");

    while (1) {
        // Accept incoming client connection
        client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &addr_len);
        if (client_fd == -1) {
            perror("Failed to accept client connection");
            continue;
        }

        // Get client address
        char client_ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &client_addr.sin_addr, client_ip, INET_ADDRSTRLEN);
        printf("Client connected from %s:%d\n", client_ip, ntohs(client_addr.sin_port));

        // Send welcome message to client
        const char* msg = "Welcome to the server!\n";
        write(client_fd, msg, strlen(msg));

        // Receive messages from client
        while (1) {
            int bytes_recv = recv(client_fd, buffer, MAX_MSG, 0);
            if (bytes_recv == -1) {
                perror("Failed to receive message from client");
                break;
            } else if (bytes_recv == 0) {
                printf("Client disconnected\n");
                break;
            } else {
                buffer[bytes_recv] = '\0';
                printf("Received message from client: %s", buffer);
            }
        }

        // Close client connection
        close(client_fd);
    }

    // Close server socket
    close(server_fd);

    return 0;
}