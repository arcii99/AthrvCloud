//FormAI DATASET v1.0 Category: Socket programming ; Style: scientific
// This program creates a socket on the server side and allows clients to connect, and then echoes back any messages sent by the client.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_BUFFER_SIZE 1024

int main() {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[MAX_BUFFER_SIZE] = {0};
    char *message = "Hello from server";

    // Create server socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Socket options error");
        exit(EXIT_FAILURE);
    }

    // Fill in server address information
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );

    // Bind server socket to address and port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("Socket binding error");
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen error");
        exit(EXIT_FAILURE);
    }

    // Accept client connection
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
        perror("Accept error");
        exit(EXIT_FAILURE);
    }

    // Receive and echo back client message indefinitely
    while (1) {
        valread = read(new_socket, buffer, MAX_BUFFER_SIZE);
        if (valread == 0) {
            printf("Client disconnected\n");
            break;
        }
        printf("Client: %s\n", buffer);
        if (strcmp(buffer, "exit") == 0) {
            printf("Client requested to exit\n");
            break;
        }
        write(new_socket, buffer, strlen(buffer));
        memset(buffer, 0, sizeof(buffer));
    }

    // Close sockets
    close(new_socket);
    close(server_fd);

    return 0;
}