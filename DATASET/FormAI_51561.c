//FormAI DATASET v1.0 Category: Simple Web Server ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAXBUF 1024

int main(int argc, char *argv[]) {
    int socket_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[MAXBUF];

    // Create a socket
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to a local address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(80); // HTTP port

    int bind_result = bind(socket_fd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    if (bind_result < 0) {
        perror("Error binding socket");
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    listen(socket_fd, 5); // queue up to 5 connections

    while (1) {
        socklen_t client_len = sizeof(client_addr);
        // Wait for a client to connect
        client_fd = accept(socket_fd, (struct sockaddr*)&client_addr, &client_len);
        if (client_fd < 0) {
            perror("Error accepting connection");
            exit(EXIT_FAILURE);
        }

        // Read the HTTP request
        memset(buffer, 0, MAXBUF);
        int bytes_read = read(client_fd, buffer, MAXBUF - 1);
        if (bytes_read < 0) {
            perror("Error reading from socket");
            exit(EXIT_FAILURE);
        }

        // Send a response
        char* response = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<html><body><h1>Hello World!</h1></body></html>";
        write(client_fd, response, strlen(response));

        // Close the client connection
        close(client_fd);
    }

    close(socket_fd);
    return 0;
}