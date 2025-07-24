//FormAI DATASET v1.0 Category: Networking ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int socket_fd, valread;
    struct sockaddr_in address;
    char buffer[BUFFER_SIZE] = {0};

    // Creating socket file descriptor
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set up address structure of server
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind socket to address structure
    if (bind(socket_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(socket_fd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    while(1) {
        int client_fd;
        struct sockaddr_in client_address;
        int addrlen = sizeof(client_address);

        // Accept incoming connection
        if ((client_fd = accept(socket_fd, (struct sockaddr *)&client_address, (socklen_t*)&addrlen))<0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        // Read incoming data
        valread = read(client_fd , buffer, BUFFER_SIZE);
        printf("Received message: %s\n", buffer);

        // Send response
        char* response = "Hello from server";
        send(client_fd, response, strlen(response), 0);
        printf("Response sent.\n");

        // Close connection
        close(client_fd);
    }

    close(socket_fd);
    return 0;
}