//FormAI DATASET v1.0 Category: Client Server Application ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char const *argv[]) {
    struct sockaddr_in server_addr, client_addr;
    int server_fd, client_fd, read_value;
    char buffer[BUFFER_SIZE] = {0};

    // Create a socket for the server
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Initialize server address struct
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);

    // Bind the socket to the specified address
    if (bind(server_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    while (true) {
        unsigned int addr_len = sizeof(client_addr);
        // Accept the incoming connection
        if ((client_fd = accept(server_fd, (struct sockaddr *) &client_addr, &addr_len)) < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        // Read incoming data from the client
        read_value = read(client_fd, buffer, BUFFER_SIZE);
        printf("Received message from client: %s\n", buffer);

        // Send response to client
        char response_buffer[BUFFER_SIZE] = "Hello from server";
        int response_length = strlen(response_buffer);
        if (send(client_fd, response_buffer, response_length, 0) != response_length) {
            perror("failed to send response to client");
            exit(EXIT_FAILURE);
        }

        close(client_fd);
    }

    return 0;
}