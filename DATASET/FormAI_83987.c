//FormAI DATASET v1.0 Category: Chat server ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define PORT 8080
#define MAX_PENDING 10
#define MAX_MSG_LENGTH 1024
#define MAX_CLIENTS 10

int client_count = 0;
int client_sockets[MAX_CLIENTS];
pthread_mutex_t client_mutex = PTHREAD_MUTEX_INITIALIZER;

void *handle_client(void *arg) {
    int socket = *(int *) arg;
    char buffer[MAX_MSG_LENGTH];
    while (1) {
        memset(buffer, 0, MAX_MSG_LENGTH);
        if (recv(socket, buffer, MAX_MSG_LENGTH, 0) <= 0) {
            pthread_mutex_lock(&client_mutex);
            for (int i = 0; i < client_count; i++) {
                if (client_sockets[i] == socket) {
                    for (int j = i; j < client_count - 1; j++) {
                        client_sockets[j] = client_sockets[j + 1];
                    }
                    client_count--;
                    break;
                }
            }
            pthread_mutex_unlock(&client_mutex);
            printf("Client %d disconnected.\n", socket);
            close(socket);
            pthread_exit(NULL);
        }
        printf("Received from client %d: %s", socket, buffer);
        pthread_mutex_lock(&client_mutex);
        for (int i = 0; i < client_count; i++) {
            if (client_sockets[i] != socket) {
                send(client_sockets[i], buffer, strlen(buffer), 0);
            }
        }
        pthread_mutex_unlock(&client_mutex);
    }
}

int main() {
    int server_socket, client_socket, addr_len;
    struct sockaddr_in server_address, client_address;
    pthread_t thread_id;
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);
    if (bind(server_socket, (const struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Failed to bind socket");
        exit(EXIT_FAILURE);
    }
    if (listen(server_socket, MAX_PENDING) < 0) {
        perror("Failed to listen on socket");
        exit(EXIT_FAILURE);
    }
    printf("Server listening on port %d...\n", PORT);
    while (1) {
        addr_len = sizeof(client_address);
        if ((client_socket = accept(server_socket, (struct sockaddr *) &client_address, (socklen_t *) &addr_len)) < 0) {
            perror("Failed to accept connection");
            exit(EXIT_FAILURE);
        }
        printf("Client %d connected.\n", client_socket);
        pthread_mutex_lock(&client_mutex);
        client_sockets[client_count++] = client_socket;
        pthread_mutex_unlock(&client_mutex);
        pthread_create(&thread_id, NULL, handle_client, (void *) &client_socket);
    }
    return 0;
}