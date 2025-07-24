//FormAI DATASET v1.0 Category: Socket programming ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8000
#define MAX_MESSAGES 1000
#define MAX_CLIENTS 5 // Maximum of 5 clients can connect

int main() {
    int server_fd, client_fd[MAX_CLIENTS], max_fd, activity, i, valread;
    struct sockaddr_in address;
    fd_set readfds;
    char message[MAX_MESSAGES];

    // Create server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Bind server socket to port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connections
    int addrlen = sizeof(address);
    printf("Waiting for connections...\n");
    for (i = 0; i < MAX_CLIENTS; i++) {
        if ((client_fd[i] = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        printf("Client %d connected\n", i);
    }

    // Set up readfds for select()
    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO, &readfds); // Listen for input from user
    for (i = 0; i < MAX_CLIENTS; i++) {
        FD_SET(client_fd[i], &readfds); // Listen for incoming messages from clients
        if (client_fd[i] > max_fd) max_fd = client_fd[i]; // Keep track of highest file descriptor
    }

    while (1) {
        // Wait for activity on client sockets or user input
        activity = select(max_fd + 1, &readfds, NULL, NULL, NULL);

        if (activity < 0) {
            perror("select");
            exit(EXIT_FAILURE);
        }

        // Check user input
        if (FD_ISSET(STDIN_FILENO, &readfds)) {
            fgets(message, MAX_MESSAGES, stdin);
            printf("User: %s", message);
            // Send message to all clients
            for (i = 0; i < MAX_CLIENTS; i++) {
                if (client_fd[i] != 0) {
                    send(client_fd[i], message, strlen(message), 0);
                }
            }
        }

        // Check incoming messages from clients
        for (i = 0; i < MAX_CLIENTS; i++) {
            if (FD_ISSET(client_fd[i], &readfds)) {
                if ((valread = read(client_fd[i], message, MAX_MESSAGES)) == 0) {
                    printf("Client %d disconnected\n", i);
                    close(client_fd[i]);
                    client_fd[i] = 0;
                } else {
                    message[valread] = '\0';
                    printf("Client %d: %s", i, message);
                }
            }
        }

        // Reset readfds for next select() call
        FD_ZERO(&readfds);
        FD_SET(STDIN_FILENO, &readfds);
        for (i = 0; i < MAX_CLIENTS; i++) {
            if (client_fd[i] != 0) {
                FD_SET(client_fd[i], &readfds);
                if (client_fd[i] > max_fd) max_fd = client_fd[i];
            }
        }
    }

    return 0;
}