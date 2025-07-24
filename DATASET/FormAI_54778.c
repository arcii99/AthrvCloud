//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: systematic
// This program demonstrates a simple server-client interaction using TCP/IP protocol.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFF_SIZE 1024

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    char buffer[BUFF_SIZE] = {0};
    int opt = 1, addrlen = sizeof(server_address);

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // Bind socket to port
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming clients
    if (listen(server_socket, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    // Accept incoming client connection
    if ((client_socket = accept(server_socket, (struct sockaddr *)&client_address, (socklen_t *)&addrlen)) < 0) {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }

    // Send welcome message to client
    char *welcomeMessage = "Connected to server. Send a message to the server:\n";
    send(client_socket, welcomeMessage, strlen(welcomeMessage), 0);

    // Loop to receive and send messages
    while (1) {
        memset(buffer, 0, BUFF_SIZE);

        // Receive message from client
        int readResult = read(client_socket, buffer, BUFF_SIZE);
        if (readResult == -1) {
            perror("read failed");
            break;
        }
        if (readResult == 0) {
            printf("Client disconnected\n");
            break;
        }

        printf("Received message from client: %s\n", buffer);

        // Send message back to client
        char response[BUFF_SIZE] = "Received your message. Thanks!";
        send(client_socket, response, strlen(response), 0);
    }

    // Close sockets
    close(client_socket);
    close(server_socket);

    return 0;
}