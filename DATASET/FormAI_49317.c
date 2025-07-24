//FormAI DATASET v1.0 Category: Networking ; Style: Dennis Ritchie
// This program demonstrates a simple client-server networking using TCP protocol.
// Written by Dennis Ritchie.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int client_socket, sockfd, status;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server_address, client_address;

    // Create the client socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        printf("Error: Could not create the socket.\n");
        exit(1);
    }

    // Initialize the client address
    memset(&client_address, 0, sizeof(client_address));
    client_address.sin_family = AF_INET;
    client_address.sin_addr.s_addr = INADDR_ANY;
    client_address.sin_port = htons(0);

    // Bind the socket to a local address and port
    status = bind(client_socket, (const struct sockaddr *)&client_address, sizeof(client_address));
    if (status < 0) {
        printf("Error: Could not bind the socket.\n");
        exit(1);
    }

    // Initialize the server address
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_address.sin_port = htons(PORT);

    // Connect to the server
    sockfd = connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address));
    if (sockfd < 0) {
        printf("Error: Could not connect to the server.\n");
        exit(1);
    }

    // Send a message to the server
    printf("Enter a message to send to the server: ");
    fgets(buffer, BUFFER_SIZE, stdin);
    send(client_socket, buffer, strlen(buffer), 0);

    // Receive a message from the server
    memset(buffer, 0, sizeof(buffer));
    recv(client_socket, buffer, BUFFER_SIZE, 0);
    printf("Message from the server: %s\n", buffer);

    // Close the socket
    close(client_socket);

    return 0;
}