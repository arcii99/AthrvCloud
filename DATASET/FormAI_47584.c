//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

// Proxy server IP and port number
#define PROXY_SERVER_IP "127.0.0.1"
#define PROXY_SERVER_PORT 8080

// HTTP server IP and port number
#define SERVER_IP "192.168.0.10"
#define SERVER_PORT 80

// Size of buffer for read/write operations
#define BUFFER_SIZE 1024

int main() {
    int proxy_sock, client_sock;
    struct sockaddr_in proxy_addr, client_addr, server_addr;
    char buffer[BUFFER_SIZE];
    ssize_t num_bytes;

    // Create the proxy socket
    if ((proxy_sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Set up the proxy address struct
    memset(&proxy_addr, 0, sizeof(proxy_addr));
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_addr.s_addr = inet_addr(PROXY_SERVER_IP);
    proxy_addr.sin_port = htons(PROXY_SERVER_PORT);

    // Bind the proxy socket to the proxy address
    if (bind(proxy_sock, (struct sockaddr *)&proxy_addr, sizeof(proxy_addr)) == -1) {
        perror("Error binding socket");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(proxy_sock, 5) == -1) {
        perror("Error listening on socket");
        exit(EXIT_FAILURE);
    }

    printf("Proxy server listening on port %d...\n", PROXY_SERVER_PORT);

    // Accept incoming client connections
    socklen_t client_addr_size = sizeof(client_addr);
    while ((client_sock = accept(proxy_sock, (struct sockaddr *)&client_addr, &client_addr_size)) != -1) {
        printf("Accepted incoming connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Set up the server address struct
        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
        server_addr.sin_port = htons(SERVER_PORT);

        // Create a new socket for the server connection
        int server_sock;
        if ((server_sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
            perror("Error creating server socket");
            exit(EXIT_FAILURE);
        }

        // Connect to the HTTP server
        if (connect(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
            perror("Error connecting to server");
            exit(EXIT_FAILURE);
        }

        // Read incoming data from the client
        while ((num_bytes = read(client_sock, buffer, BUFFER_SIZE)) > 0) {
            // Write the data to the server
            if (write(server_sock, buffer, num_bytes) == -1) {
                perror("Error writing to server");
                exit(EXIT_FAILURE);
            }

            // Read the server's response
            if ((num_bytes = read(server_sock, buffer, BUFFER_SIZE)) == -1) {
                perror("Error reading from server");
                exit(EXIT_FAILURE);
            }

            // Write the response back to the client
            if (write(client_sock, buffer, num_bytes) == -1) {
                perror("Error writing to client");
                exit(EXIT_FAILURE);
            }
        }

        // Close the client connection
        close(client_sock);
        printf("Closed connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
    }

    // Close the proxy socket and exit
    close(proxy_sock);
    return 0;
}