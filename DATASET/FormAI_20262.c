//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    // Create socket
    int socket_fd;
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    // Bind socket to port 8080
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    memset(&address, '0', addrlen);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    if (bind(socket_fd, (struct sockaddr *)&address, addrlen) < 0) {
        perror("Failed to bind to port 8080");
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(socket_fd, 10) < 0) {
        perror("Failed to listen");
        exit(EXIT_FAILURE);
    }

    while (1) {
        int new_socket;
        if ((new_socket = accept(socket_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Failed to accept incoming connection");
            exit(EXIT_FAILURE);
        }

        // Read incoming message
        char buffer[BUFFER_SIZE] = {0};
        int bytes_read = read(new_socket, buffer, BUFFER_SIZE);
        if (bytes_read < 0) {
            perror("Failed to read incoming message");
            exit(EXIT_FAILURE);
        }

        // Ping the client to check QoS
        if (strcmp(buffer, "ping") == 0) {
            int bytes_sent = send(new_socket, "pong", 4, 0);
            if (bytes_sent < 0) {
                perror("Failed to send ping response");
                exit(EXIT_FAILURE);
            }
        }
    }

    return 0;
}