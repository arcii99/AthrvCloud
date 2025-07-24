//FormAI DATASET v1.0 Category: Networking ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 5

int clients[MAX_CLIENTS];

void *handle_client(void *arg) {
    int client_fd = *(int*)arg;
    char buffer[1024] = {0};
    while (read(client_fd, buffer, 1024)) {
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (clients[i] && clients[i] != client_fd) {
                send(clients[i], buffer, strlen(buffer), 0);
            }
        }
        memset(buffer, 0, sizeof(buffer));
    }
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i] == client_fd) {
            clients[i] = 0;
        }
    }
    printf("Client disconnected.\n");
    close(client_fd);
    return NULL;
}

int main(int argc, char const *argv[]) {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    memset(clients, 0, sizeof(clients));
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }
    printf("Listening on port %d...\n", PORT);
    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }
        int idx = -1;
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (clients[i] == 0) {
                clients[i] = new_socket;
                idx = i;
                break;
            }
        }
        printf("New client connected. (id=%d)\n", idx);
        pthread_t tid;
        if (pthread_create(&tid, NULL, handle_client, &new_socket) != 0) {
            perror("pthread_create failed");
            exit(EXIT_FAILURE);
        }
    }
    return 0;
}