//FormAI DATASET v1.0 Category: Chat server ; Style: distributed
// Distributed Chat Server Program in C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

typedef struct {
    int client_socket;
    struct sockaddr_in client_address;
} client_info;

client_info clients[MAX_CLIENTS];
int num_clients = 0;

void *client_handler(void *arg) {
    char buffer[BUFFER_SIZE];
    int client_socket = *(int *)arg;
    int read_size;

    while ((read_size = recv(client_socket, buffer, BUFFER_SIZE, 0)) > 0) {
        // Broadcast message to all other clients
        for (int i = 0; i < num_clients; i++) {
            if (clients[i].client_socket != client_socket) {
                send(clients[i].client_socket, buffer, strlen(buffer), 0);
            }
        }
        memset(buffer, 0, sizeof(buffer));
    }

    // Remove client from list of active clients
    for (int i = 0; i < num_clients; i++) {
        if (clients[i].client_socket == client_socket) {
            printf("Client disconnected: %s\n", inet_ntoa(clients[i].client_address.sin_addr));
            for (int j = i; j < num_clients-1; j++) {
                clients[j] = clients[j+1];
            }
            num_clients--;
            break;
        }
    }

    close(client_socket);
    pthread_exit(NULL);
}

int main(int argc, char const *argv[]) {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    pthread_t threads[MAX_CLIENTS];

    // Create server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error creating server socket\n");
        exit(-1);
    }

    // Set server socket options
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8888);

    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        printf("Error binding server socket\n");
        exit(-2);
    }

    listen(server_socket, MAX_CLIENTS);
    printf("Server listening on port 8888...\n");

    while (1) {
        socklen_t client_len = sizeof(client_address);
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_len);

        if (client_socket == -1) {
            printf("Error accepting client connection\n");
            continue;
        }

        if (num_clients == MAX_CLIENTS) {
            printf("Reached maximum number of clients\n");
            close(client_socket);
            continue;
        }

        // Add new client to list of active clients
        clients[num_clients].client_socket = client_socket;
        clients[num_clients].client_address = client_address;
        num_clients++;

        // Create thread to handle client messages
        pthread_create(&threads[num_clients-1], NULL, client_handler, &client_socket);

        printf("New client connected: %s\n", inet_ntoa(client_address.sin_addr));
    }

    close(server_socket);
    return 0;
}