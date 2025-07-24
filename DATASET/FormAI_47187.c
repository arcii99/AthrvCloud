//FormAI DATASET v1.0 Category: Socket programming ; Style: intelligent
// This program creates a client-server architecture using C Sockets
// The client sends a message to the server and the server responds with a welcome message
// The server can handle multiple clients at once using fork system call
// Created by [Your Name]

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <netinet/in.h>

#define PORT 8080

void handle_client(int);

int main(int argc, char const *argv[]) {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Attaching socket to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to the port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen to the incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Listening on port %d...\n", PORT);

    while (1) {
        // Accept the incoming connections
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }
        printf("New client connected from %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

        // Create a new process for the incoming connection
        pid_t pid = fork();
        if (pid == -1) {
            perror("fork failed");
            exit(EXIT_FAILURE);
        }

        if (pid == 0) { // Child process
            close(server_fd);
            handle_client(new_socket);
            exit(EXIT_SUCCESS);
        } else { // Parent process
            close(new_socket);
        }
    }
    return 0;
}

// Handle each client connection in a separate function
void handle_client(int socket) {
    char buffer[1024] = {0};
    char *welcome_msg = "Welcome to the server!";

    // Receive message from client
    if (recv(socket, buffer, 1024, 0) < 0) {
        perror("recv failed");
        exit(EXIT_FAILURE);
    }
    printf("Client message: %s\n", buffer);

    // Send welcome message to client
    if (send(socket, welcome_msg, strlen(welcome_msg), 0) < 0) {
        perror("send failed");
        exit(EXIT_FAILURE);
    }
    printf("Welcome message sent to client\n");
}