//FormAI DATASET v1.0 Category: Socket programming ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 9999

void *client_handler(void *arg);

int main() {
    int server_fd, client_fd;
    struct sockaddr_in address;
    pthread_t tid;

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind socket
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }
    printf("Server started and listening on port %d\n", PORT);

    // Handle clients
    while (1) {
        if ((client_fd = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&address)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }
        pthread_create(&tid, NULL, client_handler, (void *)&client_fd);
    }
    return 0;
}

void *client_handler(void *arg) {
    char buffer[1024] = {0};
    int client_fd = *(int *)arg;
    ssize_t valread;

    // Read client message
    if ((valread = read(client_fd, buffer, 1024)) <= 0) {
        perror("Read failed");
        exit(EXIT_FAILURE);
    }
    printf("Client message: %s\n", buffer);

    // Send response to client
    char *response = "Hello from server";
    if (send(client_fd, response, strlen(response), 0) < 0) {
        perror("Send failed");
        exit(EXIT_FAILURE);
    }

    // Close socket
    close(client_fd);
    pthread_exit(NULL);
}