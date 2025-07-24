//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void handle_error(char* msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char* argv[]) {

    // Create socket file descriptor
    int server_fd, client_fd;
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        handle_error("Socket creation failed");
    }

    // Set socket options
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) == -1) {
        handle_error("Setsockopt failed");
    }

    // Bind socket to address and port
    struct sockaddr_in addr;
    memset(&addr, '0', sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr*) &addr, sizeof(addr)) == -1) {
        handle_error("Bind failed");
    }

    // Start listening for incoming connections
    if (listen(server_fd, 5) == -1) {
        handle_error("Listen failed");
    }

    // Handle incoming connections
    while (1) {

        // Accept incoming connection
        socklen_t client_len = sizeof(addr);
        if ((client_fd = accept(server_fd, (struct sockaddr*) &addr, &client_len)) == -1) {
            handle_error("Accept failed");
        }

        // Read request from client
        char buffer[BUFFER_SIZE];
        bzero(buffer, BUFFER_SIZE);
        if (read(client_fd, buffer, BUFFER_SIZE) == -1) {
            handle_error("Read failed");
        }

        // Print HTTP request
        printf("Received request:\n%s\n", buffer);
        
        // Forward request to server
        int server_fd2 = socket(AF_INET, SOCK_STREAM, 0);
        if (server_fd2 == -1) {
            handle_error("Socket creation failed");
        }
        char* server_ip = "127.0.0.1";
        struct sockaddr_in server_addr;
        memset(&server_addr, '0', sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(80);
        if (inet_pton(AF_INET, server_ip, &server_addr.sin_addr) <= 0) {
            handle_error("Invalid address/ Address not supported");
        }
        if (connect(server_fd2, (struct sockaddr*) &server_addr, sizeof(server_addr)) == -1) {
            handle_error("Connection failed");
        }
        if (write(server_fd2, buffer, strlen(buffer)) == -1) {
            handle_error("Write failed");
        }

        // Read response from server
        bzero(buffer, BUFFER_SIZE);
        if (read(server_fd2, buffer, BUFFER_SIZE) == -1) {
            handle_error("Read failed");
        }

        // Print HTTP response
        printf("Received response:\n%s\n", buffer);

        // Forward response to client
        if (write(client_fd, buffer, strlen(buffer)) == -1) {
            handle_error("Write failed");
        }

        // Close server to client socket connection
        close(client_fd);
        // Close server to server socket connection
        close(server_fd2);
    }

    // Close server socket
    close(server_fd);

    return 0;
}