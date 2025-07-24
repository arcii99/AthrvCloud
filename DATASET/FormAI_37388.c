//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define MAX_BUFFER_SIZE 65535 // Maximum size of data buffer
#define SERVER_PORT 8080 // Port number of server
#define BACKLOG 10 // Maximum pending connections

void handle_client(int client_socket)
{
    char buffer[MAX_BUFFER_SIZE];
    int bytes_recv;
    struct sockaddr_in server_addr;
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("server_socket");
        exit(1);
    }

    // Connect to server
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80); // Port number of HTTP server
    server_addr.sin_addr.s_addr = inet_addr("216.58.194.174"); // IP address of HTTP server
    if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(1);
    }

    // Forward request to server
    memset(buffer, 0, sizeof(buffer));
    bytes_recv = recv(client_socket, buffer, MAX_BUFFER_SIZE, 0);
    if (bytes_recv == -1) {
        perror("recv");
        exit(1);
    }
    if (send(server_socket, buffer, bytes_recv, 0) == -1) {
        perror("send");
        exit(1);
    }

    // Forward response to client
    memset(buffer, 0, sizeof(buffer));
    while ((bytes_recv = recv(server_socket, buffer, MAX_BUFFER_SIZE, 0)) > 0) {
        if (send(client_socket, buffer, bytes_recv, 0) == -1) {
            perror("send");
            exit(1);
        }
        memset(buffer, 0, sizeof(buffer));
    }
    if (bytes_recv == -1) {
        perror("recv");
        exit(1);
    }

    close(server_socket);
    close(client_socket);
}

int main(int argc, char *argv[])
{
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addrlen;

    // Create server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("server_socket");
        exit(1);
    }

    // Bind socket to IP address and port
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(1);
    }

    // Listen for connections
    if (listen(server_socket, BACKLOG) == -1) {
        perror("listen");
        exit(1);
    }

    // Accept incoming connections
    while (1) {
        client_addrlen = sizeof(client_addr);
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addrlen);
        if (client_socket == -1) {
            perror("accept");
            exit(1);
        }
        handle_client(client_socket);
    }

    close(server_socket);
    return 0;
}