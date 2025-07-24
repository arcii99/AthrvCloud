//FormAI DATASET v1.0 Category: Simple Web Server ; Style: recursive
/* Recursive Simple Web Server in C */
/* By: [Your Name] */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

void handle_request(int socket_fd, char *request) {
    char *response = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<html><body><h1>Welcome to my Simple Web Server!</h1></body></html>";
    write(socket_fd, response, strlen(response));
    close(socket_fd);
}

void init_server(int server_fd, struct sockaddr_in address) {
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
}

void start_server(int server_fd, struct sockaddr_in address, int addrlen) {
    int new_socket;
    char buffer[1024] = {0};
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }
    read(new_socket, buffer, 1024);
    handle_request(new_socket, buffer);
    start_server(server_fd, address, addrlen);
}

int main() {
    int server_fd;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    init_server(server_fd, address);

    start_server(server_fd, address, addrlen);
    
    return 0;
}