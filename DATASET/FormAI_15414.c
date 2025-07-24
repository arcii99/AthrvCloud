//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT_NUMBER 8080

int main(int argc, char **argv) {
    int server_fd, new_socket, ret;
    struct sockaddr_in server_addr, client_addr;
    char buffer[1024];
    ssize_t bytes_received;

    // Create a socket file descriptor
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("Failed to create socket");
        return EXIT_FAILURE;
    }

    // Initialize server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT_NUMBER);

    // Bind the socket to a specific address and port
    ret = bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (ret == -1) {
        perror("Failed to bind socket");
        close(server_fd);
        return EXIT_FAILURE;
    }

    // Listen for incoming connections
    ret = listen(server_fd, 1);
    if (ret == -1) {
        perror("Failed to listen on socket");
        close(server_fd);
        return EXIT_FAILURE;
    }

    printf("Server listening on port %d...\n", PORT_NUMBER);

    // Accept a new client connection
    socklen_t client_addr_len = sizeof(client_addr);
    new_socket = accept(server_fd, (struct sockaddr *)&client_addr, &client_addr_len);
    if (new_socket == -1) {
        perror("Failed to accept new connection");
        close(server_fd);
        return EXIT_FAILURE;
    }

    // Receive data from the client
    bytes_received = recv(new_socket, buffer, sizeof(buffer), 0);
    if (bytes_received == -1) {
        perror("Failed to receive data from client");
        close(new_socket);
        close(server_fd);
        return EXIT_FAILURE;
    }

    printf("Received message from client: %s\n", buffer);

    // Send data back to the client
    if (send(new_socket, "Hello from server!", strlen("Hello from server!"), 0) == -1) {
        perror("Failed to send data to client");
        close(new_socket);
        close(server_fd);
        return EXIT_FAILURE;
    }

    printf("Sent data to client\n");

    // Close sockets and exit
    close(new_socket);
    close(server_fd);

    return EXIT_SUCCESS;
}