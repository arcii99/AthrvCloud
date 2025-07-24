//FormAI DATASET v1.0 Category: Socket programming ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define RESPONSE_BUFFER_SIZE 1024
#define REQUEST_BUFFER_SIZE 1024
#define PORT 8080

void handle_client(int sockfd) {
    char request_buffer[REQUEST_BUFFER_SIZE] = {0};
    char response_buffer[RESPONSE_BUFFER_SIZE] = {0};
    int valread;
    
    printf("Waiting for Client request...\n");

    valread = read(sockfd, request_buffer, REQUEST_BUFFER_SIZE);
    printf("Request from Client: %s\n", request_buffer);

    // Get response for the request
    snprintf(response_buffer, RESPONSE_BUFFER_SIZE, "Hello from server!");

    // Send response to the client
    send(sockfd, response_buffer, strlen(response_buffer), 0);
    
    printf("Response sent to Client: %s\n", response_buffer);
}

int main(int argc, char const *argv[]) {
    int server_fd, client_socket, opt = 1;
    struct sockaddr_in address;
    int address_len = sizeof(address);

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attach socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to localhost:8080
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening on the socket
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    while (1) {
        printf("Awaiting Connection...\n");
        if ((client_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&address_len)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        handle_client(client_socket);
    }
}