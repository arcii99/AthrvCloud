//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: minimalist
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8080

int main() {
    int socket_fd, new_socket, status;
    struct sockaddr_in6 server_address, client_address;
    char buffer[1024] = {0};

    // create a TCP socket
    socket_fd = socket(AF_INET6, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    // initialize server address
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin6_family = AF_INET6;
    server_address.sin6_port = htons(PORT); 
    server_address.sin6_addr = in6addr_any;

    // bind socket to the specified address
    status = bind(socket_fd, (const struct sockaddr *)&server_address, sizeof(server_address));
    if (status == -1) {
        perror("Failed to bind socket");
        exit(EXIT_FAILURE);
    }

    // listen for incoming connections
    status = listen(socket_fd, 3);
    if (status == -1) {
        perror("Failed to listen");
        exit(EXIT_FAILURE);
    }

    while (true) {
        // accept connection from client
        socklen_t client_address_len = sizeof(client_address);
        new_socket = accept(socket_fd, (struct sockaddr *)&client_address, &client_address_len);
        if (new_socket == -1) {
            perror("Failed to accept connection");
            exit(EXIT_FAILURE);
        }

        // read message from client
        memset(buffer, 0, sizeof(buffer));
        status = read(new_socket, buffer, sizeof(buffer));
        if (status == -1) {
            perror("Failed to read data from socket");
            exit(EXIT_FAILURE);
        }

        printf("Received message from client: %s\n", buffer);

        // send message to client
        char *response = "Hello from server!";
        status = send(new_socket, response, strlen(response), 0);
        if (status == -1) {
            perror("Failed to send message to client");
            exit(EXIT_FAILURE);
        }

        printf("Sent message to client: %s\n", response);

        // close the connection
        close(new_socket);
    }

    // close the socket
    close(socket_fd);

    return 0;
}