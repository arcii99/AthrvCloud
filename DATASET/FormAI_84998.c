//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: multiplayer
// Building a HTTP Client example in multiplayer style

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 80
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    // Check for valid arguments
    if (argc != 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        return 1;
    }

    // Create socket
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        printf("Failed to create socket.\n");
        return 1;
    }

    // Create server address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    if (inet_pton(AF_INET, argv[1], &server_address.sin_addr) != 1) {
        printf("Invalid address.\n");
        return 1;
    }

    // Connect to server
    if (connect(client_socket, (struct sockaddr *) &server_address, sizeof(server_address)) != 0) {
        printf("Failed to connect.\n");
        return 1;
    }

    // Send HTTP GET request
    char request[BUF_SIZE];
    sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\nUser-Agent: Multiplayer-Client\r\n\r\n", argv[1]);
    send(client_socket, request, strlen(request), 0);

    // Receive response
    char response[BUF_SIZE];
    int response_length = recv(client_socket, response, BUF_SIZE, 0);
    if (response_length < 0) {
        printf("Failed to receive response.\n");
        return 1;
    }

    // Print response
    printf("%.*s\n", response_length, response);

    // Close socket
    close(client_socket);

    return 0;
}