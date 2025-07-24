//FormAI DATASET v1.0 Category: Simple Web Server ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char const *argv[]) {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    // Socket creation
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        return EXIT_FAILURE;
    }

    // Address initialization
    memset(&address, '0', sizeof(address));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to given IP and port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        return EXIT_FAILURE;
    }

    // Wait for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        return EXIT_FAILURE;
    }

    while (1) {
        printf("\nAwaits client to connect...\n");

        // Accept the connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept failed");
            return EXIT_FAILURE;
        }

        printf("Client connected successfully.\n");

        char buffer[BUFFER_SIZE] = {0};
        char *message = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello World!";

        // Send message to the client
        send(new_socket, message, strlen(message), 0);
        printf("Hello message sent\n");

        // Close the connection
        close(new_socket);
    }

    return EXIT_SUCCESS;
}