//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>

#define BUFFER_SIZE 4096

int main(int argc, char* argv[]) {
    int proxy_socket, client_socket, server_socket;
    struct sockaddr_in proxy_address, client_address, server_address;
    char buffer[BUFFER_SIZE];
    int recv_bytes;

    // Setup proxy address
    memset(&proxy_address, 0, sizeof(proxy_address));
    proxy_address.sin_family = AF_INET;
    proxy_address.sin_addr.s_addr = INADDR_ANY;
    proxy_address.sin_port = htons(8080);

    // Create proxy socket
    proxy_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy_socket < 0) {
        perror("Failed to create proxy socket");
        exit(EXIT_FAILURE);
    }

    // Bind proxy socket to proxy address
    if (bind(proxy_socket, (struct sockaddr*)&proxy_address, sizeof(proxy_address)) < 0) {
        perror("Failed to bind proxy socket");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(proxy_socket, 5) < 0) {
        perror("Failed to listen for incoming connections");
        exit(EXIT_FAILURE);
    }

    printf("Simple HTTP Proxy started on port 8080\n");

    while (1) {
        socklen_t client_address_len = sizeof(client_address);
        
        // Accept incoming client connection
        client_socket = accept(proxy_socket, (struct sockaddr*)&client_address, &client_address_len);
        if (client_socket < 0) {
            perror("Failed to accept incoming client connection");
            continue;
        }

        printf("Accepted incoming client connection from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        // Create socket to connect to server
        server_socket = socket(AF_INET, SOCK_STREAM, 0);
        if (server_socket < 0) {
            perror("Failed to create socket to connect to server");
            close(client_socket);
            continue;
        }

        // Setup server address
        memset(&server_address, 0, sizeof(server_address));
        server_address.sin_family = AF_INET;
        server_address.sin_addr.s_addr = inet_addr(argv[1]); // Use command line argument as server IP address
        server_address.sin_port = htons(80);

        // Connect to server
        if (connect(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
            perror("Failed to connect to server");
            close(client_socket);
            close(server_socket);
            continue;
        }

        printf("Connected to server at %s:%d\n", inet_ntoa(server_address.sin_addr), ntohs(server_address.sin_port));

        // Forward client request to server
        memset(buffer, 0, BUFFER_SIZE);
        recv_bytes = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (recv_bytes < 0) {
            perror("Failed to receive client request");
            close(client_socket);
            close(server_socket);
            continue;
        }

        if (send(server_socket, buffer, recv_bytes, 0) < 0) {
            perror("Failed to forward client request to server");
            close(client_socket);
            close(server_socket);
            continue;
        }

        printf("Forwarded client request to server\n");

        // Forward server response to client
        memset(buffer, 0, BUFFER_SIZE);
        recv_bytes = recv(server_socket, buffer, BUFFER_SIZE, 0);
        if (recv_bytes < 0) {
            perror("Failed to receive server response");
            close(client_socket);
            close(server_socket);
            continue;
        }

        if (send(client_socket, buffer, recv_bytes, 0) < 0) {
            perror("Failed to forward server response to client");
            close(client_socket);
            close(server_socket);
            continue;
        }

        printf("Forwarded server response to client\n");

        close(client_socket);
        close(server_socket);
    }

    return 0;
}