//FormAI DATASET v1.0 Category: Chat server ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 10

int client_sockets[MAX_CLIENTS];

void *handle_client(void *arg) {
    int *client_socket = (int *) arg;
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));
    while (1) {
        if (recv(*client_socket, buffer, sizeof(buffer), 0) <= 0) {
            break;
        }
        printf("Received: %s", buffer);
        memset(buffer, 0, sizeof(buffer));
    }
    close(*client_socket);
    return NULL;
}

int main() {
    int server_socket;
    struct sockaddr_in server_addr;
    int port = 3000;
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        printf("Failed to create socket\n");
        exit(1);
    }
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);
    if (bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        printf("Failed to bind socket\n");
        exit(1);
    }
    if (listen(server_socket, 5) < 0) {
        printf("Failed to listen on socket\n");
        exit(1);
    }
    pthread_t threads[MAX_CLIENTS];
    int i = 0;
    while (1) {
        if (i >= MAX_CLIENTS) {
            break;
        }
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_socket = accept(server_socket, (struct sockaddr *) &client_addr, &client_addr_len);
        if (client_socket < 0) {
            printf("Failed to accept client connection\n");
            continue;
        }
        client_sockets[i] = client_socket;
        printf("Accepted client connection\n");
        pthread_create(&threads[i], NULL, handle_client, &client_sockets[i]);
        i++;
    }
    for (i = 0; i < MAX_CLIENTS; i++) {
        if (client_sockets[i]) {
            close(client_sockets[i]);
        }
    }
    close(server_socket);
    return 0;
}