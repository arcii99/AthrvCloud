//FormAI DATASET v1.0 Category: Chat server ; Style: real-life
// This C Chat Server program allows multiple clients to connect and communicate with each other via TCP/IP protocol.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_CLIENTS 100
#define BUFFER_SIZE 2048

// Global variables
int client_count = 0;
int client_sockets[MAX_CLIENTS];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Function prototypes
void *handle_client(void *arg);
void broadcast(char *message, int sender_socket);

int main(int argc, char **argv) 
{
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    pthread_t thread;

    // Create socket for server
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
    {
        perror("socket failed");
        exit(1);
    }

    // Set server address properties
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(12345);

    // Bind server socket to address
    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) 
    {
        perror("bind failed");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_socket, 10) < 0) 
    {
        perror("listen failed");
        exit(1);
    }

    // Loop to accept incoming connections
    while (1) 
    {
        socklen_t client_address_length = sizeof(client_address);

        // Accept connection from client
        if ((client_socket = accept(server_socket, (struct sockaddr *) &client_address, &client_address_length)) < 0) 
        {
            perror("accept failed");
            exit(1);
        }

        // Add client socket to array
        pthread_mutex_lock(&mutex);
        client_sockets[client_count++] = client_socket;
        pthread_mutex_unlock(&mutex);

        // Create thread for client
        if (pthread_create(&thread, NULL, handle_client, (void*) &client_socket) != 0) 
        {
            perror("pthread_create failed");
            exit(1);
        }

        // Detach thread for client
        if (pthread_detach(thread) != 0) 
        {
            perror("pthread_detach failed");
            exit(1);
        }

        printf("Connection accepted from %s:%d. Client ID: %d\n",
               inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port), client_count);
    }

    return 0;
}

// Thread function to handle client communication
void *handle_client(void *arg) 
{
    int client_socket = *((int*) arg);
    char buffer[BUFFER_SIZE];

    while (1) 
    {
        memset(buffer, 0, sizeof(buffer));

        // Receive message from client
        int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);

        // Check for disconnection or error
        if (bytes_received <= 0) 
        {
            pthread_mutex_lock(&mutex);

            for (int i = 0; i < client_count; i++) 
            {
                if (client_sockets[i] == client_socket) 
                {
                    client_count--;
                    client_sockets[i] = client_sockets[client_count];
                    break;
                }
            }

            pthread_mutex_unlock(&mutex);

            close(client_socket);
            break;
        }

        // Broadcast message to all clients
        broadcast(buffer, client_socket);
    }

    return NULL;
}

// Function to broadcast message to all clients except sender
void broadcast(char *message, int sender_socket) 
{
    pthread_mutex_lock(&mutex);

    for (int i = 0; i < client_count; i++) 
    {
        if (client_sockets[i] != sender_socket) 
        {
            if (send(client_sockets[i], message, strlen(message), 0) < 0) 
            {
                perror("send failed");
                exit(1);
            }
        }
    }

    pthread_mutex_unlock(&mutex);
}