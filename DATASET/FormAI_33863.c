//FormAI DATASET v1.0 Category: Simple Web Server ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define DEFAULT_PORT 8080
#define RESPONSE_BUFFER_SIZE 1024

int main(int argc, char const *argv[]) {

    int server_socket_fd, client_socket_fd, opt = 1, addrlen = sizeof(struct sockaddr_in);
    struct sockaddr_in address;
    char response[RESPONSE_BUFFER_SIZE];

    // Create a socket for the server
    if ((server_socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    // Set socket options to reuse address and port
    if (setsockopt(server_socket_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Setsockopt error");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(DEFAULT_PORT);

    // Bind the socket to specified address and port
    if (bind(server_socket_fd, (struct sockaddr *) &address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    while (1) {
        // Accept incoming connection and obtain a new socket fd for communication
        if ((client_socket_fd = accept(server_socket_fd, (struct sockaddr *) &address, (socklen_t *) &addrlen)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }
        
        // Clear response buffer and read request from client
        memset(response, 0, RESPONSE_BUFFER_SIZE);
        read(client_socket_fd, response, RESPONSE_BUFFER_SIZE - 1);
        
        // Generate response
        sprintf(response,
            "HTTP/1.1 200 OK\n"
            "Content-Type: text/html; charset=UTF-8\n\n"
            "<html>\n"
            "<head>\n"
            "<title>C Simple Web Server Example</title>\n"
            "</head>\n"
            "<body>\n"
            "<h1>Welcome to the C Simple Web Server Example!</h1>\n"
            "</body>\n"
            "</html>\n"
        );
        
        // Send response to client and close client socket
        write(client_socket_fd, response, strlen(response));
        close(client_socket_fd);
    }

    // Close server socket
    close(server_socket_fd);
    return 0;
}