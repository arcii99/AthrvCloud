//FormAI DATASET v1.0 Category: Client Server Application ; Style: authentic
// This is a simple client-server program that allows the client to send messages to the server
// and the server to echo the message back to the client

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int server_socket, client_socket, bytes_received;
    struct sockaddr_in server_address, client_address;
    char buffer[BUFFER_SIZE];

    // Creating a TCP socket for the server
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Error creating socket");
        return EXIT_FAILURE;
    }

    // Binding the socket to a specific IP address and port
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(PORT);
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("Error binding socket");
        close(server_socket);
        return EXIT_FAILURE;
    }

    // Listening for incoming connections
    if (listen(server_socket, 5) == -1) {
        perror("Error listening for incoming connections");
        close(server_socket);
        return EXIT_FAILURE;
    }

    printf("Server started listening on port %d ...\n", PORT);

    // Accepting incoming connections
    while (1) {
        socklen_t client_address_length = sizeof(client_address);
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_length);
        if (client_socket == -1) {
            perror("Error accepting incoming connection");
            close(server_socket);
            return EXIT_FAILURE;
        }

        printf("Accepted incoming connection from %s:%d ...\n",
               inet_ntoa(client_address.sin_addr),
               ntohs(client_address.sin_port));

        // Reading data from client and echoing it back
        while ((bytes_received = read(client_socket, buffer, BUFFER_SIZE)) > 0) {
            buffer[bytes_received] = '\0';
            printf("Received message from client: %s", buffer);
            write(client_socket, buffer, strlen(buffer));
        }

        if (bytes_received == -1) {
            perror("Error reading from client socket");
            close(client_socket);
            continue;
        }

        printf("Closing connection with %s:%d ...\n",
               inet_ntoa(client_address.sin_addr),
               ntohs(client_address.sin_port));

        // Closing the connection with the client
        close(client_socket);
    }

    // Closing the server socket
    close(server_socket);

    return EXIT_SUCCESS;
}