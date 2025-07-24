//FormAI DATASET v1.0 Category: Simple Web Server ; Style: sophisticated
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 

#define MAX_REQUEST_SIZE 4096

void handle_request(int socket_fd);

int main(int argc, char* argv[]) {
    int socket_fd, client_fd, opt = 1;
    struct sockaddr_in server_address, client_address;
    socklen_t client_len = sizeof(client_address);

    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Failed to set socket options");
        exit(EXIT_FAILURE);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY; 
    server_address.sin_port = htons(8080);

    if (bind(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address))<0) {
        perror("Failed to bind socket");
        exit(EXIT_FAILURE);
    }

    if (listen(socket_fd, 3) < 0) {
        perror("Failed to listen on socket");
        exit(EXIT_FAILURE);
    }

    while (1) {
        if ((client_fd = accept(socket_fd, (struct sockaddr *)&client_address, (socklen_t*)&client_len)) < 0) {
            perror("Failed to accept client connection");
            exit(EXIT_FAILURE);
        }

        if (fork() == 0) {
            close(socket_fd);
            handle_request(client_fd);
            close(client_fd);
            exit(EXIT_SUCCESS);
        } else {
            close(client_fd);
        }
    }

    return 0;
}

void handle_request(int socket_fd) {
    char request_buffer[MAX_REQUEST_SIZE] = {0};

    if (read(socket_fd, request_buffer, MAX_REQUEST_SIZE) >= 0) {
        printf("%s\n", request_buffer);

        char* response_message = "HTTP/1.1 200 OK\nServer: MySimpleWebServer/1.0.0\nContent-Length: 12\nContent-Type: text/plain\n\nHello World!";

        if (write(socket_fd, response_message, strlen(response_message)) < 0) {
            perror("Failed to send response message");
            exit(EXIT_FAILURE);
        }
    } else {
        perror("Failed to read request message");
        exit(EXIT_FAILURE);
    }
}