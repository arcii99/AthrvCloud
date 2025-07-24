//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define MAX_BUFFER_SIZE 1024
#define PROXY_PORT 8888

void multiplayer_proxy(int source_socket_fd, struct sockaddr_in source_address) {
    char buffer[MAX_BUFFER_SIZE];
    int dest_socket_fd, n;
    struct sockaddr_in dest_address;

    bzero(&dest_address, sizeof(dest_address));

    // Fill the destination address
    dest_address.sin_family = AF_INET;
    dest_address.sin_port = htons(80);
    dest_address.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Create the destination socket
    dest_socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (connect(dest_socket_fd, (struct sockaddr*) &dest_address, sizeof(dest_address)) < 0) {
        perror("Connection error");
        exit(1);
    }

    // Forward the data from the source socket to the destination socket
    while ((n = read(source_socket_fd, buffer, MAX_BUFFER_SIZE)) > 0) {
        write(dest_socket_fd, buffer, n);
    }

    close(dest_socket_fd);
}

int main(int argc, char *argv[]) {
    int proxy_socket_fd, client_socket_fd;
    struct sockaddr_in proxy_address, client_address;

    // Create the proxy socket
    proxy_socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (proxy_socket_fd < 0) {
        perror("Socket creation error");
        exit(1);
    }

    // Fill the proxy address
    bzero(&proxy_address, sizeof(proxy_address));

    proxy_address.sin_family = AF_INET;
    proxy_address.sin_port = htons(PROXY_PORT);
    proxy_address.sin_addr.s_addr = htonl(INADDR_ANY);

    // Bind the proxy socket to the proxy address
    if (bind(proxy_socket_fd, (struct sockaddr*) &proxy_address, sizeof(proxy_address)) < 0) {
        perror("Bind error");
        exit(1);
    }

    // Start listening for incoming connections
    if (listen(proxy_socket_fd, 3) < 0) {
        perror("Listen error");
        exit(1);
    }

    while (1) {
        int client_address_len = sizeof(client_address);

        // Accept the incoming connection from the client
        client_socket_fd = accept(proxy_socket_fd, (struct sockaddr*) &client_address, &client_address_len);

        if (client_socket_fd < 0) {
            perror("Accept error");
            exit(1);
        }

        // Fork a new process to handle the client
        if (fork() == 0) {
            close(proxy_socket_fd);

            // Handle the client in multiplayer mode
            multiplayer_proxy(client_socket_fd, client_address);

            exit(0);
        } else {
            close(client_socket_fd);
        }
    }

    return 0;
}