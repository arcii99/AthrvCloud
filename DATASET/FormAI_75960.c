//FormAI DATASET v1.0 Category: Socket programming ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>

#define SERVER_PORT 8080

int main() {
    int server_socket, client_socket, optval;
    struct sockaddr_in server_address, client_address;
    socklen_t address_len = sizeof(struct sockaddr_in);
    char buffer[1024];

    // Create server socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Unable to create socket");
        exit(EXIT_FAILURE);
    }

    // Set socket options to allow port reuse
    optval = 1;
    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof optval);

    // Bind the socket to the server address
    memset(&server_address, 0, address_len);
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(SERVER_PORT);

    if(bind(server_socket, (struct sockaddr*) &server_address, address_len) == -1) {
        perror("Unable to bind socket");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if(listen(server_socket, 10) == -1) {
        perror("Unable to listen for connections");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", SERVER_PORT);

    // Accept incoming connections
    while(1) {
        client_socket = accept(server_socket, (struct sockaddr*) &client_address, &address_len);
        if(client_socket == -1) {
            perror("Unable to accept connection");
            continue;
        }

        printf("Client connected: %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        // Read data from client
        memset(buffer, 0, sizeof(buffer));
        if(read(client_socket, buffer, sizeof(buffer)-1) == -1) {
            perror("Unable to read from client");
        } else {
            printf("Client sent %s\n", buffer);
        }

        // Write data to client
        if(write(client_socket, "Hello from server!", 19) == -1) {
            perror("Unable to write to client");
        }

        close(client_socket);
    }

    close(server_socket);
    return 0;
}