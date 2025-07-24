//FormAI DATASET v1.0 Category: Client Server Application ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define SERVER_PORT 8080
#define CLIENT_POOL_SIZE 10

// client data structure
typedef struct client {
    int sock;
    char name[20];
    bool is_connected;
} client_t;

// client pool
client_t client_pool[CLIENT_POOL_SIZE];

// mutex for client pool
pthread_mutex_t client_pool_mutex = PTHREAD_MUTEX_INITIALIZER;

// function to add client to pool
void add_client(int sock) {
    pthread_mutex_lock(&client_pool_mutex);
    for (int i = 0; i < CLIENT_POOL_SIZE; i++) {
        if (client_pool[i].is_connected == false) {
            memset(client_pool[i].name, 0, sizeof(client_pool[i].name));
            client_pool[i].sock = sock;
            client_pool[i].is_connected = true;
            break;
        }
    }
    pthread_mutex_unlock(&client_pool_mutex);
}

// function to remove client from pool
void remove_client(int sock) {
    pthread_mutex_lock(&client_pool_mutex);
    for (int i = 0; i < CLIENT_POOL_SIZE; i++) {
        if (client_pool[i].sock == sock) {
            client_pool[i].is_connected = false;
            break;
        }
    }
    pthread_mutex_unlock(&client_pool_mutex);
}

// function to broadcast message to all clients in the pool
void broadcast_message(char *msg) {
    pthread_mutex_lock(&client_pool_mutex);
    for (int i = 0; i < CLIENT_POOL_SIZE; i++) {
        if (client_pool[i].is_connected) {
            send(client_pool[i].sock, msg, strlen(msg), 0);
        }
    }
    pthread_mutex_unlock(&client_pool_mutex);
}

// client handling function
void *handle_client(void *arg) {
    int sock = *(int *)arg;
    char name[20] = {0};
    char msg[1024] = {0};
    bool is_authenticated = false;

    // read client name
    while (is_authenticated == false) {
        recv(sock, name, sizeof(name), 0);
        if (strlen(name) > 0) {
            is_authenticated = true;
        }
    }

    sprintf(msg, "%s has joined the chat\n", name);
    broadcast_message(msg);

    while (1) {
        int bytes_received = recv(sock, msg, sizeof(msg), 0);
        if (bytes_received <= 0) {
            break;
        }

        msg[bytes_received] = '\0';

        if (strcmp(msg, "exit\n") == 0) {
            break;
        }

        sprintf(msg, "%s: %s", name, msg);
        broadcast_message(msg);
    }

    sprintf(msg, "%s has left the chat\n", name);
    broadcast_message(msg);

    remove_client(sock);
    close(sock);

    pthread_exit(NULL);
}

int main() {
    int server_sock, client_sock, opt = 1;
    struct sockaddr_in server_addr, client_addr;

    // initialize client pool
    for (int i = 0; i < CLIENT_POOL_SIZE; i++) {
        client_pool[i].sock = 0;
        client_pool[i].is_connected = false;
    }

    // create server socket
    if ((server_sock = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // set socket options
    if (setsockopt(server_sock, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // configure server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(SERVER_PORT);

    // bind server address to socket
    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // start listening for incoming connections
    if (listen(server_sock, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", SERVER_PORT);

    while (1) {
        unsigned int client_addr_len = sizeof(client_addr);

        // accept client connection
        if ((client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &client_addr_len)) < 0) {
            perror("accept failed");
            continue;
        }

        printf("New client connected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // add client to pool
        add_client(client_sock);

        // handle client in new thread
        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, handle_client, &client_sock) != 0) {
            perror("pthread_create failed");
            continue;
        }
    }

    return 0;
}