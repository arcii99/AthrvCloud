//FormAI DATASET v1.0 Category: Socket programming ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT_NUMBER 8080
#define MAX_CONNECTIONS 5
#define BUFFER_SIZE 1024

void process_client(int client_sock_fd, struct sockaddr_in client_address);

int main(int argc, char *argv[]) {
    int server_sock_fd, client_sock_fd;
    struct sockaddr_in server_address, client_address;
    char buffer[BUFFER_SIZE];

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);   
    server_address.sin_port = htons(PORT_NUMBER);

    server_sock_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (server_sock_fd < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    if (bind(server_sock_fd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Failed to bind socket");
        exit(EXIT_FAILURE);
    }

    if (listen(server_sock_fd, MAX_CONNECTIONS) < 0) {
        perror("Failed to listen on socket");
        exit(EXIT_FAILURE);
    }

    printf("Listening on port %d\n", PORT_NUMBER);

    while (1) {
        socklen_t client_address_len = sizeof(client_address);
        client_sock_fd = accept(server_sock_fd, (struct sockaddr *) &client_address, &client_address_len);

        if (client_sock_fd < 0) {
            perror("Failed to accept client connection");
            continue;
        }

        printf("Client connected: %s\n", inet_ntoa(client_address.sin_addr));

        if (fork() == 0) {
            close(server_sock_fd);
            process_client(client_sock_fd, client_address);
            exit(EXIT_SUCCESS);
        }

        close(client_sock_fd);
    }

    close(server_sock_fd);

    return 0;
}

void process_client(int client_sock_fd, struct sockaddr_in client_address) {
    char request[BUFFER_SIZE];
    char response[BUFFER_SIZE];

    memset(request, 0, sizeof(request));
    memset(response, 0, sizeof(response));

    if (read(client_sock_fd, request, sizeof(request)) < 0) {
        perror("Failed to receive client request");
        exit(EXIT_FAILURE);
    }

    printf("Received request from client %s: %s\n", inet_ntoa(client_address.sin_addr), request);

    // Your custom logic here ...

    strcpy(response, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n");
    strcat(response, "<html><head><title>Hello C Socket Programming!</title></head><body><h1>Hello C Socket Programming!</h1></body></html>");

    if (write(client_sock_fd, response, strlen(response)) < 0) {
        perror("Failed to send server response");
        exit(EXIT_FAILURE);
    }

    printf("Sent response to client %s: %s\n", inet_ntoa(client_address.sin_addr), response);
}