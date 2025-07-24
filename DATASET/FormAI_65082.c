//FormAI DATASET v1.0 Category: Socket programming ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int server_socket_fd, new_socket_fd;
    struct sockaddr_in server_address, client_address;
    socklen_t addr_len = sizeof(client_address);
    char buffer[BUFFER_SIZE] = {0};
    char *hello = "Hello from server";

    // Create a socket
    if ((server_socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket Creation Failed");
        exit(EXIT_FAILURE);
    }

    // Initialiaze the server address structure
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind the socket to the port
    if (bind(server_socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Bind Failed");
        exit(EXIT_FAILURE);
    }

    // Listen on the socket for incoming connections
    if (listen(server_socket_fd, 3) < 0) {
        perror("Listen");
        exit(EXIT_FAILURE);
    }

    // Accept the incoming connection
    if ((new_socket_fd = accept(server_socket_fd, (struct sockaddr *)&client_address, &addr_len)) < 0) {
        perror("Accept");
        exit(EXIT_FAILURE);
    }

    // Read data from the client
    int valread = read(new_socket_fd, buffer, BUFFER_SIZE);
    printf("Client Sent: %s\n", buffer);

    // Reply to the client
    send(new_socket_fd, hello, strlen(hello), 0);
    printf("Hello message sent\n");

    // Close both sockets
    close(new_socket_fd);
    close(server_socket_fd);
    return 0;
}