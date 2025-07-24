//FormAI DATASET v1.0 Category: Simple Web Server ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define DEFAULT_PORT 8080
#define MAX_CONNECTIONS 10

void handle_request(int client_socket);

int main(int argc, char *argv[]) {
    int server_socket, client_socket, addr_len, opt = 1;
    struct sockaddr_in server_addr, client_addr;

    // Creating socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket error");
        exit(EXIT_FAILURE);
    }

    // Set options to reuse address
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt error");
        exit(EXIT_FAILURE);
    }

    // Set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(DEFAULT_PORT);

    // Bind socket to address
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind error");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CONNECTIONS) < 0) {
        perror("listen error");
        exit(EXIT_FAILURE);
    }

    printf("Listening on port %d...\n", DEFAULT_PORT);

    while (1) {
        addr_len = sizeof(client_addr);

        // Accept incoming connection
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, (socklen_t *)&addr_len)) < 0) {
            perror("accept error");
            continue;
        }

        printf("Connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Handle client request
        handle_request(client_socket);

        // Close client socket
        close(client_socket);
    }

    // Close server socket
    close(server_socket);

    return 0;
}

void handle_request(int client_socket) {
    char buffer[1024] = { 0 };
    char *response = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<html><h1>Welcome to my web server!</h1></html>";

    // Read client request
    if (read(client_socket, buffer, 1024) < 0) {
        perror("read error");
        return;
    }

    printf("Request:\n%s\n", buffer);

    // Send response
    if (send(client_socket, response, strlen(response), 0) < 0) {
        perror("send error");
        return;
    }

    printf("Response:\n%s\n", response);
}