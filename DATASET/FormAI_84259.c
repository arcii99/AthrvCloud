//FormAI DATASET v1.0 Category: Chat server ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <pthread.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>

#define PORT 5000
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int server_socket;
int client_sockets[MAX_CLIENTS];
pthread_t client_threads[MAX_CLIENTS];

void handle_signal(int signal) {
    for(int i=0; i<MAX_CLIENTS; i++) {
        if(client_sockets[i] != -1) {
            close(client_sockets[i]);
        }
    }
    close(server_socket);
    exit(EXIT_SUCCESS);
}

void *handle_client(void *client_socket) {
    int socket = *(int*)client_socket;
    char buffer[BUFFER_SIZE];
    while(true) {
        int read_size = read(socket, buffer, BUFFER_SIZE);
        if(read_size == 0) {
            printf("Client disconnected.\n");
            fflush(stdout);
            close(socket);
            break;
        }
        for(int i=0; i<MAX_CLIENTS; i++) {
            if(client_sockets[i] != -1 && client_sockets[i] != socket) {
                write(client_sockets[i], buffer, read_size);
            }
        }
    }
    return NULL;
}

int main() {
    // initialize client sockets
    for(int i=0; i<MAX_CLIENTS; i++) {
        client_sockets[i] = -1;
    }

    // create server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(server_socket == -1) {
        printf("Error creating server socket.\n");
        exit(EXIT_FAILURE);
    }

    // set server socket options
    int opt = 1;
    if(setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) == -1) {
        printf("Error setting server socket options.\n");
        exit(EXIT_FAILURE);
    }

    // bind server socket
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);
    if(bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        printf("Error binding server socket.\n");
        exit(EXIT_FAILURE);
    }

    // listen for clients
    if(listen(server_socket, MAX_CLIENTS) == -1) {
        printf("Error listening for clients.\n");
        exit(EXIT_FAILURE);
    }

    // set signal handler for clean exit
    signal(SIGINT, handle_signal);

    // accept and handle clients
    while(true) {
        struct sockaddr_in client_address;
        int client_socket = accept(server_socket, (struct sockaddr*)&client_address, (socklen_t*)&client_address);
        if(client_socket == -1) {
            printf("Error accepting client.\n");
            continue;
        }

        bool added = false;
        for(int i=0; i<MAX_CLIENTS; i++) {
            if(client_sockets[i] == -1) {
                client_sockets[i] = client_socket;
                pthread_create(&client_threads[i], NULL, handle_client, (void*)&client_socket);
                printf("Client connected.\n");
                fflush(stdout);
                added = true;
                break;
            }
        }

        if(!added) {
            printf("Client limit reached. Closing connection.\n");
            close(client_socket);
        }
    }

    return 0;
}