//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_BUFFER 8192
#define PORT 8080
#define BACKLOG 10

int main() {
    printf("Greetings! I am a C Simple HTTP Proxy program written in the style of Alan Turing.\n");
    printf("Please input the IP address of the desired server to connect to: ");

    char ip_address[16];
    fgets(ip_address, 16, stdin);
    strtok(ip_address, "\n");

    printf("Please input the port number of the desired server to connect to: ");

    char port_number_string[6];
    fgets(port_number_string, 6, stdin);
    strtok(port_number_string, "\n");
    int port_number = atoi(port_number_string);

    printf("Thank you! Connecting to %s:%d...\n", ip_address, port_number);

    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Oops! Failed to create server socket. Please try again later.\n");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port_number);
    inet_pton(AF_INET, ip_address, &server_address.sin_addr);

    if (connect(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) != 0) {
        printf("Oops! Failed to connect to server. Please try again later.\n");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Connection successful! Listening for incoming connections...\n");

    int proxy_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy_socket == -1) {
        printf("Oops! Failed to create proxy socket. Please try again later.\n");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in proxy_address;
    proxy_address.sin_family = AF_INET;
    proxy_address.sin_port = htons(PORT);
    proxy_address.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(proxy_socket, (struct sockaddr *)&proxy_address, sizeof(proxy_address)) != 0) {
        printf("Oops! Failed to bind proxy socket. Please try again later.\n");
        close(proxy_socket);
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    if (listen(proxy_socket, BACKLOG) != 0) {
        printf("Oops! Failed to listen on proxy socket. Please try again later.\n");
        close(proxy_socket);
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Proxy server listening on port %d...\n", PORT);

    while (1) {
        struct sockaddr_in client_address;
        socklen_t client_address_size = sizeof(client_address);
        int client_socket = accept(proxy_socket, (struct sockaddr *)&client_address, &client_address_size);
        if (client_socket == -1) {
            printf("Oops! Failed to accept connection on proxy socket. Please try again later.\n");
            continue;
        }

        printf("Proxy server accepted incoming connection from %s:%d...\n", inet_ntoa(client_address.sin_addr), client_address.sin_port);

        char request_buffer[MAX_BUFFER];
        memset(request_buffer, 0, sizeof(request_buffer));
        int bytes_received = recv(client_socket, request_buffer, MAX_BUFFER - 1, 0);
        if (bytes_received == -1) {
            printf("Oops! Failed to receive data from client. Please try again later.\n");
            close(client_socket);
            continue;
        }

        printf("Proxy server received request from client: %s", request_buffer);

        if (send(server_socket, request_buffer, strlen(request_buffer), 0) == -1) {
            printf("Oops! Failed to forward request to server. Please try again later.\n");
            close(client_socket);
            continue;
        }

        printf("Proxy server forwarded request to server.\n");

        char response_buffer[MAX_BUFFER];
        memset(response_buffer, 0, sizeof(response_buffer));
        int total_bytes_received = 0;
        while (1) {
            bytes_received = recv(server_socket, response_buffer + total_bytes_received, MAX_BUFFER - total_bytes_received - 1, 0);
            if (bytes_received == -1) {
                printf("Oops! Failed to receive data from server. Please try again later.\n");
                close(client_socket);
                break;
            }

            printf("Proxy server received %d bytes from server.\n", bytes_received);

            if (bytes_received == 0) {
                break;
            }

            total_bytes_received += bytes_received;

            if (send(client_socket, response_buffer, bytes_received, 0) == -1) {
                printf("Oops! Failed to forward response to client. Please try again later.\n");
                break;
            }

            printf("Proxy server forwarded %d bytes to client.\n", bytes_received);
        }

        close(client_socket);
        printf("Proxy server closed client connection.\n");
    }

    close(proxy_socket);
    close(server_socket);

    printf("Goodbye!\n");
    return EXIT_SUCCESS;
}