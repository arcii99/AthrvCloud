//FormAI DATASET v1.0 Category: Simple Web Server ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define MESSAGE_SIZE 1024

int main(int argc, char const *argv[]) {
    int server_fd, client_fd, opt = 1;
    struct sockaddr_in server_addr, client_addr;
    char message[MESSAGE_SIZE];

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // Set server address properties
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind server socket to the specified address and port
    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Listening on port %d\n", PORT);

    while (1) {
        int client_addr_size = sizeof(client_addr);

        // Accept incoming connection
        if ((client_fd = accept(server_fd, (struct sockaddr*)&client_addr, (socklen_t*)&client_addr_size)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        // Receive incoming message
        if (recv(client_fd, message, MESSAGE_SIZE, 0) < 0) {
            perror("Receive failed");
            exit(EXIT_FAILURE);
        }

        printf("Received message: %s\n", message);

        // Send response message
        char* response = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello world!";
        if (send(client_fd, response, strlen(response), 0) < 0) {
            perror("Send failed");
            exit(EXIT_FAILURE);
        }

        printf("Sent response: %s\n", response);

        // Close client connection
        close(client_fd);
    }

    return 0;
}