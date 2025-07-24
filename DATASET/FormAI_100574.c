//FormAI DATASET v1.0 Category: Simple Web Server ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define RESPONSE_SIZE 1024

// Handles incoming requests and sends back a response
void handle_request(int socket) {
    char request[1024] = {0};
    char response[RESPONSE_SIZE] = {0};
    read(socket, request, 1024);
    printf("Received request: %s\n", request);

    snprintf(response, RESPONSE_SIZE, "HTTP/1.1 200 OK\n\nHello, world!");
    send(socket, response, strlen(response), 0);
    printf("Sent response: %s\n", response);
}

// Creates a new TCP socket and binds it to a port
int create_socket() {
    int server_fd, opt = 1;
    struct sockaddr_in address;

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", PORT);
    return server_fd;
}

int main() {
    int server_fd, new_socket, read_value;
    struct sockaddr_in address;
    int address_length = sizeof(address);

    server_fd = create_socket();
    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&address_length)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        handle_request(new_socket);
        close(new_socket);
    }
    return 0;
}