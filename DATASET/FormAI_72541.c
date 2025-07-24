//FormAI DATASET v1.0 Category: Socket programming ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int client_count = 0;
int clients[MAX_CLIENTS];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *handle_client(void *arg) {
    int client_sockfd = *(int *)arg;
    char buffer[BUFFER_SIZE];
    strcpy(buffer, "Connected to server!\n");
    write(client_sockfd, buffer, strlen(buffer));

    while (1) {
        bzero(buffer, BUFFER_SIZE);
        read(client_sockfd, buffer, BUFFER_SIZE);

        if (strcmp(buffer, "exit") == 0) {
            bzero(buffer, BUFFER_SIZE);
            strcpy(buffer, "Disconnected from server!\n");
            write(client_sockfd, buffer, strlen(buffer));
            break;
        }

        pthread_mutex_lock(&mutex);
        for (int i = 0; i < client_count; i++) {
            if (clients[i] != client_sockfd) {
                write(clients[i], buffer, strlen(buffer));
            }
        }
        pthread_mutex_unlock(&mutex);
    }

    pthread_mutex_lock(&mutex);
    for (int i = 0; i < client_count; i++) {
        if (clients[i] == client_sockfd) {
            while (i < client_count - 1) {
                clients[i] = clients[i+1];
                i++;
            }
            break;
        }
    }
    client_count--;
    close(client_sockfd);
    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    int server_sockfd, client_sockfd;
    struct sockaddr_in server_addr, client_addr;
    pthread_t thread_id;

    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sockfd < 0) {
        perror("socket() error");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(7777);

    if (bind(server_sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind() error");
        exit(EXIT_FAILURE);
    }

    if (listen(server_sockfd, MAX_CLIENTS) < 0) {
        perror("listen() error");
        exit(EXIT_FAILURE);
    }

    printf("Server started on port %d...\n", ntohs(server_addr.sin_port));

    while (1) {
        socklen_t client_len = sizeof(client_addr);
        client_sockfd = accept(server_sockfd, (struct sockaddr *)&client_addr, &client_len);

        if (client_sockfd < 0) {
            perror("accept() error");
            exit(EXIT_FAILURE);
        }

        if (client_count == MAX_CLIENTS) {
            printf("Server full! Connection rejected.\n");
            close(client_sockfd);
            continue;
        }

        pthread_mutex_lock(&mutex);
        clients[client_count++] = client_sockfd;
        pthread_mutex_unlock(&mutex);

        if (pthread_create(&thread_id, NULL, handle_client, (void *)&client_sockfd) < 0) {
            perror("pthread_create() error");
            exit(EXIT_FAILURE);
        }

        printf("New client connected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
    }

    close(server_sockfd);
    return 0;
}