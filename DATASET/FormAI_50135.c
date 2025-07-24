//FormAI DATASET v1.0 Category: Firewall ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT_NUMBER 8888
#define BUFFER_SIZE 1024

int main()
{
    // Create socket
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket address
    struct sockaddr_in address;
    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT_NUMBER);

    // Bind socket to address
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) == -1) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(server_fd, 10) == -1) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Firewall listening on port %d...\n", PORT_NUMBER);

    // Accept incoming connections
    while (1) {
        struct sockaddr_in client_addr;
        int client_fd = accept(server_fd, (struct sockaddr *)&client_addr, (socklen_t*)&client_addr);
        if (client_fd == -1) {
            perror("Accept failed");
            continue;
        }

        char buffer[BUFFER_SIZE] = {0};
        int bytes_read = read(client_fd, buffer, BUFFER_SIZE);
        if (bytes_read == -1) {
            perror("Read failed");
            close(client_fd);
            continue;
        }

        // Check if client is allowed to connect
        if (strncmp(buffer, "allow", 5) == 0) {
            printf("Accepted connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
            char* message = "Connection accepted!";
            if (send(client_fd, message, strlen(message), 0) == -1) {
                perror("Send failed");
                close(client_fd);
                continue;
            }
        } else {
            printf("Rejected connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
            char* message = "Connection rejected. You are not authorized to connect.";
            if (send(client_fd, message, strlen(message), 0) == -1) {
                perror("Send failed");
                close(client_fd);
                continue;
            }
            close(client_fd);
        }
    }
}