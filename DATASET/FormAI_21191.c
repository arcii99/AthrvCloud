//FormAI DATASET v1.0 Category: Chat server ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

typedef struct {
    int socket_fd;
    struct sockaddr_in client_addr;
} client_data;

client_data clients[MAX_CLIENTS];
int num_clients = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *handle_client(void *arg);

int main() {
    int server_fd, client_fd;
    struct sockaddr_in server_addr;
    pthread_t thread_id;

    // create server socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("socket");
        exit(-1);
    }

    // set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // bind server socket to address
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(-1);
    }

    // listen for client connections
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("listen");
        exit(-1);
    }

    while (1) {
        // accept new client connection
        client_fd = accept(server_fd, NULL, NULL);
        if (client_fd < 0) {
            perror("accept");
            exit(-1);
        }

        // add client data to array
        pthread_mutex_lock(&mutex);
        if (num_clients < MAX_CLIENTS) {
            clients[num_clients].socket_fd = client_fd;
            clients[num_clients].client_addr = server_addr;
            num_clients++;

            // create new thread to handle client messages
            if (pthread_create(&thread_id, NULL, handle_client, &client_fd) != 0) {
                perror("pthread_create");
                exit(-1);
            }
        }
        else {
            printf("Too many clients connected!\n");
            close(client_fd);
        }
        pthread_mutex_unlock(&mutex);
    }

    return 0;
}

void *handle_client(void *arg) {
    int client_fd = *(int *)arg;
    char buffer[BUFFER_SIZE];
    ssize_t num_bytes;

    while (1) {
        // read incoming message from client
        num_bytes = read(client_fd, buffer, BUFFER_SIZE);
        if (num_bytes < 0) {
            perror("read");
            exit(-1);
        }
        else if (num_bytes == 0) {
            // client disconnected
            close(client_fd);
            pthread_exit(NULL);
        }

        // broadcast message to all other clients
        pthread_mutex_lock(&mutex);
        for (int i = 0; i < num_clients; i++) {
            if (clients[i].socket_fd != client_fd) {
                if (write(clients[i].socket_fd, buffer, num_bytes) < num_bytes) {
                    perror("write");
                    exit(-1);
                }
            }
        }
        pthread_mutex_unlock(&mutex);
    }
}