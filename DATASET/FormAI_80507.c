//FormAI DATASET v1.0 Category: Simple Web Server ; Style: sophisticated
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define RESPONSE_BODY "<html><body><h1>Welcome to my Simple Web Server</h1></body></html>"
#define RESPONSE_HEADER "HTTP/1.1 200 OK\r\n" \
                        "Content-Type: text/html;charset=UTF-8\r\n" \
                        "Content-Length: %ld\r\n\r\n"

void handle_request(int client_socket) {
    char buffer[1024];
    ssize_t bytes_read;
    bytes_read = recv(client_socket, buffer, 1024, 0);
    if (bytes_read <= 0) {
        close(client_socket);
        return;
    }
    printf("Received request from client:\n%s\n", buffer);
    send(client_socket, RESPONSE_HEADER, strlen(RESPONSE_HEADER), 0);
    send(client_socket, RESPONSE_BODY, strlen(RESPONSE_BODY), 0);
    close(client_socket);
}

int main() {
    int server_fd, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t address_length = sizeof(client_address);

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8080);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    if (bind(server_fd, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
        perror("Error binding socket");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 5) == -1) {
        perror("Error listening on socket");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port 8080\n");

    while (1) {
        client_socket = accept(server_fd, (struct sockaddr *) &client_address, &address_length);
        if (client_socket == -1) {
            perror("Error accepting connection");
            continue;
        }
        printf("New client connected\n");
        handle_request(client_socket);
    }
    return EXIT_SUCCESS;
}