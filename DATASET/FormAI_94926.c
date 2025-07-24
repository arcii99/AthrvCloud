//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <pthread.h>
#include <time.h>
#include <sys/time.h>

#define MAX_CLIENTS 5
#define BUFFER_SIZE 1024

int clients[MAX_CLIENTS];
int client_count = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void handle_client(int client_socket)
{
    char buffer[BUFFER_SIZE];
    int received_size;
    int sent_size;
    
    while ((received_size = recv(client_socket, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[received_size] = '\0';
        printf("Received message: %s", buffer);
        // do some QoS monitoring and analysis here
        sent_size = send(client_socket, buffer, received_size, 0);
        if (sent_size != received_size) {
            printf("Error: failed to send message back to client\n");
            break;
        }
    }
    
    if (received_size == 0) {
        printf("Client disconnected\n");
    } else if (received_size == -1) {
        printf("Error: failed to receive message from client\n");
    }
    
    close(client_socket);
    
    pthread_mutex_lock(&mutex);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i] == client_socket) {
            clients[i] = -1;
            break;
        }
    }
    pthread_mutex_unlock(&mutex);
    
    pthread_exit(NULL);
}

void sigint_handler(int sig)
{
    printf("\nReceived SIGINT, shutting down server...\n");
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i] != -1) {
            close(clients[i]);
        }
    }
    exit(0);
}

int main(int argc, char **argv)
{
    int server_socket;
    int client_socket;
    struct sockaddr_in server_address;
    struct sockaddr_in client_address;
    socklen_t client_address_len;
    
    signal(SIGINT, sigint_handler);
    
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error: failed to create server socket\n");
        exit(1);
    }
    
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8888);
    
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        printf("Error: failed to bind server socket\n");
        exit(1);
    }
    
    if (listen(server_socket, MAX_CLIENTS) == -1) {
        printf("Error: failed to listen on server socket\n");
        exit(1);
    }
    
    printf("Server started, waiting for connections...\n");
    
    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_len);
        if (client_socket == -1) {
            printf("Error: failed to accept client connection\n");
            continue;
        }
        
        printf("Client connected: %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
        
        pthread_mutex_lock(&mutex);
        if (client_count < MAX_CLIENTS) {
            for (int i = 0; i < MAX_CLIENTS; i++) {
                if (clients[i] == -1) {
                    clients[i] = client_socket;
                    client_count++;
                    pthread_t thread;
                    pthread_create(&thread, NULL, (void *)handle_client, (void *)client_socket);
                    break;
                }
            }
        } else {
            printf("Error: maximum number of clients reached\n");
            close(client_socket);
        }
        pthread_mutex_unlock(&mutex);
    }
    
    return 0;
}