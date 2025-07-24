//FormAI DATASET v1.0 Category: Networking ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

void *handle_client(void *arg);

int main(int argc, char const *argv[]) {
    int server_fd, client_fd;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_len = sizeof(client_address);

    // Create server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket error");
        exit(EXIT_FAILURE);
    }

    // Bind to address and port
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8080);

    if (bind(server_fd, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("Bind error");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, MAX_CLIENTS) == -1) {
        perror("Listen error");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port 8080\n");

    // Accept incoming connections and create threads to handle clients
    while (1) {
        if ((client_fd = accept(server_fd, (struct sockaddr *)&client_address, &client_address_len)) == -1) {
            perror("Accept error");
            continue;
        }

        pthread_t client_thread;

        if (pthread_create(&client_thread, NULL, handle_client, (void *)&client_fd) != 0) {
            perror("Thread creation error");

            if (close(client_fd) == -1) {
                perror("Close error");
            }

            continue;
        }

        printf("Created thread for client %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
    }

    return 0;
}

void *handle_client(void *arg) {
    int client_fd = *(int *)arg;

    char buffer[BUFFER_SIZE];
    ssize_t num_bytes_read;

    while ((num_bytes_read = read(client_fd, buffer, BUFFER_SIZE)) > 0) {
        if (write(client_fd, buffer, num_bytes_read) == -1) {
            perror("Write error");
            break;
        }

        printf("Received %zd bytes from client %d\n", num_bytes_read, client_fd);
    }

    if (num_bytes_read == -1) {
        perror("Read error");
    }

    if (close(client_fd) == -1) {
        perror("Close error");
    }

    printf("Closed connection for client %d\n", client_fd);

    pthread_exit(NULL);
}