//FormAI DATASET v1.0 Category: Chat server ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void handle_client(int socket_fd) {
    char buffer[BUFFER_SIZE] = {0};
    ssize_t received = recv(socket_fd, buffer, BUFFER_SIZE, 0);
    if (received < 0) {
        perror("Error receiving data from client");
        close(socket_fd);
        return;
    }
    printf("Client message: %s\n", buffer);
    if (strcmp(buffer, "quit\n")) {
        close(socket_fd);
        return;
    }
    send(socket_fd, buffer, received, 0);
    handle_client(socket_fd);
}

int main() {
    int server_fd;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                   &opt, sizeof(opt))) {
        perror("Failed to set socket options");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *) &address, sizeof(address)) < 0) {
        perror("Failed to bind socket");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0) {
        perror("Failed to listen on socket");
        exit(EXIT_FAILURE);
    }
    printf("Server listening on port %d\n", PORT);

    while (1) {
        int new_socket_fd;
        if ((new_socket_fd = accept(server_fd, (struct sockaddr *) &address,
                                    (socklen_t *) &addrlen)) < 0) {
            perror("Failed to accept connection");
            exit(EXIT_FAILURE);
        }
        pid_t pid = fork();
        if (pid < 0) {
            perror("Failed to create child process");
            exit(EXIT_FAILURE);
        }
        if (pid == 0) {
            handle_client(new_socket_fd);
            exit(EXIT_SUCCESS);
        }
        close(new_socket_fd);
    }
    return 0;
}