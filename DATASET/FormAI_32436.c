//FormAI DATASET v1.0 Category: Client Server Application ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void serve_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int read_size;

    // read message from client
    read_size = recv(client_socket, buffer, BUFFER_SIZE, 0);

    if (read_size < 0) {
        perror("Failed to receive message from client");
        exit(EXIT_FAILURE);
    }

    printf("Client sent: %s\n", buffer);

    // send message to client
    strcpy(buffer, "Hello from server");
    if (send(client_socket, buffer, strlen(buffer), 0) < 0) {
        perror("Failed to send message to client");
        exit(EXIT_FAILURE);
    }
}

int main() {
    int server_fd, client_socket;
    struct sockaddr_in address;

    // create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Failed to create socket file descriptor");
        exit(EXIT_FAILURE);
    }

    // set address family, port, and IP address for socket
    address.sin_family = AF_INET;
    address.sin_port = htons(PORT);
    address.sin_addr.s_addr = INADDR_ANY;

    // bind socket to address
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Failed to bind socket to address");
        exit(EXIT_FAILURE);
    }

    // listen for incoming connections
    if (listen(server_fd, 5) < 0) {
        perror("Failed to listen for incoming connections");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d\n", PORT);

    while (1) {
        // accept incoming connection
        if ((client_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&address)) < 0) {
            perror("Failed to accept incoming connection");
            exit(EXIT_FAILURE);
        }

        printf("Client connected from %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

        // serve client
        serve_client(client_socket);

        // close client connection
        close(client_socket);
    }

    return 0;
}