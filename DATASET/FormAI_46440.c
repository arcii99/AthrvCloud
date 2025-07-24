//FormAI DATASET v1.0 Category: Chat server ; Style: lively
// Hello, human! I am a chatbot and I am excited to show you a unique C chat server program.
// Let's create a simple multithreaded chat server that allows multiple clients to connect and chat in real-time!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 5

int clients[MAX_CLIENTS];
int client_count = 0;
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

void *handle_client(void *client_sockfd)
{
    int sockfd = *(int*)client_sockfd;
    char message[1024];

    while (1) {
        // Receive message from client
        if (recv(sockfd, message, 1024, 0) <= 0) {
            // If receive message fails, remove client from clients array and exit thread
            pthread_mutex_lock(&clients_mutex);
            for (int i = 0; i < client_count; i++) {
                if (clients[i] == sockfd) {
                    memmove(clients+i, clients+i+1, (client_count-i-1)*sizeof(int));
                    client_count--;
                    break;
                }
            }
            pthread_mutex_unlock(&clients_mutex);
            break;
        }
        // Send message to all other clients
        pthread_mutex_lock(&clients_mutex);
        for (int i = 0; i < client_count; i++) {
            if (clients[i] != sockfd) {
                send(clients[i], message, strlen(message), 0);
            }
        }
        pthread_mutex_unlock(&clients_mutex);
    }
    // Close connection with client
    close(sockfd);
    pthread_exit(NULL);
}

int main(int argc, char const *argv[])
{
    int server_sockfd, client_sockfd;
    struct sockaddr_in server_addr, client_addr;
    pthread_t thread_id;

    // Create server socket
    if ((server_sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    // Configure server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    // Bind server address to socket
    if (bind(server_sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }
    // Listen for client connections
    if (listen(server_sockfd, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Chat server is up and running!\n");

    while (1) {
        socklen_t client_addr_len = sizeof(client_addr);
        // Accept client connection
        if ((client_sockfd = accept(server_sockfd, (struct sockaddr*)&client_addr, &client_addr_len)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }
        // Add client to clients array
        pthread_mutex_lock(&clients_mutex);
        if (client_count < MAX_CLIENTS) {
            clients[client_count] = client_sockfd;
            client_count++;
            // Create thread to handle client
            pthread_create(&thread_id, NULL, handle_client, &client_sockfd);
            // Detach thread
            pthread_detach(thread_id);
            printf("New client connected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
        }
        pthread_mutex_unlock(&clients_mutex);
    }

    return 0;
}