//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 256
#define PORT 5000

int main() {
    int server_fd, new_socket;
    struct sockaddr_in server_addr, client_addr;
    int addrlen = sizeof(server_addr);
    char buffer[BUFFER_SIZE] = {0};
    char *hello = "Hello from server";

    // Creating socket file descriptor
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        printf("Failed to create socket");
        return -1;
    }

    // Preparing server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Binding socket to the server address
    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) != 0) {
        printf("Failed to bind socket");
        return -1;
    }

    // Start listening for incoming connections
    if (listen(server_fd, 5) != 0) {
        printf("Failed to start listening");
        return -1;
    }

    printf("Server started, listening on port %d\nWaiting for client connection...\n", PORT);

    // Accepting incoming connection
    new_socket = accept(server_fd, (struct sockaddr*)&client_addr, &addrlen);
    if (new_socket < 0) {
        printf("Failed to accept incoming connection");
        return -1;
    }

    // Sending welcome message to client
    send(new_socket, hello, strlen(hello), 0);

    // Receiving message from client
    int valread = read(new_socket, buffer, BUFFER_SIZE);
    printf("Received message: %s\n", buffer);

    // Closing socket
    close(new_socket);
    close(server_fd);

    return 0;
}