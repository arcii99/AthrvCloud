//FormAI DATASET v1.0 Category: Simple Web Server ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <fcntl.h>

#define SERVER_PORT 8080
#define MAX_PENDING 10
#define MAX_SIZE 1024

const char *html = "<!DOCTYPE html><html><head><title>C Simple Web Server</title></head><body><h1>Hello, World!</h1></body></html>";

int main(int argc, char *argv[]) {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    char buffer[MAX_SIZE];

    // Create a socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to a specific IP address and port
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(SERVER_PORT);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_PENDING) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", SERVER_PORT);

    while (1) {
        socklen_t client_addr_size = sizeof(client_addr);
        // Accept incoming connection
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_size);
        if (client_socket == -1) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        printf("Client connected from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        ssize_t recv_size;
        memset(buffer, 0, MAX_SIZE);
        recv_size = recv(client_socket, buffer, MAX_SIZE, 0);

        // Check for errors and byte limits
        if ((recv_size == -1) || (recv_size == 0)) {
            close(client_socket);
            continue;
        }

        // Respond to GET request
        if (strncmp(buffer, "GET", 3) == 0) {
            write(client_socket, "HTTP/1.1 200 OK\r\n", 17);
            write(client_socket, "Content-Type: text/html\r\n\r\n", 29);
            write(client_socket, html, strlen(html));
        } else {
            write(client_socket, "HTTP/1.1 400 Bad Request\r\n", 26);
        }

        // Close client socket
        close(client_socket);
    }

    // Close server socket
    close(server_socket);

    return 0;
}