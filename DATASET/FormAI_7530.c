//FormAI DATASET v1.0 Category: Chat server ; Style: statistical
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define PORT 8800
#define MAX_CLIENTS 10

// function declarations
void *handle_client(void *);

// global variables
int client_count = 0;
int client_sockets[MAX_CLIENTS];
pthread_mutex_t client_mutex = PTHREAD_MUTEX_INITIALIZER;

int main(int argc, char *argv[]) {
    int socket_fd, client_fd;
    struct sockaddr_in server, client;
    
    // create a socket
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        perror("Error creating socket");
        exit(1);
    }
    
    // set up server address
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);
    
    // bind socket to server address
    if (bind(socket_fd, (struct sockaddr *) &server, sizeof(server)) < 0) {
        perror("Error binding socket");
        exit(1);
    }
    
    // set socket to listen mode
    if (listen(socket_fd, MAX_CLIENTS) < 0) {
        perror("Error in listen mode");
        exit(1);
    }
    
    // accept client connections
    printf("Chat server running on port %d\n", PORT);
    while (1) {
        pthread_t client_thread;
        socklen_t client_len = sizeof(client);
        client_fd = accept(socket_fd, (struct sockaddr *) &client, &client_len);
        if (client_fd < 0) {
            perror("Error in accepting client");
            exit(1);
        }
        
        // add client socket to list
        pthread_mutex_lock(&client_mutex);
        if (client_count < MAX_CLIENTS) {
            client_sockets[client_count++] = client_fd;
            pthread_create(&client_thread, NULL, handle_client, (void *) &client_fd);
        } else {
            close(client_fd);
            printf("Maximum number of clients reached.\n");
        }
        pthread_mutex_unlock(&client_mutex);
    }
    
    // close server socket
    close(socket_fd);
    
    return 0;
}

void *handle_client(void *arg) {
    int client_fd = *((int *) arg);
    char buffer[256];
    int n;
    while (1) {
        // read message from client
        bzero(buffer, 256);
        n = read(client_fd, buffer, 255);
        if (n < 0) {
            perror("Error in reading from client");
            close(client_fd);
            pthread_exit(NULL);
        }
        
        // send message to all other clients
        pthread_mutex_lock(&client_mutex); 
        for (int i = 0; i < client_count; i++) {
            if (client_sockets[i] != client_fd) {
                n = write(client_sockets[i], buffer, strlen(buffer));
                if (n < 0) {
                    perror("Error in writing to client");
                    close(client_sockets[i]);
                    pthread_exit(NULL);
                }
            }
        }
        pthread_mutex_unlock(&client_mutex);
    }
    pthread_exit(NULL);
}