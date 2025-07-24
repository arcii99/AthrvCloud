//FormAI DATASET v1.0 Category: Chat server ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 4000
#define MAX_CLIENTS 5
#define BUFFER_SIZE 1024

void *client_handler(void *arg)
{
    int client_socket = *(int *)arg;
    char buffer[BUFFER_SIZE];
    int read_size;
    
    while((read_size = read(client_socket, buffer, BUFFER_SIZE)) > 0)
    {
        buffer[read_size] = '\0';
        printf("New message from client: %s", buffer);        
    }
    
    if(read_size == 0)
    {
        printf("Client disconnected\n");
    }
    else
    {
        printf("Read error\n");
    }
    
    close(client_socket);
}

int main()
{
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    pthread_t thread_id;
    
    // Create server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(server_socket < 0)
    {
        printf("Socket creation error\n");
        exit(EXIT_FAILURE);
    }
    
    // Bind server to IP address and port
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);
    
    if(bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
    {
        printf("Binding error\n");
        exit(EXIT_FAILURE);
    }
    
    // Listen for incoming connections
    if(listen(server_socket, MAX_CLIENTS) < 0)
    {
        printf("Listening error\n");
        exit(EXIT_FAILURE);
    }
    
    printf("Server is running on port %d\n", PORT);
    
    while(1)
    {
        // Accept client connections
        int client_address_size = sizeof(client_address);
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, (socklen_t *)&client_address_size);
        
        if(client_socket < 0)
        {
            printf("Connection error\n");
            continue;
        }
        
        printf("New client connected from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
        
        // Create a new thread to handle this client
        if(pthread_create(&thread_id, NULL, client_handler, (void *)&client_socket) < 0)
        {
            printf("Thread creation error\n");
            continue;
        }
        
        printf("Thread created for client\n");
        
        pthread_detach(thread_id);
    }
    
    return 0;
}