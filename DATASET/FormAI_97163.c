//FormAI DATASET v1.0 Category: Chat server ; Style: thoughtful
// This is a simple chat server program written in C language.
// The program listens to incoming client connections and allows them to send messages to each other.
// This program uses TCP sockets and multithreading for efficient handling of multiple clients.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <pthread.h>

#define PORT 8000
#define MAX_CLIENTS 10

// client information structure
typedef struct {
    int fd;
    char name[20];
} client_t;

// mutex for thread safety
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// array of connected clients
client_t clients[MAX_CLIENTS];

// function declarations
void *client_handling(void *arg);
void send_all(const char *message);
void send_to(const char *message, int client_fd);

int main() {
    int i;
    int sock_fd, new_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len;
    pthread_t tids[MAX_CLIENTS];

    // create socket
    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // set socket options
    int optval = 1;
    if (setsockopt(sock_fd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) == -1) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;
    memset(&(server_addr.sin_zero), '\0', 8);

    // bind socket to address
    if (bind(sock_fd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    // listen for incoming connections
    if (listen(sock_fd, MAX_CLIENTS) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // initialize client list
    for (i = 0; i < MAX_CLIENTS; i++) {
        clients[i].fd = -1;
        memset(clients[i].name, '\0', sizeof(clients[i].name));
    }

    printf("Server started on port %d\n", PORT);

    // accept incoming client connections
    while (1) {
        client_len = sizeof(client_addr);
        if ((new_fd = accept(sock_fd, (struct sockaddr *)&client_addr, &client_len)) == -1) {
            perror("accept");
            continue;
        }

        // find an available slot in client list
        int j;
        for (j = 0; j < MAX_CLIENTS; j++) {
            if (clients[j].fd == -1) {
                clients[j].fd = new_fd;
                break;
            }
        }

        // if client list is full, reject new connection
        if (j == MAX_CLIENTS) {
            fprintf(stderr, "Maximum number of clients reached\n");
            close(new_fd);
            continue;
        }

        char welcome_msg[50];
        sprintf(welcome_msg, "Welcome to the chat room! You are client %d\n", j+1);
        send_to(welcome_msg, new_fd);

        // create thread for handling client messages
        pthread_create(&tids[j], NULL, &client_handling, (void *)((intptr_t)new_fd));
    }

    return 0;
}

// function for handling individual clients
void *client_handling(void *arg) {
    int i, n;
    char buf[1024];
    int client_fd = (intptr_t)arg;

    // ask client for their name
    char name[20];
    send_to("Please enter your name: ", client_fd);
    while (recv(client_fd, name, sizeof(name), 0) == -1);
    name[strcspn(name, "\n")] = '\0';

    // add client name to list
    for (i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i].fd == client_fd) {
            strcpy(clients[i].name, name);
            break;
        }
    }

    char join_msg[50];
    sprintf(join_msg, "%s has joined the chat room\n", name);
    send_all(join_msg);

    // receive and broadcast messages from client
    while ((n = recv(client_fd, buf, sizeof(buf), 0)) > 0) {
        buf[n] = '\0';
        char msg[1024];
        sprintf(msg, "%s: %s", name, buf);
        send_all(msg);
    }

    // remove client from list
    for (i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i].fd == client_fd) {
            clients[i].fd = -1;
            memset(clients[i].name, '\0', sizeof(clients[i].name));
            break;
        }
    }

    char leave_msg[50];
    sprintf(leave_msg, "%s has left the chat room\n", name);
    send_all(leave_msg);

    close(client_fd);
    pthread_exit(NULL);
}

// function for broadcasting messages to all clients
void send_all(const char *message) {
    pthread_mutex_lock(&mutex);
    int i;
    for (i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i].fd != -1) {
            send(clients[i].fd, message, strlen(message), 0);
        }
    }
    pthread_mutex_unlock(&mutex);
}

// function for sending messages to a specific client
void send_to(const char *message, int client_fd) {
    pthread_mutex_lock(&mutex);
    send(client_fd, message, strlen(message), 0);
    pthread_mutex_unlock(&mutex);
}