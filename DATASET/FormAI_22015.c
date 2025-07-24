//FormAI DATASET v1.0 Category: Simple Web Server ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE];
    char *response = "HTTP/1.1 200 OK\nContent-Type: text/html\nConnection: close\n\n<!DOCTYPE html><html><head><title>Simple Web Server</title></head><body><h1>Welcome to my Simple Web Server!</h1><p>This is a basic web server implemented in C using sockets and HTTP protocol.</p></body></html>\n";

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Assign IP and port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind socket to IP and port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Simple Web Server is listening on port %d...\n", PORT);

    // Serve incoming connections
    while (1) {
        // Accept the incoming connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        // Read the request from the client
        valread = read(new_socket , buffer, BUFFER_SIZE);
        printf("%s\n", buffer);

        // Send the response to the client
        write(new_socket , response , strlen(response));
        printf("Response sent.\n");

        // Close the connection
        close(new_socket);
    }

    return 0;
}