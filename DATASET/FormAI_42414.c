//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    int port = 8080;

    int listening_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_length = sizeof(client_address);

    char buffer[BUFFER_SIZE];
    int bytes_received;

    // Create a listening socket
    if ((listening_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Error creating a listening socket");
        exit(1);
    }

    // Set the server address
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(port);

    // Bind the listening socket to the server address
    if (bind(listening_socket, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
        perror("Error binding the listening socket");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(listening_socket, 10) == -1) {
        perror("Error listening for incoming connections");
        exit(1);
    }

    printf("Proxy server listening on port %d\n", port);

    // Accept incoming connections
    while (1) {
        if ((client_socket = accept(listening_socket, (struct sockaddr *) &client_address, &client_address_length)) == -1) {
            perror("Error accepting incoming connection");
            continue;
        }

        printf("Accepted incoming connection from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        // Receive the request from the client
        if ((bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0)) == -1) {
            perror("Error receiving data from client");
            close(client_socket);
            continue;
        }

        printf("Received request from client:\n%s\n", buffer);

        // Create a new socket to connect to the real server
        int server_socket;
        if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
            perror("Error creating a socket to connect to the real server");
            close(client_socket);
            continue;
        }

        // Set the server address
        struct sockaddr_in server_address;
        memset(&server_address, 0, sizeof(server_address));
        server_address.sin_family = AF_INET;
        server_address.sin_port = htons(80); // Connect to port 80 on the real server
        server_address.sin_addr.s_addr = inet_addr("123.45.67.89"); // Replace with the IP address of the real server

        // Connect to the real server
        if (connect(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
            perror("Error connecting to the real server");
            close(client_socket);
            close(server_socket);
            continue;
        }

        printf("Connected to real server\n");

        // Forward the client request to the real server
        if (send(server_socket, buffer, bytes_received, 0) == -1) {
            perror("Error forwarding client request to real server");
            close(client_socket);
            close(server_socket);
            continue;
        }

        // Receive the response from the real server and forward it to the client
        while ((bytes_received = recv(server_socket, buffer, BUFFER_SIZE, 0)) > 0) {
            if (send(client_socket, buffer, bytes_received, 0) == -1) {
                perror("Error forwarding real server response to client");
                close(client_socket);
                close(server_socket);
                break;
            }
        }

        close(client_socket);
        close(server_socket);
    }

    return 0;
}