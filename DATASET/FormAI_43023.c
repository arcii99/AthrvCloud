//FormAI DATASET v1.0 Category: Chat server ; Style: peaceful
/* Example Chat Server Program in C*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define PORT 8080

void * handle_connection(void *);

int main(int argc, char const *argv[])
{
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    pthread_t thread_id;

    // Create a socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("Could not create socket");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("Could not set socket options");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind socket to address
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, MAX_CLIENTS) < 0)
    {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server is up and running\n");
    printf("Listening on port %d\n", PORT);

    while(1)
    {
        // Wait for incoming connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, 
            (socklen_t*)&addrlen))<0)
        {
            perror("Accept failed");
            continue;
        }

        // Create new thread to handle connection
        if (pthread_create(&thread_id, NULL, handle_connection, (void *)&new_socket) < 0)
        {
            perror("Could not create thread");
            continue;
        }

        printf("New connection accepted\n");
    }

    return 0;
}

// Handle Client Connection
void * handle_connection(void * socket_fd)
{
    int new_socket = *(int *)socket_fd;
    char buffer[1024] = {0};
    int valread;

    while(1)
    {
        // Read incoming message from client
        valread = read( new_socket , buffer, 1024);

        // If message is 'quit' break loop and close connection
        if (strcmp(buffer, "quit\n") == 0)
        {
            printf("Connection closed\n");
            close(new_socket);
            break;
        }

        // Print message from client
        printf("Client: %s\n", buffer);

        // Echo message back to client
        send(new_socket , buffer , strlen(buffer) , 0 );
        memset(buffer, 0, 1024);
    }

    return NULL;
}