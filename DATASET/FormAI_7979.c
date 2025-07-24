//FormAI DATASET v1.0 Category: Simple Web Server ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8080
#define BACKLOG 10

int main() {
    int server_fd, client_fd;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_len = sizeof(client_address);

    char *response = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<h1>Welcome to my web server!</h1>";
    char buffer[1024] = {0};

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    // Set server address and bind
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Bind error");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, BACKLOG) < 0) {
        perror("Listen error");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connections and handle requests
    while (1) {
        if ((client_fd = accept(server_fd, (struct sockaddr *)&client_address, &client_address_len)) < 0) {
            perror("Accept error");
            exit(EXIT_FAILURE);
        } 

        // Read request from client
        read(client_fd, buffer, 1024);
        printf("Received request:\n%s\n", buffer);

        // Send response to client
        send(client_fd, response, strlen(response), 0);
        memset(buffer, 0, sizeof buffer);

        close(client_fd);
    }

    return 0;
}