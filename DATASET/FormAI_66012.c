//FormAI DATASET v1.0 Category: Socket programming ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define MAX_MSG_LENGTH 200

void *client_handler(void *);

int main(int argc, char *argv[]) {
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    pthread_t thread_id;
    int opt = 1;

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // Bind socket to port
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);

    if (bind(server_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Waiting for clients ...\n");

    while (1) {
        socklen_t addr_len = sizeof(client_addr);

        // Accept incoming connection
        if ((client_fd = accept(server_fd, (struct sockaddr *) &client_addr, &addr_len)) < 0) {
            perror("Accept failed");
            continue;
        }

        // Create a new thread for client communication
        if (pthread_create(&thread_id, NULL, client_handler, (void *) &client_fd) < 0) {
            perror("Thread creation failed");
            continue;
        }
    }

    return 0;
}

void *client_handler(void *arg) {
    int client_fd = *(int *) arg;
    char incoming_msg[MAX_MSG_LENGTH] = {0};
    char outgoing_msg[MAX_MSG_LENGTH] = {0};

    printf("New client connected\n");

    while (1) {
        // Receive message from client
        if (recv(client_fd, incoming_msg, MAX_MSG_LENGTH, 0) == 0) {
            printf("Client disconnected\n");
            break;
        }

        printf("Client: %s\n", incoming_msg);

        // Prepare outgoing message
        snprintf(outgoing_msg, MAX_MSG_LENGTH, "Server: %s", incoming_msg);

        // Send message to client
        if (send(client_fd, outgoing_msg, strlen(outgoing_msg), 0) < 0) {
            perror("Send failed");
            break;
        }
    }

    // Close client connection
    close(client_fd);

    return NULL;
}