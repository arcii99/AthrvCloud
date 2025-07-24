//FormAI DATASET v1.0 Category: Chat server ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define MAX_MESSAGE_LEN 1000

typedef struct {
    int sock_fd;
    struct sockaddr_in address;
    char name[20];
} client_t;

client_t clients[MAX_CLIENTS];
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

/* Function to send message to all clients except sender */
void send_to_all_except_sender(char *message, int sender) {
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i].sock_fd != 0 && clients[i].sock_fd != sender) {
            send(clients[i].sock_fd, message, strlen(message), 0);
        }
    }
}

/* Function to handle client connection */
void *handle_client(void *arg) {
    client_t client = *(client_t *)arg;
    char buf[MAX_MESSAGE_LEN];
    memset(buf, 0, MAX_MESSAGE_LEN);

    while (1) {
        if (recv(client.sock_fd, buf, MAX_MESSAGE_LEN, 0) <= 0) {
            printf("%s disconnected\n", client.name);
            break;
        }
        printf("%s: %s", client.name, buf);
        send_to_all_except_sender(buf, client.sock_fd);
        memset(buf, 0, MAX_MESSAGE_LEN);
    }

    pthread_mutex_lock(&lock);
    close(client.sock_fd);
    client.sock_fd = 0;
    pthread_mutex_unlock(&lock);

    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    pthread_t clients_thread[MAX_CLIENTS];
    char name[20];

    /* Create server socket */
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Failed to create server socket");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(9000);

    /* Bind socket to address and port */
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to bind server socket");
        exit(EXIT_FAILURE);
    }

    /* Listen for incoming connections */
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("Failed to listen for incoming connections");
        exit(EXIT_FAILURE);
    }

    printf("Server started\n");

    while (1) {
        unsigned int addr_len = sizeof(client_addr);

        /* Accept incoming connection */
        if ((client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &addr_len)) < 0) {
            perror("Failed to accept incoming connection");
            continue;
        }

        /* Prompt username from client */
        send(client_fd, "\nEnter your name: ", strlen("\nEnter your name: "), 0);
        recv(client_fd, name, 20, 0);

        /* Add client to client list */
        pthread_mutex_lock(&lock);
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (clients[i].sock_fd == 0) {
                clients[i].sock_fd = client_fd;
                clients[i].address = client_addr;
                strcpy(clients[i].name, name);
                printf("%s connected\n", clients[i].name);
                pthread_create(&clients_thread[i], NULL, handle_client, (void *)&clients[i]);
                break;
            }
        }
        pthread_mutex_unlock(&lock);
    }

    close(server_fd);
    exit(EXIT_SUCCESS);
}