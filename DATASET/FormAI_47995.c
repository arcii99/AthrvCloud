//FormAI DATASET v1.0 Category: Chat server ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

#define BUFFER_SIZE 1024
#define PORT 8080

void clear_buffer(char *buffer) {
    memset(buffer, 0, BUFFER_SIZE);
}

int main() {
    
    // Create a socket
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    // Define the server address
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket to the specified IP and port
    if (bind(server_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Failed to bind socket");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 5) < 0) {
        perror("Failed to listen for connections");
        exit(EXIT_FAILURE);
    }

    // Wait for incoming connections
    printf("Server waiting for incoming connections...\n");
    struct sockaddr_in client_address;
    int client_fd;
    char buffer[BUFFER_SIZE];
    while (1) {
        socklen_t len = sizeof(client_address);
        client_fd = accept(server_fd, (struct sockaddr *)&client_address, &len);
        if (client_fd < 0) {
            perror("Failed to accept connection");
            continue;
        }
        printf("Client connected from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        // Start chatting with the client
        while (1) {
            clear_buffer(buffer);
            ssize_t bytes = recv(client_fd, buffer, BUFFER_SIZE, 0);
            if (bytes == 0) {
                printf("Client disconnected\n");
                break;
            } else if (bytes < 0) {
                perror("Failed to receive message from client");
                break;
            }
            printf("Message received from client: %s\n", buffer);
            
            // Process the client's message
            if (strcmp(buffer, "quit\n") == 0) {
                printf("Client disconnected\n");
                break;
            } else {
                strcat(buffer, " (server)");
                bytes = send(client_fd, buffer, strlen(buffer), 0);
                printf("Message sent to client\n");
                if (bytes < 0) {
                    perror("Failed to send message to client");
                    break;
                }
            }
        }

        // Close the connection with the client
        close(client_fd);
    }

    // Close the socket
    close(server_fd);

    return 0;
}