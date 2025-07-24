//FormAI DATASET v1.0 Category: Chat server ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

// Define a struct to hold client information
struct Client {
    int socket;
    struct sockaddr_in address;
};

// Declare global variables
struct Client clients[MAX_CLIENTS];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to handle incoming messages from clients
void *handle_client(void *client_socket) {
    char buffer[BUFFER_SIZE];
    int socket = *(int*) client_socket;
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int read_size = recv(socket, buffer, BUFFER_SIZE, 0);
        if (read_size == 0) {
            printf("Client disconnected\n");
            break;
        }
        printf("Message received: %s\n", buffer);
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (clients[i].socket != 0 && clients[i].socket != socket) {
                send(clients[i].socket, buffer, strlen(buffer), 0);
            }
        }
    }
    // Remove client from list of connected clients
    pthread_mutex_lock(&mutex);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i].socket == socket) {
            clients[i].socket = 0;
            break;
        }
    }
    pthread_mutex_unlock(&mutex);
    close(socket);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8888);
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Could not create server socket");
        exit(1);
    }
    if (bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address)) < 0) {
        perror("Could not bind to server socket");
        exit(1);
    }
    listen(server_socket, MAX_CLIENTS);
    printf("Server started\n");
    while (1) {
        socklen_t client_length = sizeof(client_address);
        client_socket = accept(server_socket, (struct sockaddr*) &client_address, &client_length);
        if (client_socket < 0) {
            perror("Could not accept client connection");
            exit(1);
        }
        // Add new client to list of connected clients
        pthread_mutex_lock(&mutex);
        int i;
        for (i = 0; i < MAX_CLIENTS; i++) {
            if (clients[i].socket == 0) {
                clients[i].socket = client_socket;
                clients[i].address = client_address;
                pthread_t thread_id;
                pthread_create(&thread_id, NULL, handle_client, (void*) &client_socket);
                break;
            }
        }
        if (i == MAX_CLIENTS) {
            printf("Maximum number of clients reached\n");
            close(client_socket);
        }
        pthread_mutex_unlock(&mutex);
    }
    return 0;
}