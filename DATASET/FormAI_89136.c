//FormAI DATASET v1.0 Category: Socket programming ; Style: systematic
/* 
 * This is a simple C socket programming example that creates a server and listens for incoming client connections.
 * When a client connects, the server sends a welcome message and waits for the client to send a message.
 * Once the client sends a message, the server echoes that message back to the client.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char **argv) {
    int server_socket, client_socket, ret;
    struct sockaddr_in server_addr, client_addr;
    char buffer[MAX_BUFFER_SIZE];

    // Create a socket for the server
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        printf("Failed to create server socket.\n");
        return EXIT_FAILURE;
    }

    // Bind the socket to the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);
    ret = bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr));
    if (ret < 0) {
        printf("Failed to bind server socket to address.\n");
        close(server_socket);
        return EXIT_FAILURE;
    }

    // Listen for incoming client connections
    ret = listen(server_socket, 10);
    if (ret < 0) {
        printf("Failed to listen for incoming client connections.\n");
        close(server_socket);
        return EXIT_FAILURE;
    }

    printf("Server listening on port 8080...\n");

    while (1) {
        // Accept incoming client connection
        memset(&client_addr, 0, sizeof(client_addr));
        client_socket = accept(server_socket, (struct sockaddr*)&client_addr, (socklen_t*)&client_addr);
        if (client_socket < 0) {
            printf("Failed to accept incoming client connection.\n");
            close(server_socket);
            return EXIT_FAILURE;
        }

        printf("Accepted new client connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Send welcome message to client
        strcpy(buffer, "Welcome to the server!\n");
        send(client_socket, buffer, strlen(buffer), 0);

        // Receive message from client and echo it back
        memset(buffer, 0, sizeof(buffer));
        ret = recv(client_socket, buffer, sizeof(buffer), 0);
        if (ret < 0) {
            printf("Failed to receive message from client.\n");
            close(client_socket);
            close(server_socket);
            return EXIT_FAILURE;
        } else if (ret == 0) {
            printf("Connection closed by client.\n");
            close(client_socket);
            continue;
        }

        printf("Received message from client: %s", buffer);

        ret = send(client_socket, buffer, strlen(buffer), 0);
        if (ret < 0) {
            printf("Failed to send message to client.\n");
            close(client_socket);
            continue;
        }
    }

    close(server_socket);
    return EXIT_SUCCESS;
}