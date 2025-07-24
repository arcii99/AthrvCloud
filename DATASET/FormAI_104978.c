//FormAI DATASET v1.0 Category: Simple Web Server ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void handle_request(int client_socket);

int main(int argc, char const *argv[]) {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t sock_size;

    // create a socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    // bind socket to a port
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8080);

    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("Failed to bind socket");
        exit(EXIT_FAILURE);
    }

    // listen for incoming connections
    if (listen(server_socket, 10) == -1) {
        perror("Failed to listen");
        exit(EXIT_FAILURE);
    }

    printf("Server running on port 8080\n");

    // handle incoming connections
    while (1) {
        sock_size = sizeof(client_address);
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, &sock_size);

        if (client_socket == -1) {
            perror("Failed to accept incoming connection");
            continue;
        }

        printf("New incoming connection from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        // handle request from client
        handle_request(client_socket);

        // close socket
        close(client_socket);
    }

    // close server socket
    close(server_socket);

    return 0;
}

void handle_request(int client_socket) {
    char buffer[BUFFER_SIZE];
    char response[] = "HTTP/1.1 200 OK\r\nContent-Type: text/html; charset=UTF-8\r\n\r\n<!DOCTYPE html><html><head><title>Simple Web Server</title></head><body><h1>Welcome to the Simple Web Server</h1></body></html>";
    int length = strlen(response);

    // read request from client
    int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
    if (bytes_received == -1) {
        perror("Failed to receive data from client");
        exit(EXIT_FAILURE);
    }

    printf("Received %d bytes from client: %s\n", bytes_received, buffer);

    // send response to client
    int bytes_sent = send(client_socket, response, length, 0);
    if (bytes_sent == -1) {
        perror("Failed to send data to client");
        exit(EXIT_FAILURE);
    }

    printf("Sent %d bytes to client\n", bytes_sent);
}