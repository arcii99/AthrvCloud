//FormAI DATASET v1.0 Category: Chat server ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

pthread_t thread_id[MAX_CLIENTS];   // Thread identifiers for MAX_CLIENTS threads.
int chats[MAX_CLIENTS];             // Client sockets
bool active_clients[MAX_CLIENTS];   // To keep track of active clients.
pthread_mutex_t lock;
char buffer[BUFFER_SIZE];

void* chat(void* arg) 
{
    int client_index = *((int*)arg);
    int client_socket = chats[client_index];

    while (true) 
    {
        memset(buffer, '\0', BUFFER_SIZE);  
        int recv_status = recv(client_socket, buffer, BUFFER_SIZE, 0);

        if (recv_status <= 0) 
        {
            printf("Client %d disconnected\n", client_index);
            close(client_socket);
            active_clients[client_index] = false;
            break;
        }

        // Send received message to all other active clients.
        pthread_mutex_lock(&lock);

        for (int i = 0; i < MAX_CLIENTS; ++i) 
        {
            if (active_clients[i] && i != client_index) 
            {
                send(chats[i], buffer, strlen(buffer), 0);
            }
        }

        pthread_mutex_unlock(&lock);
    }

    return NULL;
}

int main() 
{
    int server_socket, client_socket, opt = 1;
    struct sockaddr_in server_address, client_address;
    int address_length = sizeof(server_address);

    for (int i = 0; i < MAX_CLIENTS; ++i) 
    {
        chats[i] = 0;   // Initializing chats array to 0.
        active_clients[i] = false;
    }

    // Creates a TCP socket.
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
    {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options to reuse address and port.
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) 
    {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // Sets the server_address sockaddr_in structure with port and IP address.
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Binds server_socket to the server_address structure.
    if (bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) 
    {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming client connections.
    if (listen(server_socket, MAX_CLIENTS) < 0) 
    {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Chat server is running on port %d\n", PORT);

    while (true) 
    {
        // Accepts a new client connection and creates a socket descriptor.
        if ((client_socket = accept(server_socket, (struct sockaddr*)&client_address, (socklen_t*)&address_length)) < 0) 
        {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        // Adds the accepted client socket descriptor to chats array.
        for (int i = 0; i < MAX_CLIENTS; ++i) 
        {
            if (!active_clients[i]) 
            {
                chats[i] = client_socket;
                active_clients[i] = true;

                pthread_create(&thread_id[i], NULL, chat, (void*)&i);
                pthread_detach(thread_id[i]);

                printf("Client %d connected\n", i);

                break;
            }
        }

        memset(buffer, '\0', BUFFER_SIZE);
        strcpy(buffer, "You are now connected");
        send(client_socket, buffer, strlen(buffer), 0);
    }

    close(server_socket);
    return 0;
}