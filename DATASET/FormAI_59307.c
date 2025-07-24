//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 8080

int main(int argc, char const *argv[]) {
    struct sockaddr_in client_address, server_address;
    int server_socket_fd, client_socket_fd;
    char buffer[BUFFER_SIZE];

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SERVER_PORT);
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);

    if ((server_socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket() failed");
        return EXIT_FAILURE;
    }

    if (bind(server_socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("bind() failed");
        return EXIT_FAILURE;
    }

    if (listen(server_socket_fd, 5) < 0) {
        perror("listen() failed");
        return EXIT_FAILURE;
    }

    printf("Server listening on port %d\n", SERVER_PORT);

    while (1) {
        socklen_t client_address_len = sizeof(client_address);

        if ((client_socket_fd = accept(server_socket_fd, (struct sockaddr *)&client_address, &client_address_len)) < 0) {
            perror("accept() failed");
            return EXIT_FAILURE;
        }

        printf("Client connected: %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        while (1) {
            ssize_t num_bytes_received = recv(client_socket_fd, buffer, sizeof(buffer), 0);
            if (num_bytes_received < 0) {
                perror("recv() failed");
                return EXIT_FAILURE;
            } else if (num_bytes_received == 0) {
                printf("Client disconnected: %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
                break;
            } else {
                printf("[Received from client %s:%d] %d bytes: %s\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port), num_bytes_received, buffer);
                ssize_t num_bytes_sent = send(client_socket_fd, buffer, num_bytes_received, 0);
                if (num_bytes_sent < 0) {
                    perror("send() failed");
                    return EXIT_FAILURE;
                }
            }
        }

        close(client_socket_fd);
    }

    return EXIT_SUCCESS;
}