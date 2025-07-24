//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 8080
#define PROXY_PORT 9090
#define BUFFER_SIZE 1024

void handle_client(int client_socket);

int main() {
    int server_socket, proxy_socket, client_socket, opt = 1;
    struct sockaddr_in server_addr, proxy_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    // create server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Error creating server socket");
        exit(EXIT_FAILURE);
    }

    // set server socket to reusable
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Error setting server socket to reusable");
        exit(EXIT_FAILURE);
    }

    // bind server socket to address and port
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
    server_addr.sin_port = htons(SERVER_PORT);

    if (bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding server socket to address and port");
        exit(EXIT_FAILURE);
    }

    // listen for incoming client connections
    if (listen(server_socket, 3) < 0) {
        perror("Error listening for incoming client connections");
        exit(EXIT_FAILURE);
    }

    printf("Simple HTTP Proxy listening on port %d\n", PROXY_PORT);

    // create proxy socket
    proxy_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy_socket == -1) {
        perror("Error creating proxy socket");
        exit(EXIT_FAILURE);
    }

    // set proxy socket to reusable
    if (setsockopt(proxy_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Error setting proxy socket to reusable");
        exit(EXIT_FAILURE);
    }

    // bind proxy socket to port
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_addr.s_addr = INADDR_ANY;
    proxy_addr.sin_port = htons(PROXY_PORT);

    if (bind(proxy_socket, (struct sockaddr *) &proxy_addr, sizeof(proxy_addr)) < 0) {
        perror("Error binding proxy socket to port");
        exit(EXIT_FAILURE);
    }

    // listen for incoming client connections
    if (listen(proxy_socket, 3) < 0) {
        perror("Error listening for incoming client connections");
        exit(EXIT_FAILURE);
    }

    printf("Proxy Server listening on port %d\n", PROXY_PORT);

    while (true) {
        // accept incoming client connection
        client_socket = accept(server_socket, (struct sockaddr *) &client_addr, &client_addr_len);
        if (client_socket < 0) {
            perror("Error accepting incoming client connection");
            exit(EXIT_FAILURE);
        }

        printf("Incoming client connection accepted\n");

        // fork process to handle client connection
        pid_t pid = fork();

        if (pid < 0) {
            perror("Error forking process");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            // child process handles client connection
            close(server_socket);
            handle_client(client_socket);
            exit(EXIT_SUCCESS);
        }

        // parent process continues to listen for incoming client connections
        close(client_socket);
    }

    return 0;
}

void handle_client(int client_socket) {
    int proxy_socket, valread, opt = 1;
    char buffer[BUFFER_SIZE] = {0};
    struct sockaddr_in proxy_addr;
    socklen_t proxy_addr_len = sizeof(proxy_addr);

    // create proxy socket
    proxy_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy_socket == -1) {
        perror("Error creating proxy socket");
        exit(EXIT_FAILURE);
    }

    // set proxy socket to reusable
    if (setsockopt(proxy_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Error setting proxy socket to reusable");
        exit(EXIT_FAILURE);
    }

    // connect proxy socket to server address and port
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
    proxy_addr.sin_port = htons(SERVER_PORT);

    if (connect(proxy_socket, (struct sockaddr *) &proxy_addr, sizeof(proxy_addr)) < 0) {
        perror("Error connecting proxy socket to server address and port");
        exit(EXIT_FAILURE);
    }

    printf("Proxying client request...\n");

    // read client request
    valread = read(client_socket, buffer, BUFFER_SIZE);
    if (valread < 0) {
        perror("Error reading client request");
        exit(EXIT_FAILURE);
    }

    printf("Received client request:\n%s\n", buffer);

    // send client request to server
    if (send(proxy_socket, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending client request to server");
        exit(EXIT_FAILURE);
    }

    printf("Sent client request to server\n");

    // read server response
    memset(buffer, 0, BUFFER_SIZE);
    valread = read(proxy_socket, buffer, BUFFER_SIZE);
    if (valread < 0) {
        perror("Error reading server response");
        exit(EXIT_FAILURE);
    }

    printf("Received server response:\n%s\n", buffer);

    // send server response to client
    if (send(client_socket, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending server response to client");
        exit(EXIT_FAILURE);
    }

    printf("Sent server response to client\n");

    // close sockets
    close(client_socket);
    close(proxy_socket);
}