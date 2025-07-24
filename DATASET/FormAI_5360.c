//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

#define BUFFER_SIZE 1024

void handle_client(int client_socket_fd) {
    char buffer[BUFFER_SIZE];
    ssize_t bytes_recv;
    ssize_t bytes_sent;

    // read data from client
    bytes_recv = recv(client_socket_fd, buffer, BUFFER_SIZE, 0);

    if (bytes_recv < 0) {
        perror("Error receiving data from client.\n");
        exit(1);
    }

    // parse host and port from client's request
    char *host, *port, *http_version;
    host = strstr(buffer, "Host: ");

    if (host == NULL) {
        perror("Error parsing Host from client's request.\n");
        exit(1);
    }

    host = host + strlen("Host: ");
    char *host_end = strstr(host, "\r\n");

    if (host_end == NULL) {
        perror("Error parsing Host from client's request.\n");
        exit(1);
    }

    *host_end = '\0';
    port = strchr(host, ':');

    if (port == NULL) {
        port = "80";
    } else {
        *port = '\0';
        port = port + 1;
    }

    http_version = strstr(buffer, "HTTP/");

    if (http_version == NULL) {
        perror("Error parsing HTTP version from client's request.\n");
        exit(1);
    }

    http_version = http_version + strlen("HTTP/");

    char *server_url = malloc(strlen(host) + strlen(port) + 8);
    strcpy(server_url, "http://");
    strcat(server_url, host);
    strcat(server_url, ":");
    strcat(server_url, port);

    printf("Handling client request. Host: %s, Port: %s, HTTP Version: %s\n", host, port, http_version);

    int server_socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket_fd < 0) {
        perror("Error creating socket for server.\n");
        exit(1);
    }

    struct sockaddr_in server_address = {
        .sin_family = AF_INET,
        .sin_addr.s_addr = inet_addr(host),
        .sin_port = htons(atoi(port)),
    };

    if (connect(server_socket_fd, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        perror("Error connecting to server.\n");
        exit(1);
    }

    // send request to server
    bytes_sent = send(server_socket_fd, buffer, bytes_recv, 0);

    if (bytes_sent < 0) {
        perror("Error sending data to server.\n");
        exit(1);
    }

    // receive data from server
    bool retransmission_flag = false;

    do {
        bytes_recv = recv(server_socket_fd, buffer, BUFFER_SIZE, 0);

        if (bytes_recv < 0) {
            perror("Error receiving data from server.\n");
            exit(1);
        }

        if (!retransmission_flag) {
            // send data to client if there were no errors while receiving data from server
            bytes_sent = send(client_socket_fd, buffer, bytes_recv, 0);

            if (bytes_sent < 0) {
                perror("Error sending data to client.\n");
                exit(1);
            }
        }

        retransmission_flag = false;
    } while (bytes_recv > 0);

    close(client_socket_fd);
    close(server_socket_fd);
}

int main() {
    int server_socket_fd, client_socket_fd;
    ssize_t bytes_recv;
    struct sockaddr_in server_address = {
        .sin_family = AF_INET,
        .sin_addr.s_addr = INADDR_ANY,
        .sin_port = htons(8080),
    };
    struct sockaddr_in client_address;
    socklen_t client_address_len = sizeof(client_address);

    server_socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket_fd < 0) {
        perror("Error creating socket for server.\n");
        exit(1);
    }

    if (bind(server_socket_fd, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        perror("Error binding socket to address.\n");
        exit(1);
    }

    if (listen(server_socket_fd, 10) < 0) {
        perror("Error listening on socket.\n");
        exit(1);
    }

    printf("Started HTTP proxy server on port %d\n", ntohs(server_address.sin_port));

    while (true) {
        client_socket_fd = accept(server_socket_fd, (struct sockaddr*)&client_address, &client_address_len);

        if (client_socket_fd < 0) {
            perror("Error accepting connection.\n");
            exit(1);
        }

        handle_client(client_socket_fd);
    }

    return 0;
}