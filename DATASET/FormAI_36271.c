//FormAI DATASET v1.0 Category: Client Server Application ; Style: surprised
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
int client_socket[MAX_CLIENTS];
pthread_mutex_t mutex_clients = PTHREAD_MUTEX_INITIALIZER;

void send_all(char* message, int sender_socket) {
    pthread_mutex_lock(&mutex_clients);
    for(int i=0; i<MAX_CLIENTS; i++) {
        if(client_socket[i] != 0 && client_socket[i] != sender_socket) {
            send(client_socket[i], message, strlen(message), 0);
        }
    }
    pthread_mutex_unlock(&mutex_clients);
}

void* handle_client(void* arg) {
    char buffer[BUFFER_SIZE];
    int client_socket = *((int*) arg);
    recv(client_socket, buffer, BUFFER_SIZE, 0);
    printf("Received message from client %d: %s\n", client_socket, buffer);
    send_all(buffer, client_socket);
    close(client_socket);
    pthread_exit(NULL);
}

int main(int argc, char** argv) {
    int server_socket, client_socket_addr;
    struct sockaddr_in server_addr, client_addr;
    pthread_t client_thread[MAX_CLIENTS];

    bzero(&server_addr, sizeof(server_addr));

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(server_socket == -1) {
        printf("Error creating socket\n");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(9000);

    if(bind(server_socket, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
        printf("Error binding server socket\n");
        exit(EXIT_FAILURE);
    }

    listen(server_socket, 5);

    while(1) {
        if(client_count >= MAX_CLIENTS) {
            printf("Cannot accept more clients\n");
            continue;
        }

        int client_addr_len = sizeof(client_addr);
        client_socket_addr = accept(server_socket, (struct sockaddr*) &client_addr, &client_addr_len);
        if(client_socket_addr < 0) {
            printf("Error accepting client\n");
            continue;
        }

        pthread_mutex_lock(&mutex_clients);
        client_socket[client_count++] = client_socket_addr;
        pthread_mutex_unlock(&mutex_clients);

        int thread_index = client_count - 1;
        int ret = pthread_create(&client_thread[thread_index], NULL, handle_client, &client_socket[thread_index]);
        if(ret) {
            printf("Error creating thread\n");
            exit(EXIT_FAILURE);
        }
    }

    close(server_socket);
    return 0;
}