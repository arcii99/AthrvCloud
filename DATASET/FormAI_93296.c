//FormAI DATASET v1.0 Category: Networking ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define SERVER_PORT 8080
#define MAX_CONNECTIONS 5
#define BUFFER_SIZE 1024

int main() {
    int server_socket, client_socket, num_connections = 0;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_size = sizeof(client_address);

    char buffer[BUFFER_SIZE];

    // Create the socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Could not create socket");
        exit(EXIT_FAILURE);
    }

    // Set server address parameters
    bzero(&server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(SERVER_PORT);

    // Bind the socket to the server address
    if (bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        perror("Could not bind socket to server address");
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(server_socket, MAX_CONNECTIONS) < 0) {
        perror("Error while listening for incoming connections");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening for incoming connections on port %d...\n", SERVER_PORT);

    // Accept incoming connections
    while (1) {
        client_socket = accept(server_socket, (struct sockaddr*)&client_address, &client_address_size);
        if (client_socket < 0) {
            perror("Error while accepting incoming connection");
            continue;
        }

        printf("New connection accepted from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
        num_connections++;

        // Receive messages from the client
        while (1) {
            bzero(buffer, BUFFER_SIZE);
            ssize_t bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);

            if (bytes_received == 0) {
                printf("Connection closed by client %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
                close(client_socket);
                num_connections--;
                break;
            }
            else if (bytes_received < 0) {
                perror("Error while receiving message from client");
                break;
            }
            else {
                printf("Incoming message from %s:%d: %s", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port), buffer);
            }

            // Echo the message back to the client
            ssize_t bytes_sent = send(client_socket, buffer, strlen(buffer), 0);
            if (bytes_sent < 0) {
                perror("Error while sending message to client");
                break;
            }
        }

        if (num_connections == 0) {
            printf("No more connections. Exiting...\n");
            break;
        }
    }

    close(server_socket);
    return 0;
}