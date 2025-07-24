//FormAI DATASET v1.0 Category: Chat server ; Style: protected
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main()
{
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    char message[] = "Server: Connection established. Type 'exit' to close connection.\n";
    
    // Create TCP socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // Set socket address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind socket to address and port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Set listening mode
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connections
    while (1) {
        printf("Waiting for incoming connections...\n");
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        // Send connection message to client
        send(new_socket, message, strlen(message), 0);

        // Read incoming messages
        while (1) {
            valread = read(new_socket, buffer, BUFFER_SIZE);

            // If "exit" is received, close connection
            if (strncmp(buffer, "exit", 4) == 0) {
                printf("Client disconnected\n");
                close(new_socket);
                break;
            }

            // Echo received message back to client
            printf("Client: %s\n", buffer);
            send(new_socket, buffer, strlen(buffer), 0);
            memset(buffer, 0, BUFFER_SIZE);
        }
    }

    return 0;
}