//FormAI DATASET v1.0 Category: Simple Web Server ; Style: Claude Shannon
// The following C program is an implementation of a simple web server
// inspired by the work of Claude Shannon, the father of information theory.

// Firstly, we include necessary headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_length = sizeof(client_address);
    char request_buffer[BUFFER_SIZE], response_buffer[BUFFER_SIZE];

    // Create a socket for the server
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    // Set the server address information
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8080);

    // Bind the socket to the server address
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("Failed to bind socket");
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming client requests
    if (listen(server_socket, 5) == -1) {
        perror("Failed to start listening");
        exit(EXIT_FAILURE);
    }

    printf("Shannon's Simple Web Server is up and running on port 8080!\n");

    while (1) {
        // Accept incoming client connection
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_length)) == -1) {
            perror("Error accepting incoming client connection");
            exit(EXIT_FAILURE);
        }

        printf("Client connected from %s:%d.\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        // Clean buffers before starting a new request
        memset(request_buffer, 0, BUFFER_SIZE);
        memset(response_buffer, 0, BUFFER_SIZE);

        // Read HTTP request from client
        if (recv(client_socket, request_buffer, sizeof(request_buffer), 0) == -1) {
            perror("Error receiving HTTP request from client");
            exit(EXIT_FAILURE);
        }

        // Prepare HTTP response to send back to client
        sprintf(response_buffer, "HTTP/1.1 200 OK\r\n"
                                  "Content-Type: text/html\r\n"
                                  "\r\n"
                                  "<html><body><h1>Welcome to Shannon's Simple Web Server!</h1></body></html>");

        // Send the HTTP response to client
        if (send(client_socket, response_buffer, strlen(response_buffer), 0) == -1) {
            perror("Error sending HTTP response to client");
            exit(EXIT_FAILURE);
        }

        printf("HTTP response sent to client.\n");

        // Close the client socket
        close(client_socket);
    }

    // Close the server socket
    close(server_socket);

    return 0;
}