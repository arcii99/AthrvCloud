//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PROXY_PORT 8888
#define SERVER_PORT 80
#define BUF_SIZE 4096

int main() {
    int proxy_sock, client_sock, server_sock;
    struct sockaddr_in proxy_addr, client_addr, server_addr;
    char buffer[BUF_SIZE];
    int bytes_read, bytes_written;

    // Create proxy socket
    if ((proxy_sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Error creating proxy socket");
        exit(1);
    }

    // Set address structure for proxy
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_port = htons(PROXY_PORT);
    proxy_addr.sin_addr.s_addr = INADDR_ANY;
    memset(&(proxy_addr.sin_zero), '\0', 8);

    // Bind proxy socket to address
    if (bind(proxy_sock, (struct sockaddr *)&proxy_addr, sizeof(struct sockaddr)) == -1) {
        perror("Error binding proxy socket");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(proxy_sock, 10) == -1) {
        perror("Error listening on proxy socket");
        exit(1);
    }

    printf("Proxy server listening on port %d\n", PROXY_PORT);

    while (1) {
        // Accept incoming connection from client
        unsigned int client_len = sizeof(client_addr);
        if ((client_sock = accept(proxy_sock, (struct sockaddr *)&client_addr, &client_len)) == -1) {
            perror("Error accepting client connection");
            continue;
        }

        // Read client's request
        memset(buffer, 0, BUF_SIZE);
        if ((bytes_read = recv(client_sock, buffer, BUF_SIZE, 0)) == -1) {
            perror("Error reading client request");
            close(client_sock);
            continue;
        }

        printf("Received request from client:\n%s\n", buffer);

        // Create socket for server
        if ((server_sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
            perror("Error creating server socket");
            close(client_sock);
            continue;
        }

        // Set address structure for server
        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(SERVER_PORT);
        inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

        // Connect to server
        if (connect(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
            perror("Error connecting to server");
            close(client_sock);
            close(server_sock);
            continue;
        }

        printf("Connected to server\n");

        // Send client's request to server
        if ((bytes_written = send(server_sock, buffer, bytes_read, 0)) == -1) {
            perror("Error sending request to server");
            close(client_sock);
            close(server_sock);
            continue;
        }

        printf("Sent request to server (%d bytes):\n%s\n", bytes_written, buffer);

        // Read response from server
        memset(buffer, 0, BUF_SIZE);
        while ((bytes_read = recv(server_sock, buffer, BUF_SIZE, 0)) > 0) {
            // Send response to client
            if ((bytes_written = send(client_sock, buffer, bytes_read, 0)) == -1) {
                perror("Error sending response to client");
                close(client_sock);
                close(server_sock);
                break;
            }

            printf("Received %d bytes from server and sent %d bytes to client:\n%s\n", bytes_read, bytes_written, buffer);
            memset(buffer, 0, BUF_SIZE);
        }

        close(client_sock);
        close(server_sock);
        printf("Closed client and server sockets\n");
    }

    return 0;
}