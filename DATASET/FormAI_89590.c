//FormAI DATASET v1.0 Category: Networking ; Style: random
/*
* This program creates a chat application. It uses basic client server architecture.
* The client can send messages to the server and the server can broadcast them to all the clients.
* The clients can also receive messages sent by other clients.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<pthread.h>

#define MAX_CLIENTS 5
#define BUFFER_SIZE 256

// Structure to store client details
typedef struct{
    int sock_fd; // Socket File Descriptor
    char name[BUFFER_SIZE]; // Name of the client
}client;

client clients[MAX_CLIENTS]; // Array to store client details
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // Mutex used to lock shared resources

// Handles sending messages to all clients except the sender
void broadcast_message(int sender_sock_fd, char* message){
    pthread_mutex_lock(&mutex); // Locks the mutex to access shared resources
    for(int i=0; i<MAX_CLIENTS; i++){
        if(clients[i].sock_fd != 0 && clients[i].sock_fd != sender_sock_fd){ // Loop through clients except the sender
            write(clients[i].sock_fd, message, strlen(message)); // Send message to client
        }
    }
    pthread_mutex_unlock(&mutex); // Unlock the mutex after accessing the shared resources
}

// Handles messages from clients
void* handle_client(void* args){
    client* current_client = (client*) args;
    char message[BUFFER_SIZE];
    while(1){
        int read_size = read(current_client->sock_fd, message, BUFFER_SIZE); // Read message from client
        if(read_size > 0){ // Check if message is valid
            message[read_size] = '\0';
            broadcast_message(current_client->sock_fd, message); // Broadcast the message to all clients except the sender
        }
    }
    return NULL;
}

int main(int argc, char* argv[]){

    int server_sock_fd, client_sock_fd;
    struct sockaddr_in server_address, client_address;

    // Create a socket
    server_sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(server_sock_fd == -1){
        printf("Error: Could not create socket\n");
        return 1;
    }

    // Fill in server details
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8888);

    // Bind socket to server address
    if(bind(server_sock_fd, (struct sockaddr*) &server_address, sizeof(server_address)) < 0){
        printf("Error: Could not bind socket\n");
        return 1;
    }

    // Listen for incoming connections
    listen(server_sock_fd, 3);

    // Wait for incoming connections
    printf("Waiting for clients...\n");
    int n = 0;
    while(n < MAX_CLIENTS){
        int client_address_len = sizeof(client_address);
        client_sock_fd = accept(server_sock_fd, (struct sockaddr*) &client_address, (socklen_t*) &client_address_len);
        if(client_sock_fd < 0){
            printf("Error: Could not accept connection\n");
            continue;
        }

        // Add new client to the list of clients
        pthread_mutex_lock(&mutex);
        strcpy(clients[n].name, "Unnamed"); // Default name of unnamed clients
        clients[n].sock_fd = client_sock_fd;
        printf("Client %d connected\n", n+1);
        pthread_create(&clients[n], NULL, handle_client, (void*) &clients[n]); // Create new thread to handle client messages
        n++;
        pthread_mutex_unlock(&mutex);
    }

    // Close all sockets
    for(int i=0; i<MAX_CLIENTS; i++){
        if(clients[i].sock_fd != 0){
            close(clients[i].sock_fd);
        }
    }
    close(server_sock_fd);

    return 0;
}