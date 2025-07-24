//FormAI DATASET v1.0 Category: Chat server ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *welcome_message = "Hello and welcome to Retro Chat!";

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                &opt, sizeof(opt))) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_fd, (struct sockaddr *)&address,
            sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming requests
    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connection
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                (socklen_t*)&addrlen)) < 0) {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }

    // Send welcome message to new client
    send(new_socket, welcome_message, strlen(welcome_message), 0);

    // Handle incoming messages
    while (1) {
        memset(buffer, 0, sizeof(buffer));
        valread = read(new_socket, buffer, 1024);

        // Connection closed
        if (valread == 0) {
            printf("Client disconnected\n");
            break;
        }

        // Print incoming message
        printf("Client: %s", buffer);

        // Prepare outgoing message
        char *outgoing_message = malloc(strlen(buffer) + 14);
        sprintf(outgoing_message, "You said: %s", buffer);

        // Send outgoing message to client
        send(new_socket, outgoing_message, strlen(outgoing_message), 0);
        free(outgoing_message);
    }

    close(server_fd);
    return 0;
}