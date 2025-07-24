//FormAI DATASET v1.0 Category: Chat server ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10

int client_sockets[MAX_CLIENTS];
pthread_t threads[MAX_CLIENTS];
int num_clients = 0;
pthread_mutex_t mutex;

void *handle_client(void *arg) {
    int socket = *(int *)arg;
    int read_size;
    char buffer[1024] = {0};
    
    while ((read_size = recv(socket, buffer, 1024, 0)) > 0) {  
        for (int i = 0; i < num_clients; i++) {
            if (client_sockets[i] != socket) {
                send(client_sockets[i], buffer, strlen(buffer), 0);
            }
        }
        memset(buffer, 0, sizeof(buffer));
    }
    pthread_mutex_lock(&mutex);
    for (int i = 0; i < num_clients; i++) {  
        if (client_sockets[i] == socket) {
            client_sockets[i] = client_sockets[num_clients-1];
            num_clients--;
            break;
        }
    }
    pthread_mutex_unlock(&mutex);
    close(socket);
}

int main(int argc, char const *argv[]) {
    int server_fd, client_fd;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    pthread_mutex_init(&mutex, NULL);

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        if ((client_fd = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        pthread_mutex_lock(&mutex);
        client_sockets[num_clients++] = client_fd;
        pthread_mutex_unlock(&mutex);
        pthread_create(&threads[num_clients-1], NULL, handle_client, &client_fd);
    }
}