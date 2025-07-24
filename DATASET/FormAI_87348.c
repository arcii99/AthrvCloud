//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUF_SIZE 1024

// Function to handle the proxy connection
void handle_connection(int client_fd, struct sockaddr_in client_addr) {
    int server_fd, status;
    struct addrinfo hints, *res;
    char buffer[BUF_SIZE];
    fd_set read_fds, write_fds;
    int maxfd, i;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    // Get the server information from the proxy request
    status = getaddrinfo(buffer, "http", &hints, &res);
    if (status != 0) {
        perror("Error getting server information");
        exit(1);
    }

    // Create a socket for the server connection
    server_fd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (server_fd == -1) {
        perror("Error creating socket for server");
        exit(1);
    }

    // Connect to the server
    status = connect(server_fd, res->ai_addr, res->ai_addrlen);
    if (status == -1) {
        perror("Error connecting to server");
        exit(1);
    }

    // Set up select for asynchronous IO
    FD_ZERO(&read_fds);
    FD_ZERO(&write_fds);
    FD_SET(client_fd, &read_fds);
    FD_SET(server_fd, &read_fds);
    maxfd = (client_fd > server_fd) ? client_fd : server_fd;

    while (1) {
        if (select(maxfd + 1, &read_fds, &write_fds, NULL, NULL) == -1) {
            perror("Error in select");
            exit(1);
        }

        // Client has sent a message to the proxy
        if (FD_ISSET(client_fd, &read_fds)) {
            memset(buffer, 0, BUF_SIZE);
            status = read(client_fd, buffer, BUF_SIZE);
            if (status == -1) {
                perror("Error reading from client");
                exit(1);
            }
            if (status == 0) {
                break;
            }

            // Send the message to the server
            status = send(server_fd, buffer, status, 0);
            if (status == -1) {
                perror("Error sending to server");
                exit(1);
            }
        }

        // Server has sent a message to the proxy
        if (FD_ISSET(server_fd, &read_fds)) {
            memset(buffer, 0, BUF_SIZE);
            status = recv(server_fd, buffer, BUF_SIZE, 0);
            if (status == -1) {
                perror("Error receiving from server");
                exit(1);
            }
            if (status == 0) {
                break;
            }

            // Send the message to the client
            status = write(client_fd, buffer, status);
            if (status == -1) {
                perror("Error sending to client");
                exit(1);
            }
        }
    }

    close(server_fd);
    close(client_fd);
}

int main(int argc, char **argv) {
    int proxy_fd, client_fd, status;
    struct sockaddr_in proxy_addr, client_addr;
    socklen_t sin_size;

    // Create the proxy socket
    proxy_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy_fd == -1) {
        perror("Error creating socket");
        exit(1);
    }

    // Set up the proxy address
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_port = htons(8080);
    proxy_addr.sin_addr.s_addr = INADDR_ANY;
    memset(&(proxy_addr.sin_zero), '\0', 8);

    // Bind the socket to the address
    status = bind(proxy_fd, (struct sockaddr *)&proxy_addr, sizeof(proxy_addr));
    if (status == -1) {
        perror("Error binding to socket");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(proxy_fd, 10) == -1) {
        perror("Error listening on socket");
        exit(1);
    }

    printf("Proxy is running on port 8080...\n");

    while (1) {
        sin_size = sizeof(struct sockaddr_in);
        client_fd = accept(proxy_fd, (struct sockaddr *)&client_addr, &sin_size);
        if (client_fd == -1) {
            perror("Error accepting connection");
            continue;
        }
        printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
        handle_connection(client_fd, client_addr);
    }

    return 0;
}