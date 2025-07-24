//FormAI DATASET v1.0 Category: Simple Web Server ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>
#include <unistd.h>

#define DEFAULT_PORT 8080 // Default port number
#define BUFFER_SIZE 1024 // Maximum buffer size
#define MAX_CLIENTS 10 // Maximum number of clients that can connect simultaneously

// Function prototype
void *handle_client(void *arg);

int main(int argc, char *argv[]) {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE];
    pthread_t tid[MAX_CLIENTS];

    // Create server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set server socket options
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Set server address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(DEFAULT_PORT);

    // Bind server socket to address
    if (bind(server_fd, (struct sockaddr *) &address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 10) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server started on port %d...\n", DEFAULT_PORT);

    int i = 0;
    while (1) {
        // Accept new connection
        if ((new_socket = accept(server_fd, (struct sockaddr *) &address, (socklen_t *) &addrlen)) < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        // Create new thread to handle client request
        if (pthread_create(&tid[i], NULL, handle_client, (void *) &new_socket) != 0) {
            perror("pthread_create failed");
            exit(EXIT_FAILURE);
        }

        // Limit number of simultaneous clients
        if (i >= MAX_CLIENTS) {
            i = 0;
            while (tid[i] != 0) {
                i++;
            }
            pthread_join(tid[i], NULL);
        }

        i++;
    }

    return EXIT_SUCCESS;
}

void *handle_client(void *arg) {
    int client_fd = *(int *) arg;
    char buffer[BUFFER_SIZE] = {0};
    char *response;
    int bytes_read;

    printf("New client connected...\n");

    // Read client request
    bytes_read = read(client_fd, buffer, BUFFER_SIZE);
    if (bytes_read < 0) {
        perror("read failed");
        exit(EXIT_FAILURE);
    }

    // Generate response
    response = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<html><body><h1>Hello World!</h1></body></html>\r\n";

    // Send response to client
    if (write(client_fd, response, strlen(response)) < 0) {
        perror("write failed");
        exit(EXIT_FAILURE);
    }

    // Close client socket
    close(client_fd);
    printf("Client disconnected...\n");

    pthread_exit(NULL);
}