//FormAI DATASET v1.0 Category: Networking ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void handle_connection(int client_socket_fd) {
    char buffer[BUFFER_SIZE];
    int read_size = read(client_socket_fd, buffer, BUFFER_SIZE);
    if (read_size == 0) {
        printf("Client disconnected.\n");
        close(client_socket_fd);
        return;
    }
    buffer[read_size] = '\0';
    printf("Received message: %s", buffer);
    write(client_socket_fd, buffer, strlen(buffer));
    handle_connection(client_socket_fd);
}

int main() {
    int server_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket_fd == -1) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_address, client_address;
    memset(&server_address, '0', sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(PORT);

    if (bind(server_socket_fd, (struct sockaddr*) &server_address, sizeof(server_address)) == -1) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket_fd, 5) == -1) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    while (true) {
        unsigned int client_address_size = sizeof(client_address);
        int client_socket_fd = accept(server_socket_fd, (struct sockaddr*) &client_address, &client_address_size);
        if (client_socket_fd == -1) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }
        char client_address_string[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &client_address.sin_addr, client_address_string, INET_ADDRSTRLEN);
        printf("Accepted connection from %s:%d.\n", client_address_string, ntohs(client_address.sin_port));
        handle_connection(client_socket_fd);
    }

    close(server_socket_fd);
    return 0;
}