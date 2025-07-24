//FormAI DATASET v1.0 Category: Client Server Application ; Style: accurate
// C Client Server Application
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void error(char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char const *argv[]) {
    int server_socket, new_socket;
    long valread;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    // Create a socket for the server
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        error("Socket creation failed");
    }

    // Set up the server options
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to the address and port
    if (bind(server_socket, (struct sockaddr *)&address, sizeof(address)) < 0) {
        error("Bind failed");
    }

    // Wait for clients to connect
    while (1) {
        if (listen(server_socket, 3) < 0) {
            error("Listen failed");
        }
        printf("Server is listening on port %d\n", PORT);

        // Accept the client connection
        if ((new_socket = accept(server_socket, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            error("Accept failed");
        }

        // Receive client message
        char buffer[BUFFER_SIZE] = {0};
        valread = read(new_socket, buffer, BUFFER_SIZE);

        // Print client message
        printf("Client: %s\n", buffer);

        // Send server message
        char *server_msg = "Hello, this is the server.";
        send(new_socket, server_msg, strlen(server_msg), 0);

        // Close the socket
        close(new_socket);
    }

    return 0;
}