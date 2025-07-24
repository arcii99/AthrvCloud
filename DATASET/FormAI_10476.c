//FormAI DATASET v1.0 Category: Chat server ; Style: secure
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_CLIENTS 100
#define BUFFER_SIZE 1024

int client_count = 0;
int clients[MAX_CLIENTS];

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *handle_client(void *arg) {
    int client_socket = *(int *)arg;
    char message[BUFFER_SIZE];

    while (1) {
        if (recv(client_socket, message, BUFFER_SIZE, 0) > 0) {
            pthread_mutex_lock(&mutex);

            // broadcast message to all clients
            for (int i = 0; i < client_count; i++) {
                if (clients[i] != client_socket) {
                    send(clients[i], message, strlen(message), 0);
                }
            }

            pthread_mutex_unlock(&mutex);
        }
    }

    return NULL;
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    pthread_t thread;

    // create server socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        return 1;
    }

    // set server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(8080);

    // bind socket to address
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("bind failed");
        return 1;
    }

    // listen for connections
    if (listen(server_socket, 5) < 0) {
        perror("listen failed");
        return 1;
    }

    while (1) {
        // accept incoming connection
        socklen_t client_address_length = sizeof(client_address);
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_length);

        // check if max number of clients has been reached
        if (client_count == MAX_CLIENTS) {
            char message[BUFFER_SIZE];
            sprintf(message, "Server is full. Please try again later.\n");
            send(client_socket, message, strlen(message), 0);
            close(client_socket);
            continue;
        }

        // add client socket to list
        clients[client_count] = client_socket;
        client_count++;

        // create thread to handle client
        pthread_create(&thread, NULL, handle_client, (void *)&client_socket);
    }

    return 0;
}