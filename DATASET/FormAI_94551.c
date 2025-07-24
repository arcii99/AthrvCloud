//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER_PORT 8080
#define PROXY_PORT 8888
#define BUFFER_SIZE 1024

void handle_client(int client_socket, struct sockaddr_in proxy_address);

int main(int argc, char *argv[]) {
    int server_socket, client_socket, option = 1;
    struct sockaddr_in server_address, client_address, proxy_address;
    pid_t pid;

    // Creating the server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Error creating server socket");
        exit(EXIT_FAILURE);
    }

    // Setting socket options
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &option, sizeof(int)) == -1) {
        perror("Error setting socket options");
        exit(EXIT_FAILURE);
    }

    // Setting up server address struct
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(SERVER_PORT);

    // Binding the server socket
    if (bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address)) == -1) {
        perror("Error binding socket");
        exit(EXIT_FAILURE);
    }

    // Listening for connections
    if (listen(server_socket, 10) == -1) {
        perror("Error listening");
        exit(EXIT_FAILURE);
    }

    while (1) {
        printf("Waiting for connections...\n");

        // Accepting incoming connections
        socklen_t client_address_len = sizeof(client_address);
        client_socket = accept(server_socket, (struct sockaddr*) &client_address, &client_address_len);
        if (client_socket == -1) {
            perror("Error accepting connection");
            exit(EXIT_FAILURE);
        }

        // Setting up proxy address struct
        proxy_address.sin_family = AF_INET;
        proxy_address.sin_addr.s_addr = INADDR_ANY;
        proxy_address.sin_port = htons(PROXY_PORT);

        // Forking child process to handle incoming connection
        pid = fork();
        if (pid == -1) {
            perror("Error forking child process");
            exit(EXIT_FAILURE);
        } else if (pid == 0) { // Child process
            close(server_socket);
            handle_client(client_socket, proxy_address);
            exit(EXIT_SUCCESS);
        } else { // Parent process
            close(client_socket);
        }
    }

    return 0;
}

void handle_client(int client_socket, struct sockaddr_in proxy_address) {
    int proxy_socket, bytes_received, bytes_sent;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server_address;

    // Creating the proxy socket
    proxy_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy_socket == -1) {
        perror("Error creating proxy socket");
        exit(EXIT_FAILURE);
    }

    // Connecting to the server
    if (connect(proxy_socket, (struct sockaddr*) &proxy_address, sizeof(proxy_address)) == -1) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    // Receiving data from the client and sending it to the server
    while ((bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0)) > 0) {
        printf("Received %d bytes from client\n", bytes_received);

        bytes_sent = send(proxy_socket, buffer, bytes_received, 0);
        if (bytes_sent == -1) {
            perror("Error sending data to server");
            exit(EXIT_FAILURE);
        }

        printf("Sent %d bytes to server\n", bytes_sent);

        // Receiving data from the server and sending it back to the client
        bytes_received = recv(proxy_socket, buffer, BUFFER_SIZE, 0);
        if (bytes_received == -1) {
            perror("Error receiving data from server");
            exit(EXIT_FAILURE);
        }

        bytes_sent = send(client_socket, buffer, bytes_received, 0);
        if (bytes_sent == -1) {
            perror("Error sending data to client");
            exit(EXIT_FAILURE);
        }

        printf("Sent %d bytes to client\n", bytes_sent);
    }

    close(client_socket);
    close(proxy_socket);
}