//FormAI DATASET v1.0 Category: Chat server ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_CLIENTS 5
#define BUFFER_SIZE 256

void *client_handler(void *);

int main(int argc, char *argv[]) {
    int server_fd, client_fd, read_val;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len;
    char buffer[BUFFER_SIZE];
    pthread_t tid[MAX_CLIENTS];
    int opt = 1, i;

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set the socket options for reuse and allow multiple connections
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);

    // Bind the socket to the address
    if (bind(server_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening on the socket
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Accept incoming client connections
    while (1) {
        client_len = sizeof(client_addr);

        if ((client_fd = accept(server_fd, (struct sockaddr *) &client_addr, &client_len)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        printf("New client connected: %s\n", inet_ntoa(client_addr.sin_addr));

        // Start a new thread to handle the client
        for (i = 0; i < MAX_CLIENTS; i++) {
            if (tid[i] == 0) {
                if (pthread_create(&tid[i], NULL, client_handler, (void *) &client_fd) < 0) {
                    perror("pthread_create");
                    exit(EXIT_FAILURE);
                }
                break;
            }
        }

        // If all threads are taken, let the client know
        if (i == MAX_CLIENTS) {
            strcpy(buffer, "Server is full, please try again later.");
            if (write(client_fd, buffer, strlen(buffer)) < 0) {
                perror("write");
            }
            close(client_fd);
        }
    }

    return 0;
}

// Client handler function
void *client_handler(void *client_fd_ptr) {
    int client_fd = *((int *) client_fd_ptr);
    int read_val;
    char buffer[BUFFER_SIZE];

    // Read data from the client
    while ((read_val = read(client_fd, buffer, BUFFER_SIZE)) > 0) {
        printf("Received message: %s\n", buffer);

        // Convert message to uppercase
        for (int i = 0; i < read_val; i++) {
            if (buffer[i] >= 97 && buffer[i] <= 122) {
                buffer[i] -= 32;
            }
        }

        // Send the modified message back to the client
        if (write(client_fd, buffer, strlen(buffer)) < 0) {
            perror("write");
            break;
        }
    }

    // Handle any errors during the read/write operations
    if (read_val == 0) {
        puts("Client disconnected");
    } else if (read_val == -1) {
        perror("read");
    }

    close(client_fd);
    pthread_exit(NULL);
}