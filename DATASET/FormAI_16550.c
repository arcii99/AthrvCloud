//FormAI DATASET v1.0 Category: Socket programming ; Style: automated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10

int client_count = 0;
int client_sockets[MAX_CLIENTS];
pthread_t threads[MAX_CLIENTS];

void * handle_client(void * arg){
    int client_socket = *(int *) arg;
    char buffer[1024];
    while(1){
        memset(buffer, 0, 1024);
        int n = read(client_socket, buffer, 1024);
        if(n <= 0){
            close(client_socket);
            return NULL;
        }
        printf("Message from client %d: %s\n", client_socket, buffer);
        for(int i=0; i<client_count; i++){
            if(client_sockets[i] != client_socket){
                write(client_sockets[i], buffer, n);
            }
        }
    }
}

int main(int argc, char const *argv[]){
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_length = sizeof(client_address);

    // Creating socket file descriptor
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == 0){
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind socket to specified IP and Port
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address))<0){
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) < 0){
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connections
    while(1){
        printf("Waiting for incoming connections...\n");
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_length);
        if(client_socket < 0){
            perror("Accept failed");
            continue;
        }
        printf("New client connected with ID: %d\n", client_socket);

        // Add client socket to array
        client_sockets[client_count] = client_socket;

        // Create thread to handle client communication
        if(pthread_create(&threads[client_count], NULL, handle_client, &client_sockets[client_count]) != 0){
            perror("Thread creation failed");
            continue;
        }

        // Increase client count
        client_count++;

        // Limit number of clients
        if(client_count == MAX_CLIENTS){
            printf("Max clients reached. Server is full.\n");
            break;
        }
    }

    // Close all client connections
    for(int i=0; i<client_count; i++){
        close(client_sockets[i]);
        pthread_cancel(threads[i]);
    }

    // Close server socket
    close(server_socket);

    return 0;
}