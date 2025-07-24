//FormAI DATASET v1.0 Category: Socket programming ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define MAX_CLIENTS 5
#define BUFFER_SIZE 1024

int main(int argc, char const *argv[]) {
    int server_fd, client_fd, read_val;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    // Create TCP socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed.");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Setsockopt failed.");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to PORT
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed.");
        exit(EXIT_FAILURE);
    }

    // Start listening on the socket
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("Listen failed.");
        exit(EXIT_FAILURE);
    }

    printf("Listening on PORT %d...\n", PORT);

    // Accept incoming connections and handle them
    while (1) {
        if ((client_fd = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accept failed.");
            exit(EXIT_FAILURE);
        }

        printf("New client connected: %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

        // Send welcome message
        char *welcome_msg = "Welcome to my unique C socket programming art!\n";
        send(client_fd, welcome_msg, strlen(welcome_msg), 0);

        // Request client's name
        char *name_request = "Please enter your name to continue: ";
        send(client_fd, name_request, strlen(name_request), 0);

        // Receive client's name
        read_val = read(client_fd, buffer, BUFFER_SIZE);
        printf("Client name: %s\n", buffer);

        // Send personalized message to client
        char personalized_msg[BUFFER_SIZE];
        sprintf(personalized_msg, "Hi %s, enjoy your stay!\n", buffer);
        send(client_fd, personalized_msg, strlen(personalized_msg), 0);

        // Close connection with client
        close(client_fd);
        printf("Client disconnected.\n");
    }

    return 0;
}