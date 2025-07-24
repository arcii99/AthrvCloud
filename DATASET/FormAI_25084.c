//FormAI DATASET v1.0 Category: Networking ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_PORT 6969
#define MAX_CONNECTIONS 5
#define BUFFER_SIZE 1024

int main() {
    int server_socket, client_socket, client_address_size;
    struct sockaddr_in server_address, client_address;
    char buffer[BUFFER_SIZE];

    // Create a socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1) {
        perror("Error creating socket");
        exit(1);
    }

    // Prepare the server address struct
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(SERVER_PORT);

    // Bind the socket to the server address
    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
        perror("Error binding socket");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CONNECTIONS) == -1) {
        perror("Error listening on socket");
        exit(1);
    }

    printf("Server started on port %d\n", SERVER_PORT);

    while (1) {
        // Accept a client connection
        client_address_size = sizeof(client_address);
        if ((client_socket = accept(server_socket, (struct sockaddr *) &client_address, &client_address_size))
                == -1) {
            perror("Error accepting connection");
            exit(1);
        }

        printf("Client connected from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        while (1) {
            // Receive data from client
            if (recv(client_socket, buffer, BUFFER_SIZE, 0) == -1) {
                perror("Error receiving data");
                exit(1);
            }

            if (strcmp(buffer, "exit") == 0) {
                printf("Client disconnected\n");
                close(client_socket);
                break;
            }

            printf("Received data: %s\n", buffer);

            // Send data back to client
            if (send(client_socket, buffer, strlen(buffer), 0) == -1) {
                perror("Error sending data");
                exit(1);
            }
        }
    }

    close(server_socket);
    return 0;
}