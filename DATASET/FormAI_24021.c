//FormAI DATASET v1.0 Category: Socket programming ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 5000
#define MAX_PENDING_CONNECTIONS 10
#define MAX_MSG_LEN 1024

int main() {
    int server_fd, client_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[MAX_MSG_LEN] = {0};
    char *hello = "Hello from server";

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Failed to create socket file descriptor");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Failed to set socket options");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to a specific IP and port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Failed to bind socket");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, MAX_PENDING_CONNECTIONS) < 0) {
        perror("Failed to start listening for incoming connections");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", PORT);

    // Accept incoming connections and send a welcome message to the client
    while (1) {
        if ((client_fd = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Failed to accept incoming connection");
            exit(EXIT_FAILURE);
        }

        printf("New connection established\n");

        if (send(client_fd, hello, strlen(hello), 0) != strlen(hello)) {
            perror("Failed to send welcome message to client");
            exit(EXIT_FAILURE);
        }

        // Receive messages from the client and echo them back
        while(1) {
            memset(buffer, 0, sizeof(buffer));

            if (recv(client_fd, buffer, MAX_MSG_LEN, 0) == 0) {
                printf("Client disconnected\n");
                break;
            }

            printf("Client: %s\n", buffer);

            if (send(client_fd, buffer, strlen(buffer), 0) != strlen(buffer)) {
                perror("Failed to echo message back to client");
                exit(EXIT_FAILURE);
            }
        }

        close(client_fd);
    }

    return 0;
}