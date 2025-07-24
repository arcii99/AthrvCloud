//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_PORT 8000
#define MAX_BUFFER 2048

void handle_request(int client_socket);

int main(int argc, char **argv) {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    int client_address_length;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Error creating server socket");
        exit(EXIT_FAILURE);
    }

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(SERVER_PORT);

    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Error binding server socket");
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, 10) < 0) {
        perror("Error listening on server socket");
        exit(EXIT_FAILURE);
    }

    printf("Server started on port %d\n", SERVER_PORT);

    while (1) {
        client_address_length = sizeof(client_address);
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, (socklen_t *)&client_address_length);
        if (client_socket < 0) {
            perror("Error accepting client connection");
            exit(EXIT_FAILURE);
        }

        handle_request(client_socket);
        close(client_socket);
    }

    close(server_socket);
    return 0;
}

void handle_request(int client_socket) {
    char buffer[MAX_BUFFER] = {'\0'};
    char request[MAX_BUFFER] = {'\0'};
    char *host = NULL;
    ssize_t bytes_received = 0;

    bytes_received = recv(client_socket, buffer, MAX_BUFFER, 0);
    if (bytes_received < 0) {
        perror("Error receiving client request");
        exit(EXIT_FAILURE);
    }

    printf("Received client request:\n%s", buffer);

    host = strstr(buffer, "Host: ");
    if (host == NULL) {
        perror("Could not find host in client request");
        exit(EXIT_FAILURE);
    }

    sscanf(host, "Host: %s", request);

    int proxy_socket;
    struct sockaddr_in proxy_address;

    proxy_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy_socket < 0) {
        perror("Error creating proxy socket");
        exit(EXIT_FAILURE);
    }

    memset(&proxy_address, 0, sizeof(proxy_address));
    proxy_address.sin_family = AF_INET;
    proxy_address.sin_addr.s_addr = inet_addr(request);
    proxy_address.sin_port = htons(80);

    if (connect(proxy_socket, (struct sockaddr *)&proxy_address, sizeof(proxy_address)) < 0) {
        perror("Error connecting to proxy server");
        exit(EXIT_FAILURE);
    }

    if (send(proxy_socket, buffer, bytes_received, 0) < 0) {
        perror("Error sending request to proxy server");
        exit(EXIT_FAILURE);
    }

    while (1) {
        bytes_received = recv(proxy_socket, buffer, MAX_BUFFER, 0);
        if (bytes_received < 0) {
            perror("Error receiving response from proxy server");
            exit(EXIT_FAILURE);
        } else if (bytes_received == 0) {
            break;
        }

        if (send(client_socket, buffer, bytes_received, 0) < 0) {
            perror("Error sending response to client");
            exit(EXIT_FAILURE);
        }
    }

    close(proxy_socket);
}