//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024

int main() {
    int server_socket, client_socket, addr_len;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server_address, client_address;

    // Create the TCP socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // Check if the socket was created successfully
    if (server_socket < 0) {
        perror("Unable to create server socket");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to a specific IP address and port
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8080);
    memset(server_address.sin_zero, 0, sizeof(server_address.sin_zero));
    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Unable to bind server socket to IP address and port");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) < 0) {
        perror("Unable to listen for incoming connections");
        exit(EXIT_FAILURE);
    }

    printf("Server is running and listening for incoming connections...\n");

    while (1) {
        // Accept incoming connections
        addr_len = sizeof(client_address);
        client_socket = accept(server_socket, (struct sockaddr *) &client_address, (socklen_t *) &addr_len);

        if (client_socket < 0) {
            perror("Unable to accept incoming connection");
            exit(EXIT_FAILURE);
        }

        printf("Received incoming connection from %s:%d\n",
               inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        // Receive data from the client
        memset(buffer, 0, BUFFER_SIZE);
        if (recv(client_socket, buffer, BUFFER_SIZE, 0) < 0) {
            perror("Unable to receive data from client");
            exit(EXIT_FAILURE);
        }

        printf("Received data from client: %s\n", buffer);

        // Send data back to the client
        if (send(client_socket, "Hello from the server!", strlen("Hello from the server!"), 0) < 0) {
            perror("Unable to send data to client");
            exit(EXIT_FAILURE);
        }

        printf("Data sent back to client successfully\n");

        // Close the connection
        close(client_socket);
    }

    // Close the server socket
    close(server_socket);
    printf("Server has stopped listening for incoming connections\n");

    return 0;
}