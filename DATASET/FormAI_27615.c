//FormAI DATASET v1.0 Category: Networking ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10

// global variables
int client_sockets[MAX_CLIENTS];
int num_clients = 0;

// function prototypes
void *handle_client(void *socket_ptr);
void send_all_clients(const char *message, int sender_socket);

int main(int argc, char const *argv[]) {
    int server_socket, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    pthread_t threads[MAX_CLIENTS];

    // create server socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // set server socket options
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // bind server socket to port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server is running on port %d\n", PORT);

    // accept incoming connections and create a new thread to handle each client
    while (1) {
        if ((new_socket = accept(server_socket, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        printf("New client connected: %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

        // store client socket in array
        client_sockets[num_clients] = new_socket;
        num_clients++;

        // create new thread to handle client
        pthread_create(&threads[num_clients - 1], NULL, handle_client, &new_socket);
    }

    return 0;
}

void *handle_client(void *socket_ptr) {
    int client_socket = *(int *)socket_ptr;
    char buffer[1024] = {0};

    while (1) {
        // receive data from client
        if (recv(client_socket, buffer, 1024, 0) <= 0) {
            // client disconnected
            printf("Client disconnected\n");
            break;
        }

        printf("Received message from client: %s\n", buffer);

        // send message to all clients except sender
        send_all_clients(buffer, client_socket);

        // clear buffer
        memset(buffer, 0, sizeof(buffer));
    }

    // remove client socket from array
    for (int i = 0; i < num_clients; i++) {
        if (client_sockets[i] == client_socket) {
            for (int j = i; j < num_clients - 1; j++) {
                client_sockets[j] = client_sockets[j + 1];
            }
            num_clients--;
            break;
        }
    }
    close(client_socket);
    pthread_exit(NULL);
}

void send_all_clients(const char *message, int sender_socket) {
    for (int i = 0; i < num_clients; i++) {
        if (client_sockets[i] != sender_socket) {
            send(client_sockets[i], message, strlen(message), 0);
        }
    }
}