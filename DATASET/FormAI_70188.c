//FormAI DATASET v1.0 Category: Chat server ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10

int clients[MAX_CLIENTS];
int num_clients = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void handle_request(int client) {
    char message[1024] = {0};
    read(client, message, 1024);
    printf("Received message: %s", message);
    for(int i = 0; i < num_clients; i++) {
        if(clients[i] != client) {
            write(clients[i], message, strlen(message));
        }
    }
}

void* client_thread(void* arg) {
    int client = *((int*) arg);
    while(1) {
        handle_request(client);
    }
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    // Create socket file descriptor
    if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    int opt = 1;
    if(setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // Bind socket to address and port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    if(bind(server_fd, (struct sockaddr*) &address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening for connections
    if(listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    // Accept client connections and spawn threads to handle them
    while(1) {
        if((new_socket = accept(server_fd, (struct sockaddr*) &address, (socklen_t*) &addrlen)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        pthread_mutex_lock(&mutex);
        if(num_clients < MAX_CLIENTS) {
            clients[num_clients++] = new_socket;
            pthread_t thread_id;
            pthread_create(&thread_id, NULL, client_thread, &new_socket);
            pthread_detach(thread_id);
        } else {
            printf("Max clients reached, connection rejected\n");
            close(new_socket);
        }
        pthread_mutex_unlock(&mutex);
    }

    return 0;
}