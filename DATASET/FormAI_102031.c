//FormAI DATASET v1.0 Category: Simple Web Server ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define PORT 8080

int main()
{
    int server_fd, client_fd;
    struct sockaddr_in server_address, client_address;
    char buffer[BUFFER_SIZE] = {0};
    char *response = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello World!";

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Set server address attributes
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind the socket to the address and port
    if (bind(server_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening for connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        // Accept incoming connections
        int address_length = sizeof(client_address);
        if ((client_fd = accept(server_fd, (struct sockaddr *)&client_address, (socklen_t*)&address_length)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        printf("Client connected: %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        // Receive data from client
        read(client_fd, buffer, BUFFER_SIZE);
        printf("Received request from client:\n%s", buffer);

        // Send back the response
        write(client_fd, response, strlen(response));
        printf("Sent response to client:\n%s\n", response);

        // Close the connection
        close(client_fd);
        printf("Client disconnected.\n");
    }

    return 0;
}