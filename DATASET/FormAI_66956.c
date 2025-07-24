//FormAI DATASET v1.0 Category: Simple Web Server ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8000
#define MAX_CONNECTIONS 10
#define MAX_REQUEST_SIZE 2048

void handle_request(int client_socket) {
    char buffer[MAX_REQUEST_SIZE];
    recv(client_socket, buffer, MAX_REQUEST_SIZE, 0);
    printf("Received request: %s\n", buffer);
    char* response = "HTTP/1.1 200 OK\r\nContent-Length: 12\r\n\r\nHello world!";
    send(client_socket, response, strlen(response), 0);
    close(client_socket);
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Failed to create socket\n");
        exit(1);
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address)) == -1) {
        printf("Failed to bind to port %d\n", PORT);
        exit(1);
    }

    if (listen(server_socket, MAX_CONNECTIONS) == -1) {
        printf("Failed to listen on socket\n");
        exit(1);
    }

    printf("Server listening on port %d\n", PORT);

    while (1) {
        struct sockaddr_in client_address;
        int client_socket = accept(server_socket, (struct sockaddr*) &client_address, (socklen_t*) sizeof(client_address));
        if (client_socket == -1) {
            printf("Failed to accept client connection\n");
            continue;
        }

        handle_request(client_socket);
    }

    close(server_socket);
}