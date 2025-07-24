//FormAI DATASET v1.0 Category: Chat server ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int server_fd, new_socket;
pthread_t threads[MAX_CLIENTS];
int client_sockets[MAX_CLIENTS];

void* client_handler(void* arg) {
    int client_sock = *(int*)arg;
    char buffer[BUFFER_SIZE] = {0};

    while (1) {
        int num_bytes = read(client_sock, buffer, BUFFER_SIZE);
        if (num_bytes <= 0) {
            printf("Client %d disconnected.\n", client_sock);
            break;
        }

        printf("Received message from client %d: %s", client_sock, buffer);

        // Send the message to all other connected clients
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (client_sockets[i] != 0 && client_sockets[i] != client_sock) {
                write(client_sockets[i], buffer, num_bytes);
            }
        }
    }

    // Remove the client socket from the list of connected clients
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (client_sockets[i] == client_sock) {
            client_sockets[i] = 0;
            break;
        }
    }

    close(client_sock);
    pthread_exit(NULL);
}

int main(int argc, char const *argv[]) {
    struct sockaddr_in address;
    int opt = 1, addrlen = sizeof(address);
       
    // Create the server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set options for the server socket
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
       
    // Bind the server socket to the specified address and port
    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming client connections
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        // Wait for a new client connection
        if ((new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        printf("New client connected: %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

        // Add the new client socket to the list of connected clients
        int i;
        for (i = 0; i < MAX_CLIENTS; i++) {
            if (client_sockets[i] == 0) {
                client_sockets[i] = new_socket;
                break;
            }
        }

        // Create a new thread to handle the client communication
        if (pthread_create(&threads[i], NULL, client_handler, (void*)&new_socket) < 0) {
            perror("pthread_create");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}