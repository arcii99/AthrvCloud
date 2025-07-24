//FormAI DATASET v1.0 Category: Client Server Application ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CONNECTIONS 30

int client_sockets[MAX_CONNECTIONS]; // Stores client socket file descriptors
int active_clients = 0; // Number of active clients
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // Mutex initialization

void *handle_client(void *arg) {
    int client_socket = *(int *)arg; // Typecasting arg to int pointer and dereferencing
    char buffer[1024] = {0};
    int valread;

    while ((valread = read(client_socket , buffer, 1024)) > 0) { // Read client message
        printf("Received message from client %d: %s\n", client_socket, buffer);
        pthread_mutex_lock(&mutex); // Lock mutex to access shared active_clients variable
        for (int i = 0; i < active_clients; i++) { // Send message to all clients
            if (client_sockets[i] != client_socket) { // Exclude sender
                send(client_sockets[i] , buffer , strlen(buffer) , 0 );
            }
        }
        memset(buffer, 0, 1024); // Clear buffer for next message
        pthread_mutex_unlock(&mutex); // Unlock mutex
    }

    pthread_mutex_lock(&mutex); // Lock mutex to remove client socket from array
    for (int i = 0; i < active_clients; i++) {
        if (client_sockets[i] == client_socket) {
            client_sockets[i] = 0;
            active_clients--;
            break;
        }
    }
    close(client_socket); // Close client socket
    pthread_mutex_unlock(&mutex); // Unlock mutex
    printf("Client %d disconnected.\n", client_socket);
    return NULL;
}

int main(int argc, char const *argv[]) {
    int server_fd, new_client_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) { // Creating socket file descriptor
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Socket options failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) { // Bind socket to given port
        perror("Socket binding failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, MAX_CONNECTIONS) < 0) { // Listen for connections
        perror("Socket listening failed");
        exit(EXIT_FAILURE);
    }

    printf("Server started.\n");

    while (1) {
        if ((new_client_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
            perror("Socket accepting failed");
            exit(EXIT_FAILURE);
        }

        printf("Client %d connected.\n", new_client_socket);

        pthread_mutex_lock(&mutex); // Lock mutex to access shared client_sockets and active_clients variables
        client_sockets[active_clients] = new_client_socket;
        active_clients++;
        pthread_mutex_unlock(&mutex); // Unlock mutex

        pthread_t tid;
        pthread_create(&tid, NULL, handle_client, &new_client_socket); // Create new thread to handle client
        pthread_detach(tid); // Detach thread
    }
    return 0;
}