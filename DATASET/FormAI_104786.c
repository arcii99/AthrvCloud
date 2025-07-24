//FormAI DATASET v1.0 Category: Networking ; Style: synchronous
/**
 * A simple echo server that communicates with clients using TCP/IP.
 * In synchronous or blocking I/O style.
 * The server will listen on a specified port for incoming connections from clients.
 * Once a client connects, the server will read client’s message, echo it back and close the connection.
 * 
 * Author: XYZ
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8888
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int server_socket, client_socket, bytes_received;
    struct sockaddr_in server_address, client_address;
    socklen_t sin_size = sizeof(struct sockaddr_in);
    char buffer[BUFFER_SIZE];

    // Create a socket to listen for incoming connections
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Error: Failed to create socket.");
        exit(EXIT_FAILURE);
    }

    // Configure the server address structure
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    memset(&(server_address.sin_zero), '\0', 8);

    // Bind the socket to the server address
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(struct sockaddr)) == -1) {
        perror("Error: Failed to bind socket.");
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(server_socket, 5) == -1) {
        perror("Error: Failed to listen for incoming connections.");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening for incoming connections on port %d...\n", PORT);

    while (1) { // Loop indefinitely to accept incoming client connections
        // Accept a client connection
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_address, &sin_size)) == -1) {
            perror("Error: Failed to accept incoming client connection.");
            continue;
        }

        printf("Client connection accepted.\n");

        // Receive and echo client's message
        while ((bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0)) > 0) {
            printf("Received %d bytes.\n", bytes_received);

            // Echo client's message back
            if (send(client_socket, buffer, bytes_received, 0) == -1) {
                perror("Error: Failed to send message back to client.");
                break;
            }
        }

        printf("Client connection closed.\n");

        // Close the client socket
        close(client_socket);
    }

    // Close the server socket
    close(server_socket);

    return 0;
}