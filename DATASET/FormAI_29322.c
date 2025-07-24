//FormAI DATASET v1.0 Category: Networking ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_CLIENTS 100 // Maximum number of clients allowed to connect
#define BUFFER_SIZE 1024 // Size of message buffer

// Client structure
typedef struct {
    int sockfd;
    struct sockaddr_in addr;
    char name[50];
} client_t;

client_t clients[MAX_CLIENTS]; // Array to store all clients information
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER; // Mutex to protect client array

void broadcast(char *msg, int sender_fd) {
    pthread_mutex_lock(&clients_mutex); // Acquiring mutex
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i].sockfd && clients[i].sockfd != sender_fd) { // Checking if client is connected and not the sender
            write(clients[i].sockfd, msg, strlen(msg)); // Sending message to the client
        }
    }
    pthread_mutex_unlock(&clients_mutex); // Releasing mutex
}

void *handle_client(void *arg) {
    client_t client = *((client_t *)arg);
    char buffer[BUFFER_SIZE];
    char name[50];

    // Prompting client to enter their name
    write(client.sockfd, "Welcome to the chat room!\nPlease enter your name: ", strlen("Welcome to the chat room!\nPlease enter your name: "));
    read(client.sockfd, &name, sizeof(name));

    // Saving client's name
    strcpy(client.name, name);

    // Notifying other clients about the new connection
    sprintf(buffer, "%s has joined the chat!\n", client.name);
    broadcast(buffer, -1);

    // Handling incoming messages
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int message_size = read(client.sockfd, buffer, sizeof(buffer));
        if (message_size <= 0) {
            // Client disconnected
            sprintf(buffer, "%s has left the chat!\n", client.name);
            close(client.sockfd);
            broadcast(buffer, client.sockfd);
            break;
        }
        sprintf(buffer, "%s: %s", client.name, buffer);
        broadcast(buffer, client.sockfd);
    }

    // Removing client from the array
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i].sockfd == client.sockfd) {
            clients[i].sockfd = 0;
            strcpy(clients[i].name, "");
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);

    pthread_detach(pthread_self());
    return NULL;
}

int main(int argc, char *argv[]) {
    int server_fd, new_client_fd, opt = 1;
    struct sockaddr_in server_addr, client_addr;
    pthread_t tid;
    socklen_t client_len = sizeof(client_addr);

    // Creating server socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd <= 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Setting socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Error setting socket options");
        exit(EXIT_FAILURE);
    }

    // Binding socket to port
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Binding failed");
        exit(EXIT_FAILURE);
    }

    // Listening for incoming connections
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("Listening failed");
        exit(EXIT_FAILURE);
    }

    printf("Server is up and running on port %d...\n", ntohs(server_addr.sin_port));

    while (1) {
        // Accepting incoming connection
        new_client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_len);
        if (new_client_fd < 0) {
            perror("Accepting connection failed");
            continue;
        }

        // Adding client to the array
        pthread_mutex_lock(&clients_mutex);
        int i;
        for (i = 0; i < MAX_CLIENTS; i++) {
            if (clients[i].sockfd == 0) {
                clients[i].sockfd = new_client_fd;
                clients[i].addr = client_addr;
                break;
            }
        }
        pthread_mutex_unlock(&clients_mutex);

        if (i == MAX_CLIENTS) {
            fprintf(stderr, "Client limit exceeded. Connection rejected.\n");
            close(new_client_fd);
            continue;
        }

        // Creating a new thread for this client
        pthread_create(&tid, NULL, &handle_client, (void *)&clients[i]);
    }

    return 0;
}