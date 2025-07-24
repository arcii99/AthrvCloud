//FormAI DATASET v1.0 Category: Chat server ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_CLIENTS 10

int num_clients = 0;
int client_sockets[MAX_CLIENTS];
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

void *handle_client(void *p_client_socket) {
    int client_socket = *(int *)p_client_socket;
    char name[20];
    char message[256];
    int n;

    // Prompt client for their name
    write(client_socket, "Please enter your name: ", strlen("Please enter your name: "));
    n = read(client_socket, name, 20);
    name[n-1] = '\0';

    // Welcome message
    sprintf(message, "Welcome %s! There are %d clients connected.\n", name, num_clients);
    write(client_socket, message, strlen(message));

    while (1) {
        // Receive message from client
        memset(message, 0, 256);
        n = read(client_socket, message, 256);
        if (n == 0) {
            // Client disconnected
            close(client_socket);
            pthread_mutex_lock(&clients_mutex);
            num_clients--;
            for (int i = 0; i < MAX_CLIENTS; i++) {
                if (client_sockets[i] == client_socket) {
                    client_sockets[i] = -1;
                }
            }
            pthread_mutex_unlock(&clients_mutex);
            sprintf(message, "%s has disconnected. There are %d clients connected.\n", name, num_clients);
            break;
        }
        message[n-1] = '\0';

        // Broadcast message to all connected clients
        pthread_mutex_lock(&clients_mutex);
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (client_sockets[i] != -1 && client_sockets[i] != client_socket) {
                write(client_sockets[i], message, strlen(message));
            }
        }
        pthread_mutex_unlock(&clients_mutex);
    }

    // Notify all connected clients of disconnection
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (client_sockets[i] != -1) {
            write(client_sockets[i], message, strlen(message));
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}

int main(int argc, char *argv[]) {
    int server_socket;
    struct sockaddr_in server_addr, client_addr;
    int client_socket, client_addr_len;
    pthread_t thread_id;

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Failed to create socket.\n");
        exit(EXIT_FAILURE);
    }

    // Bind socket to IP address and port
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Failed to bind socket to port.\n");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    listen(server_socket, MAX_CLIENTS);

    printf("Server is listening on port 8080...\n");

    while (1) {
        // Accept incoming connection
        client_addr_len = sizeof(client_addr);
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, (socklen_t *)&client_addr_len);
        if (client_socket < 0) {
            printf("Failed to accept incoming connection.\n");
            exit(EXIT_FAILURE);
        }

        // Add client socket to array of clients
        pthread_mutex_lock(&clients_mutex);
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (client_sockets[i] == -1) {
                client_sockets[i] = client_socket;
                num_clients++;
                break;
            }
        }
        pthread_mutex_unlock(&clients_mutex);

        // Start handling client in separate thread
        pthread_create(&thread_id, NULL, handle_client, (void *)&client_socket);
    }
    
    return 0;
}