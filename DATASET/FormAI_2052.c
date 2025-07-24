//FormAI DATASET v1.0 Category: Socket programming ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

void handle_connection(int socket_fd);

int main(int argc, char const *argv[]) {
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        perror("Unable to create socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8080);

    if (bind(socket_fd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    listen(socket_fd, 5);
    printf("Server listening on port 8080\n");

    struct sockaddr_in client_address;
    socklen_t client_address_len = sizeof(client_address);

    int new_socket_fd = accept(socket_fd, (struct sockaddr *) &client_address, &client_address_len);
    if (new_socket_fd < 0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    printf("New Connection Accepted!");

    handle_connection(new_socket_fd);

    close(socket_fd);
    return 0;
}

void handle_connection(int socket_fd) {
    char buffer[1024] = {0};
    char *response = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<html><body><h1>Hello World!</h1></body></html>";

    read(socket_fd, buffer, 1024);
    printf("%s\n", buffer);

    send(socket_fd, response, strlen(response), 0);
}