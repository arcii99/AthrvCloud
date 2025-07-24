//FormAI DATASET v1.0 Category: Firewall ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_CONNECTIONS 10

pthread_mutex_t mutex;

void *client_handler(void *arg) {
    int client_socket = *(int *)arg;
    char buffer[1024];

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        int read_len = read(client_socket, buffer, sizeof(buffer));
        if (read_len <= 0)
            break;

        pthread_mutex_lock(&mutex);

        // Custom firewall logic goes here
        // For example, check if the request is coming from a blacklisted IP address
        // If so, send a forbidden response

        // For now, let's just "echo" the message back to the sender
        write(client_socket, buffer, read_len);

        pthread_mutex_unlock(&mutex);
    }

    close(client_socket);
    pthread_exit(NULL);
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_len = sizeof(client_address);

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(8080);

    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket() error");
        exit(EXIT_FAILURE);
    }

    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("bind() error");
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, MAX_CONNECTIONS) == -1) {
        perror("listen() error");
        exit(EXIT_FAILURE);
    }

    pthread_t threads[MAX_CONNECTIONS];

    while (1) {
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_len)) == -1) {
            perror("accept() error");
            continue;
        }

        printf("Accepted connection from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, client_handler, (void *)&client_socket) != 0) {
            perror("pthread_create() error");
            close(client_socket);
            continue;
        }

        threads[thread_id % MAX_CONNECTIONS] = thread_id;
    }

    close(server_socket);

    return 0;
}