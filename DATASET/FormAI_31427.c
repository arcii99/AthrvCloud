//FormAI DATASET v1.0 Category: Simple Web Server ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

void handle_request(int client_socket) {
    char response[] = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE html><html><head><title>My First Web Server</title></head><body><h1>Hello World!</h1></body></html>";
    write(client_socket, response, sizeof(response));
    close(client_socket);
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_size;
    char buffer[1024];

    // create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Failed to create socket");
        exit(1);
    }

    // bind socket to port 8080
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(8080);
    if (bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        perror("Failed to bind to port 8080");
        exit(1);
    }

    // listen for incoming connections
    if (listen(server_socket, 10) == -1) {
        perror("Failed to listen for connections");
        exit(1);
    }

    printf("Server is running on port 8080...\n");

    // handle incoming connections
    while (1) {
        client_address_size = sizeof(client_address);
        client_socket = accept(server_socket, (struct sockaddr*)&client_address, &client_address_size);
        if (client_socket == -1) {
            perror("Failed to accept incoming connection");
            continue;
        }

        printf("New client connected: %s\n", inet_ntoa(client_address.sin_addr));

        if (recv(client_socket, buffer, sizeof(buffer), 0) == -1) {
            perror("Failed to receive client request");
            close(client_socket);
            continue;
        }

        handle_request(client_socket);
    }

    // close server socket
    close(server_socket);

    return 0;
}