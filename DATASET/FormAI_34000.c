//FormAI DATASET v1.0 Category: Networking ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define DEFAULT_PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int client_socket, recvd_bytes;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    memset(&server_addr, 0, sizeof(server_addr));

    // Create socket
    if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        fprintf(stderr, "Error creating socket\n");
        exit(EXIT_FAILURE);
    }

    // Set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(DEFAULT_PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Try to connect to server
    if (connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        fprintf(stderr, "Error connecting to server\n");
        exit(EXIT_FAILURE);
    }

    // Send message to server
    char *message = "Hello from the client!";
    if (send(client_socket, message, strlen(message), 0) < 0) {
        fprintf(stderr, "Error sending message to server\n");
        exit(EXIT_FAILURE);
    }

    // Receive message from server
    memset(buffer, 0, sizeof(buffer));
    if ((recvd_bytes = recv(client_socket, buffer, BUFFER_SIZE - 1, 0)) < 0) {
        fprintf(stderr, "Error receiving message from server\n");
        exit(EXIT_FAILURE);
    }

    // Print received message
    printf("Server's message: %s\n", buffer);

    // Close socket
    close(client_socket);

    return EXIT_SUCCESS;
}