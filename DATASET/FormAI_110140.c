//FormAI DATASET v1.0 Category: Chat server ; Style: visionary
// A visionary chat server program in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_CLIENTS 100
#define MAX_MSG_LENGTH 200

int client_count = 0;
int client_sockets[MAX_CLIENTS];
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void send_message(char* message, int current_client) {
    pthread_mutex_lock(&lock);
    for (int i=0; i<client_count; i++) {
        if (client_sockets[i] != current_client) { // broadcast to all except the current client
            send(client_sockets[i], message, strlen(message), 0);
        }
    }
    pthread_mutex_unlock(&lock);
}

void* handle_client(void* arg) {
    int client_socket = *((int*) arg);
    char message[MAX_MSG_LENGTH];

    while (1) {
        memset(message, 0, MAX_MSG_LENGTH);
        int read_value = recv(client_socket, message, MAX_MSG_LENGTH, 0);
        if (read_value <= 0) {
            // client disconnected
            pthread_mutex_lock(&lock);
            for (int i=0; i<client_count; i++) {
                if (client_sockets[i] == client_socket) {
                    client_count--;
                    for (int j=i; j<client_count; j++) {
                        client_sockets[j] = client_sockets[j+1];
                    }
                    break;
                }
            }
            pthread_mutex_unlock(&lock);
            close(client_socket);
            return NULL;
        }
        send_message(message, client_socket);
    }
}

int main(int argc, char* argv[]) {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_length = sizeof(client_address);
    pthread_t new_thread;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Error: Could not create socket.\n");
        exit(EXIT_FAILURE);
    }

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8080);

    if (bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address)) < 0) {
        perror("Error: Binding failed.\n");
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, 5) < 0) {
        perror("Error: Listening failed.\n");
        exit(EXIT_FAILURE);
    }

    printf("Server is running and listening on port %d.\n", ntohs(server_address.sin_port));

    while (1) {
        client_socket = accept(server_socket, (struct sockaddr*) &client_address, &client_address_length);

        pthread_mutex_lock(&lock);
        if (client_count < MAX_CLIENTS) {
            client_sockets[client_count] = client_socket;
            client_count++;
            pthread_create(&new_thread, NULL, handle_client, &client_socket);
        }
        else {
            printf("Client limit reached. Connection rejected.\n");
            close(client_socket);
        }
        pthread_mutex_unlock(&lock);
    }

    return 0;
}