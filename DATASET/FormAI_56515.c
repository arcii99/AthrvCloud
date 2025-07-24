//FormAI DATASET v1.0 Category: Simple Web Server ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void handle_request(int socket_fd) {
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);

    // Read the request from the client
    if (read(socket_fd, buffer, BUFFER_SIZE - 1) < 0) {
        perror("Error reading request from client\n");
        exit(1);
    }

    // Print the request
    printf("Request: %s \n", buffer);

    // Write a response back to the client
    char *response = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<html><body><h1>Simple Web Server</h1><p>Welcome to my server!</p></body></html>";
    if (write(socket_fd, response, strlen(response)) < 0) {
        perror("Error writing response to client\n");
        exit(1);
    }

    // Close the connection
    close(socket_fd);
}

int main(int argc, char const *argv[]) {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    // Create a socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Error creating socket\n");
        exit(1);
    }

    // Set socket options to allow reuse of the address
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Error setting socket options\n");
        exit(1);
    }

    // Bind the socket to a specific IP and port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Error binding socket\n");
        exit(1);
    }

    // Start listening for connections
    if (listen(server_fd, 10) < 0) {
        perror("Error listening for connections\n");
        exit(1);
    }

    // Handle incoming connections
    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
            perror("Error accepting connection\n");
            exit(1);
        }

        // Handle the request
        handle_request(new_socket);
    }

    return 0;
}