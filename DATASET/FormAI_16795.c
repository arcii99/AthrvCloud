//FormAI DATASET v1.0 Category: Client Server Application ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080

int main() {
    int sock_fd;
    struct sockaddr_in server_addr = {0};

    // Creating socket file descriptor
    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket to the specified IP and port
    if (bind(sock_fd, (struct sockaddr*)&server_addr, sizeof(server_addr))<0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sock_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", PORT);

    int client_sock_fd;
    struct sockaddr_in client_addr = {0};
    int addrlen = sizeof(client_addr);
    char buffer[1024] = {0};

    while (1) {
        // Accept incoming connection
        if ((client_sock_fd = accept(sock_fd, (struct sockaddr*)&client_addr, (socklen_t*)&addrlen))<0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        printf("Client connected from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Receive incoming message from client
        bzero(buffer, 1024);
        read(client_sock_fd, buffer, 1024);
        printf("Received message: %s\n", buffer);

        // Echo back the received message to the client
        write(client_sock_fd, buffer, strlen(buffer));

        // Close client socket
        close(client_sock_fd);
    }

    // Close server socket
    close(sock_fd);

    return 0;
}