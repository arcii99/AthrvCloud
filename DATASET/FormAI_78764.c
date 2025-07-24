//FormAI DATASET v1.0 Category: Networking ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int server_socket, connection_socket;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE] = {0};
    int addrlen = sizeof(server_addr);

    // Create a socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to a port
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Socket binding failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 3) < 0) {
        perror("Listening failed");
        exit(EXIT_FAILURE);
    }

    printf("\nWaiting for connection...\n");

    // Accept an incoming connection
    if ((connection_socket = accept(server_socket, (struct sockaddr *)&client_addr, (socklen_t *)&addrlen)) < 0) {
        perror("Accepting connection failed");
        exit(EXIT_FAILURE);
    }

    printf("Connected to %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    // Send and receive data
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);

        // Receive data from the client
        int bytes_received = recv(connection_socket, buffer, BUFFER_SIZE, 0);

        if (bytes_received < 0) {
            perror("Receiving data failed");
            exit(EXIT_FAILURE);
        }

        printf("Received data from client: %s", buffer);

        // Send data to the client
        char *response = "Hello, client!\n";
        send(connection_socket, response, strlen(response), 0);
    }

    return 0;
}