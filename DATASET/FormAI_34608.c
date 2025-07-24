//FormAI DATASET v1.0 Category: Chat server ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char welcome_message[] = "Welcome to the Retro Chat Server!\n\n";

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options to allow reuse of address and port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Set server address and port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to the address and port
    if (bind(server_fd, (struct sockaddr *) &address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Retro Chat Server initialized and listening on port %d...\n", PORT);

    // Accept incoming connections
    if ((new_socket = accept(server_fd, (struct sockaddr *) &address, (socklen_t *) &addrlen)) < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    // Send the welcome message to the client
    send(new_socket, welcome_message, strlen(welcome_message), 0);

    while (1) {
        // Clear the buffer
        memset(buffer, 0, sizeof(buffer));

        // Read from the socket
        valread = read(new_socket, buffer, 1024);

        if (valread == 0) {
            printf("Client disconnected\n");
            break;
        } else {
            printf("Client: %s", buffer);
        }

        // Send a response
        char response[1024];
        sprintf(response, "Server: %s", buffer);
        send(new_socket, response, strlen(response), 0);
    }

    // Close the socket
    close(new_socket);

    return 0;
}