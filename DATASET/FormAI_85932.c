//FormAI DATASET v1.0 Category: Simple Web Server ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <ctype.h>

#define BUFFER_SIZE 1024
#define PORT 8080

void error_handling(char *message);

int main(int argc, char *argv[]) {
    int serv_socket, client_socket;
    struct sockaddr_in serv_addr, client_addr;
    socklen_t addr_size;
    char buffer[BUFFER_SIZE] = {0};
    char response[BUFFER_SIZE] = {0};
    int read_size;

    // Create socket
    if ((serv_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        error_handling("Failed to create socket.");
    }

    // Prepare the sockaddr_in structure
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    // Bind socket to IP Address and port number
    if (bind(serv_socket, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) == -1) {
        error_handling("Failed to bind.");
    }

    // Listen on the socket for incoming connections
    if (listen(serv_socket, 5) == -1) {
        error_handling("Failed to listen.");
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        // Accept incoming connection from client
        addr_size = sizeof(struct sockaddr_in);
        client_socket = accept(serv_socket, (struct sockaddr*) &client_addr, &addr_size);
        if (client_socket == -1) {
            error_handling("Failed to accept connection.");
        }

        printf("Accepted a new client connection.\n");

        // Read request from client
        memset(buffer, 0, BUFFER_SIZE);
        read_size = read(client_socket, buffer, BUFFER_SIZE);
        if (read_size < 0) {
            error_handling("Failed to read from client.");
        }

        // Parse request and generate response
        char *token = strtok(buffer, " ");
        if (strcmp(token, "GET") == 0) {
            token = strtok(NULL, " ");
            if (strcmp(token, "/") == 0) {
                sprintf(response, "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<html><body><h1>Hello, World!</h1></body></html>");
            } else if (strcmp(token, "/about") == 0) {
                sprintf(response, "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<html><body><h1>About Us</h1><p>We are a simple web server!</p></body></html>");
            } else {
                sprintf(response, "HTTP/1.1 404 Not Found\nContent-Type: text/html\n\n<html><body><h1>Page Not Found</h1></body></html>");
            }
        } else {
            sprintf(response, "HTTP/1.1 501 Not Implemented\nContent-Type: text/html\n\n<html><body><h1>Not Implemented</h1></body></html>");
        }

        // Send response to client
        write(client_socket, response, strlen(response));

        // Close client socket
        close(client_socket);
    }

    // Close server socket
    close(serv_socket);

    return 0;
}

void error_handling(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(EXIT_FAILURE);
}