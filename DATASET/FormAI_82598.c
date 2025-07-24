//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PROXY_PORT 8000
#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char* argv[]) {

    // Create a proxy socket
    int proxy_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (proxy_socket == -1) {
        perror("Failed to create a socket");
        return EXIT_FAILURE;
    }

    // Set the address and port of the proxy
    struct sockaddr_in proxy_address;
    memset(&proxy_address, 0, sizeof(proxy_address));
    proxy_address.sin_family = AF_INET;
    proxy_address.sin_addr.s_addr = htonl(INADDR_ANY);
    proxy_address.sin_port = htons(PROXY_PORT);

    // Bind the socket to the address and port
    if (bind(proxy_socket, (struct sockaddr*)&proxy_address, sizeof(proxy_address)) == -1) {
        perror("Failed to bind the socket");
        return EXIT_FAILURE;
    }

    // Listen for incoming connections
    if (listen(proxy_socket, 5) == -1) {
        perror("Failed to listen for incoming connections");
        return EXIT_FAILURE;
    }

    printf("Proxy server listening at port %d...\n", PROXY_PORT);

    while (true) {
        // Accept an incoming connection
        struct sockaddr_in client_address;
        socklen_t client_address_size = sizeof(client_address);
        int client_socket = accept(proxy_socket, (struct sockaddr*)&client_address, &client_address_size);

        if (client_socket == -1) {
            perror("Failed to accept an incoming connection");
            continue;
        }

        printf("Accepted a client from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        // Create a server socket
        int server_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

        if (server_socket == -1) {
            perror("Failed to create a socket");
            close(client_socket);
            continue;
        }

        // Set the address and port of the server
        struct sockaddr_in server_address;
        memset(&server_address, 0, sizeof(server_address));
        server_address.sin_family = AF_INET;
        server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
        server_address.sin_port = htons(SERVER_PORT);

        // Connect to the server
        if (connect(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
            perror("Failed to connect to the server");
            close(client_socket);
            close(server_socket);
            continue;
        }

        printf("Connected to the server at %s:%d\n", inet_ntoa(server_address.sin_addr), ntohs(server_address.sin_port));

        // Forward data between the client and server
        while (true) {
            char buffer[BUFFER_SIZE];
            int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);

            if (bytes_received == -1) {
                perror("Failed to receive data from the client");
                break;
            }

            if (bytes_received == 0) {
                printf("Client disconnected\n");
                break;
            }

            printf("Received %d bytes from the client\n", bytes_received);

            int bytes_sent = send(server_socket, buffer, bytes_received, 0);

            if (bytes_sent == -1) {
                perror("Failed to send data to the server");
                break;
            }

            printf("Sent %d bytes to the server\n", bytes_sent);

            bytes_received = recv(server_socket, buffer, BUFFER_SIZE, 0);

            if (bytes_received == -1) {
                perror("Failed to receive data from the server");
                break;
            }

            if (bytes_received == 0) {
                printf("Server disconnected\n");
                break;
            }

            printf("Received %d bytes from the server\n", bytes_received);

            bytes_sent = send(client_socket, buffer, bytes_received, 0);

            if (bytes_sent == -1) {
                perror("Failed to send data to the client");
                break;
            }

            printf("Sent %d bytes to the client\n", bytes_sent);
        }

        // Close the client and server sockets
        close(client_socket);
        close(server_socket);
    }

    // Close the proxy socket
    close(proxy_socket);

    return EXIT_SUCCESS;
}