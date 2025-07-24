//FormAI DATASET v1.0 Category: Simple Web Server ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 8080
#define MAX_REQUEST_SIZE 1024

void handle_request(int connfd);

int main(int argc, char const *argv[]) {
    int sockfd, connfd;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_len;

    // Create socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind socket to address and port
    if (bind(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sockfd, 5) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", PORT);

    // Accept incoming connections and handle requests
    while (1) {
        client_address_len = sizeof(client_address);
        if ((connfd = accept(sockfd, (struct sockaddr *)&client_address, &client_address_len)) == -1) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        handle_request(connfd);

        close(connfd);
    }

    return 0;
}

void handle_request(int connfd) {
    char request[MAX_REQUEST_SIZE];
    ssize_t request_len;
    char response[] = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello World!";

    // Read request from client
    request_len = read(connfd, request, MAX_REQUEST_SIZE);
    if (request_len == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    // Print request to console
    printf("%.*s\n", (int)request_len, request);

    // Send response to client
    if (write(connfd, response, strlen(response)) == -1) {
        perror("write");
        exit(EXIT_FAILURE);
    }
}