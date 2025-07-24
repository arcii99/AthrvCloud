//FormAI DATASET v1.0 Category: Chat server ; Style: distributed
/* A unique C Chat server example program in a distributed style */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

// a structure to store client information
typedef struct {
    int socketfd;
    struct sockaddr_in address;
    char username[50];
} client_t;

// global array to store all connected clients
client_t clients[MAX_CLIENTS];
pthread_mutex_t mutex_clients;

// function to broadcast messages to all connected clients
void broadcast_message(char* message, int current_client) {
    pthread_mutex_lock(&mutex_clients);

    for(int i=0; i<MAX_CLIENTS; i++) {
        if(clients[i].socketfd > 0 && i != current_client) {
            send(clients[i].socketfd, message, strlen(message), 0);
        }
    }
    
    pthread_mutex_unlock(&mutex_clients);
}

// function to handle client communication
void* handle_client(void* arg) {
    client_t* client = (client_t*) arg;
    char buffer[BUFFER_SIZE];
    int read_size;

    // prompt the client to set a username
    send(client->socketfd, "Enter username: ", strlen("Enter username: "), 0);
    recv(client->socketfd, client->username, sizeof(client->username), 0);
    printf("%s has joined the chat.\n", client->username);

    // send a welcome message to the client
    char welcome_message[BUFFER_SIZE];
    sprintf(welcome_message, "Welcome %s!\n", client->username);
    send(client->socketfd, welcome_message, strlen(welcome_message), 0);

    // loop to receive and broadcast messages
    while((read_size = recv(client->socketfd, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[read_size] = '\0';
        char message[BUFFER_SIZE];
        sprintf(message, "%s: %s", client->username, buffer);
        broadcast_message(message, client - clients);
    }

    // client disconnected
    printf("%s has left the chat.\n", client->username);

    // close the socket
    close(client->socketfd);

    // clear the client struct
    pthread_mutex_lock(&mutex_clients);

    for(int i=0; i<MAX_CLIENTS; i++) {
        if(&clients[i] == client) {
            clients[i].socketfd = -1;
            strcpy(clients[i].username, "");
            break;
        }
    }

    pthread_mutex_unlock(&mutex_clients);

    // exit the thread
    pthread_exit(NULL);
}

int main() {
    // initialize the mutex
    pthread_mutex_init(&mutex_clients, NULL);

    // initialize the clients array
    for(int i=0; i<MAX_CLIENTS; i++) {
        clients[i].socketfd = -1;
        strcpy(clients[i].username, "");
    }

    // create a socket for incoming connections
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(server_socket == -1) {
        printf("Error: Failed to create socket.\n");
        exit(1);
    }

    // bind the socket to a local address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8080);

    if(bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address)) < 0) {
        printf("Error: Failed to bind socket.\n");
        exit(1);
    }

    // listen for incoming connections
    if(listen(server_socket, 5) < 0) {
        printf("Error: Failed to listen for incoming connections.\n");
        exit(1);
    }

    printf("Server started. Waiting for clients...\n");

    // accept incoming connections and create a new thread for each client
    struct sockaddr_in client_address;
    socklen_t client_address_length = sizeof(client_address);

    while(1) {
        int client_socket = accept(server_socket, (struct sockaddr*) &client_address, &client_address_length);
        if(client_socket < 0) {
            printf("Error: Failed to accept client connection.\n");
            continue;
        }

        pthread_mutex_lock(&mutex_clients);

        int i;
        for(i=0; i<MAX_CLIENTS; i++) {
            if(clients[i].socketfd == -1) {
                clients[i].socketfd = client_socket;
                clients[i].address = client_address;
                break;
            }
        }

        if(i == MAX_CLIENTS) {
            printf("Error: Too many clients.\n");
            close(client_socket);
            continue;
        }

        pthread_mutex_unlock(&mutex_clients);

        pthread_t thread;
        if(pthread_create(&thread, NULL, handle_client, &clients[i])) {
            printf("Error: Failed to create thread.\n");
            continue;
        }
    }

    return 0;
}