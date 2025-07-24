//FormAI DATASET v1.0 Category: Client Server Application ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CLIENTS 5

void *handle_client(void *arg) {
    int client_socket = *((int *) arg);
    char buffer[1024] = {0};
    while (true) {
        int valread = read(client_socket, buffer, 1024);
        if (valread > 0) {
            printf("Received message from client - %s\n", buffer);
            send(client_socket, buffer, strlen(buffer), 0);
        } else {
            printf("Client disconnected\n");
            break;
        }
        memset(buffer, 0, 1024);
    }
    close(client_socket);
    return NULL;
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server started on port %d\n", PORT);

    pthread_t client_threads[MAX_CLIENTS];
    int i = 0;
    while (true) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        printf("New client connected - %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

        pthread_create(&client_threads[i], NULL, handle_client, &new_socket);

        i++;
        if (i >= MAX_CLIENTS) {
            i = 0;
            // Join all threads before continuing
            for (int j = 0; j < MAX_CLIENTS; j++) {
                pthread_join(client_threads[j], NULL);
            }
        }
    }

    return 0;
}