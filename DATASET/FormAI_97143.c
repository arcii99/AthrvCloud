//FormAI DATASET v1.0 Category: Chat server ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_MSG_LENGTH 1024
#define PORT 8080

char *get_response(char *msg);

int main() {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[MAX_MSG_LENGTH] = {0};
    char *response;

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind socket to address
    if (bind(server_fd, (struct sockaddr *) &address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    printf("Listening on port %d\n", PORT);

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connection
    if ((new_socket = accept(server_fd, (struct sockaddr *) &address, (socklen_t *) &addrlen)) < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    printf("Client connected\n");

    // Read incoming message
    while ((valread = read(new_socket, buffer, MAX_MSG_LENGTH)) > 0) {
        printf("Received message: %s\n", buffer);
        // Get response to message
        response = get_response(buffer);
        // Send response to client
        send(new_socket, response, strlen(response), 0);
        memset(buffer, 0, MAX_MSG_LENGTH);
        free(response);
    }

    if (valread == 0) {
        printf("Client disconnected\n");
    } else {
        perror("read error");
    }

    close(new_socket);
    close(server_fd);
    return 0;
}

// Function to generate response to message
char *get_response(char *msg) {
    char *response = calloc(MAX_MSG_LENGTH, sizeof(char));
    char *lower_msg = calloc(strlen(msg) + 1, sizeof(char));
    int i;

    // Convert message to lowercase
    for (i = 0; i < strlen(msg); i++) {
        lower_msg[i] = tolower(msg[i]);
    }

    if (strstr(lower_msg, "hello") || strstr(lower_msg, "hi")) {
        strcpy(response, "Hi there!");
    } else if (strstr(lower_msg, "how are you")) {
        strcpy(response, "I'm doing well, thank you.");
    } else if (strstr(lower_msg, "bye")) {
        strcpy(response, "Goodbye!");
    } else {
        strcpy(response, "I'm sorry, I didn't understand that.");
    }

    free(lower_msg);
    return response;
}