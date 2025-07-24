//FormAI DATASET v1.0 Category: Chat server ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MESSAGE_SIZE 1024

int main(int argc, char *argv[]) {
    int port = 8888;

    // Create socket
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Bind socket to port
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Error binding socket");
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(server_fd, 3) < 0) {
        perror("Error listening for connections");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d...\n", port);

    while (1) {
        // Accept incoming connections
        int client_fd = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&address);
        if (client_fd < 0) {
            perror("Error accepting incoming connection");
            exit(EXIT_FAILURE);
        }

        printf("New connection: %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

        char buffer[MESSAGE_SIZE] = {0};
        int message_len;
        while ((message_len = read(client_fd, buffer, MESSAGE_SIZE)) > 0) {
            printf("Received message from %s:%d: %s\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port), buffer);

            if (strncmp(buffer, "quit", 4) == 0) {
                break;
            }

            // Echo message back to client
            if (send(client_fd, buffer, message_len, 0) < 0) {
                perror("Error sending message to client");
                exit(EXIT_FAILURE);
            }
        }

        printf("%s:%d disconnected\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));
        close(client_fd);
    }

    return 0;
}