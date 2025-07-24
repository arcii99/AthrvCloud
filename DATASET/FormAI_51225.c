//FormAI DATASET v1.0 Category: Simple Web Server ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const *argv[])
{
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *response = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<html><body><h1>Hello, World!</h1></body></html>";

    // Create server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("Could not create socket. Game Over.");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        printf("Could not set socket options. Game Over.");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );

    // Bind socket to address
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        printf("Could not bind socket to address. Game Over.");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        printf("Could not listen for incoming connections. Game Over.");
        exit(EXIT_FAILURE);
    }

    // Wait for incoming connections
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
        printf("Could not accept connection. Game Over.");
        exit(EXIT_FAILURE);
    }

    // Read incoming request
    valread = read(new_socket , buffer, 1024);
    printf("%s\n", buffer);

    // Send response
    send(new_socket , response , strlen(response) , 0 );
    printf("Response sent\n");

    return 0;
}