//FormAI DATASET v1.0 Category: Chat server ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 100

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int clients[MAX_CLIENTS];
int total_clients = 0;

void *handle_client(void *client_fd_ptr) {
    int client_fd = *(int *)client_fd_ptr;
    char username[20];
    char buffer[256];
    memset(buffer, 0, 256);

    // Get username from client
    if (recv(client_fd, username, sizeof(username), 0) <= 0) {
        perror("recv");
        pthread_exit(NULL);
    }

    printf("%s has joined the chat.\n", username);

    while (1) {
        memset(buffer, 0, 256);

        // Receive message from client
        if (recv(client_fd, buffer, sizeof(buffer), 0) <= 0) {
            perror("recv");
            break;
        }

        // Send message to all clients
        pthread_mutex_lock(&mutex);
        for (int i = 0; i < total_clients; i++) {
            if (clients[i] != client_fd) {
                if (send(clients[i], buffer, strlen(buffer), 0) == -1) {
                    perror("send");
                    break;
                }
            }
        }
        pthread_mutex_unlock(&mutex);
    }

    // Remove client from array and close connection
    pthread_mutex_lock(&mutex);
    for (int i = 0; i < total_clients; i++) {
        if (clients[i] == client_fd) {
            printf("%s has left the chat.\n", username);
            memmove(clients + i, clients + i + 1,
                    (total_clients - i - 1) * sizeof(int));
            total_clients--;
            break;
        }
    }
    pthread_mutex_unlock(&mutex);
    close(client_fd);
    pthread_exit(NULL);
}

int main() {
    int server_fd, client_fd;
    struct sockaddr_in address;

    // Create server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        return 1;
    }

    // Set socket address parameters
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind socket to address and listen for connections
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) == -1) {
        perror("bind");
        return 1;
    }

    if (listen(server_fd, 5) == -1) {
        perror("listen");
        return 1;
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        // Accept incoming connection
        if ((client_fd = accept(server_fd, NULL, NULL)) == -1) {
            perror("accept");
            continue;
        }

        // Add client to array
        pthread_mutex_lock(&mutex);
        clients[total_clients++] = client_fd;
        pthread_mutex_unlock(&mutex);

        // Create thread to handle client
        pthread_t thread;
        if (pthread_create(&thread, NULL, handle_client, &client_fd) == -1) {
            perror("pthread_create");
            return 1;
        }
    }

    close(server_fd);
    return 0;
}