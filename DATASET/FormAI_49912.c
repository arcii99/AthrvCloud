//FormAI DATASET v1.0 Category: Chat server ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define PORT 8888
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

// Client socket structure
typedef struct {
    int sockfd;
    struct sockaddr_in addr;
    char name[20];
} client_info_t;

// Global array to store clients
client_info_t clients[MAX_CLIENTS];
int client_count = 0;

// Function to broadcast message to all clients except the sender
void broadcast_message(char *message, int sender_sockfd) {
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i].sockfd > 0 && clients[i].sockfd != sender_sockfd) {
            send(clients[i].sockfd, message, strlen(message), 0);
        }
    }
}

// Function to handle client connections
void *handle_client(void *arg) {
    client_info_t *client = (client_info_t *) arg;
    char buffer[BUFFER_SIZE];
    int n;

    // Set client name
    recv(client->sockfd, client->name, sizeof(client->name), 0);

    // Notify all clients of new connection
    char join_msg[30];
    sprintf(join_msg, "%s has joined.", client->name);
    broadcast_message(join_msg, client->sockfd);

    // Start chat loop
    while ((n = recv(client->sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[n] = '\0';
        char message[BUFFER_SIZE + 30];
        sprintf(message, "%s: %s", client->name, buffer);
        broadcast_message(message, client->sockfd);
    }

    // Handle client disconnect
    char leave_msg[30];
    sprintf(leave_msg, "%s has left.", client->name);
    broadcast_message(leave_msg, client->sockfd);
    close(client->sockfd);
    client->sockfd = 0;
    client_count--;

    return NULL;
}

// Main function
int main() {
    int sockfd;
    struct sockaddr_in serv_addr;
    pthread_t threads[MAX_CLIENTS];

    // Initialize server socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    // Bind server socket
    bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));

    // Start listening for connections
    listen(sockfd, MAX_CLIENTS);

    // Accept client connections and handle them in separate threads
    while (1) {
        int client_sockfd = accept(sockfd, NULL, NULL);

        if (client_sockfd > 0) {
            if (client_count >= MAX_CLIENTS) {
                char error_msg[] = "Maximum number of clients reached.";
                send(client_sockfd, error_msg, strlen(error_msg), 0);
                close(client_sockfd);
            } else {
                clients[client_count].sockfd = client_sockfd;
                clients[client_count].addr = serv_addr;
                pthread_create(&threads[client_count], NULL, handle_client, &clients[client_count]);
                client_count++;
            }
        }
    }

    return 0;
}