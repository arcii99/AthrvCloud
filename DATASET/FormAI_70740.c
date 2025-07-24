//FormAI DATASET v1.0 Category: Client Server Application ; Style: introspective
/* This is a unique C client-server application that allows users to send messages between clients through a central server. It is an introspective chat program that allows the server and all clients to see each other's messages.

The program starts by creating a server socket and a client socket, and listening for incoming connections. When a client connects, the server assigns it a unique ID and adds it to a list of connected clients. The server then broadcasts a message to all clients, notifying them of the new connection.

The clients can then send messages to the server, which broadcasts them to all other connected clients. The server also logs all messages for future reference.

Enjoy! */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 100
#define MAX_MSG_LEN 1000

int client_count = 0;
int client_ids[MAX_CLIENTS];
int client_sockets[MAX_CLIENTS];

pthread_mutex_t client_mutex = PTHREAD_MUTEX_INITIALIZER;

void *handle_client(void *client_socket_ptr) {
    int client_socket = *(int*) client_socket_ptr;
    char client_msg[MAX_MSG_LEN];

    while (recv(client_socket, client_msg, MAX_MSG_LEN, 0) > 0) {
        pthread_mutex_lock(&client_mutex);
        for (int i = 0; i < client_count; i++) {
            if (client_socket != client_sockets[i])
                send(client_sockets[i], client_msg, strlen(client_msg), 0);
        }
        pthread_mutex_unlock(&client_mutex);

        printf("Client %d: %s", client_socket, client_msg);
        fflush(stdout);
    }

    close(client_socket);

    pthread_mutex_lock(&client_mutex);
    for (int i = 0; i < client_count; i++) {
        if (client_socket == client_sockets[i]) {
            client_ids[i] = -1;
            client_sockets[i] = -1;
            break;
        }
    }
    client_count--;
    pthread_mutex_unlock(&client_mutex);

    char client_disconnect_msg[MAX_MSG_LEN];
    snprintf(client_disconnect_msg, MAX_MSG_LEN, "Client %d disconnected.\n", client_socket);
    printf("%s", client_disconnect_msg);
    fflush(stdout);

    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {

    int server_socket, client_socket;
    int server_port = 8080;
    int reuse_addr = 1;
    struct sockaddr_in server_addr, client_addr;
    socklen_t sock_size = sizeof(struct sockaddr_in);
    pthread_t thread_id;
    char welcome_msg[MAX_MSG_LEN];

    // Create server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Error creating server socket");
        exit(EXIT_FAILURE);
    }

    // Set socket options to reuse address
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &reuse_addr, sizeof(reuse_addr)) == -1) {
        perror("Error setting socket options");
        exit(EXIT_FAILURE);
    }

    // Set up server address struct
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(server_port);

    // Bind server socket to address
    if (bind(server_socket, (struct sockaddr*) &server_addr, sizeof(server_addr)) == -1) {
        perror("Error binding server socket to address");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, SOMAXCONN) == -1) {
        perror("Error listening for incoming connections");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connections
    while (client_socket = accept(server_socket, (struct sockaddr*) &client_addr, &sock_size)) {
        // Assign client a unique ID and add to list of connected clients
        int client_id = -1;
        pthread_mutex_lock(&client_mutex);
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (client_ids[i] == -1) {
                client_ids[i] = client_id = i;
                client_sockets[i] = client_socket;
                client_count++;
                break;
            }
        }
        pthread_mutex_unlock(&client_mutex);

        // Send welcome message to client
        snprintf(welcome_msg, MAX_MSG_LEN, "Welcome, client %d!\n", client_id);
        send(client_socket, welcome_msg, strlen(welcome_msg), 0);

        // Broadcast new connection message to all clients except the connecting client
        char new_conn_msg[MAX_MSG_LEN];
        snprintf(new_conn_msg, MAX_MSG_LEN, "Client %d connected.\n", client_id);
        pthread_mutex_lock(&client_mutex);
        for (int i = 0; i < client_count; i++) {
            if (client_socket != client_sockets[i])
                send(client_sockets[i], new_conn_msg, strlen(new_conn_msg), 0);
        }
        pthread_mutex_unlock(&client_mutex);

        // Create new client thread to handle messages
        pthread_create(&thread_id, NULL, handle_client, &client_socket);
    }

    // Clean up and exit
    close(server_socket);
    return 0;
}