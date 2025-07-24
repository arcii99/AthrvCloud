//FormAI DATASET v1.0 Category: Socket programming ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

#define MAX_CLIENTS 100
#define BUFFER_SIZE 2048

int clients[MAX_CLIENTS];
int num_clients = 0;
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

void *handle_client(void *arg) {
    int client_fd = *((int*) arg);
    char buffer[BUFFER_SIZE];
    char *response;
    memset(buffer, 0, BUFFER_SIZE);
    recv(client_fd, buffer, BUFFER_SIZE, 0);
    response = "Welcome to the post-apocalyptic server!\n";
    send(client_fd, response, strlen(response), 0);

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int recv_size = recv(client_fd, buffer, BUFFER_SIZE, 0);
        if (recv_size == 0) {
            pthread_mutex_lock(&clients_mutex);
            for (int i = 0; i < num_clients; i++) {
                if (clients[i] == client_fd) {
                    clients[i] = -1;
                }
            }
            pthread_mutex_unlock(&clients_mutex);
            break;
        }
        response = "The world is in ruins. The only way to survive is to scavenge for resources and protect your shelter.\n";
        send(client_fd, response, strlen(response), 0);
    }
    close(client_fd);
    return NULL;
}

int main(int argc, char **argv) {
    int server_fd, client_fd;
    struct sockaddr_in server_address, client_address;
    int opt = 1;
    socklen_t client_len;

    memset(clients, -1, sizeof(clients));

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8080);

    bind(server_fd, (struct sockaddr *) &server_address, sizeof(server_address));
    listen(server_fd, 5);

    printf("Server started on port 8080.\n");

    while (1) {
        client_fd = accept(server_fd, (struct sockaddr *) &client_address, &client_len);
        pthread_mutex_lock(&clients_mutex);
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (clients[i] == -1) {
                clients[i] = client_fd;
                num_clients++;
                pthread_t client_thread;
                pthread_create(&client_thread, NULL, handle_client, (void*) &client_fd);
                pthread_detach(client_thread);
                break;
            }
        }
        pthread_mutex_unlock(&clients_mutex);
    }

    return 0;
}