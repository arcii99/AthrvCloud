//FormAI DATASET v1.0 Category: Socket programming ; Style: detailed
// C socket programming example program
// This program creates a server that can handle multiple clients simultaneously by using threads.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>
 
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024
 
void *client_handler(void *);
 
int main(int argc, char *argv[])
{
    int server_sock, client_sock, i;
    struct sockaddr_in server_addr, client_addr;
    pthread_t thread_id;
     
    //Create TCP socket
    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock == -1)
    {
        printf("Error creating socket\n");
        exit(EXIT_FAILURE);
    }
     
    // Prepare the sockaddr_in structure
    memset(&server_addr, 0, sizeof(struct sockaddr_in));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8888);
     
    // Bind
    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        printf("Error binding socket\n");
        exit(EXIT_FAILURE);
    }

    // Listen
    if(listen(server_sock, MAX_CLIENTS) == -1)
    {
        printf("Error listening on the socket\n");
        exit(EXIT_FAILURE);
    }
     
    printf("Waiting for incoming connections...\n");
     
    while(1)
    {
        socklen_t client_addr_len = sizeof(client_addr);
        client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &client_addr_len);
         
        if (client_sock < 0)
        {
            printf("Error accepting connection\n");
            exit(EXIT_FAILURE);
        }

        printf("New client connected - IP: %s - Port: %d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
         
        if(pthread_create(&thread_id, NULL, client_handler, (void*)&client_sock) < 0)
        {
            printf("Error creating thread\n");
            exit(EXIT_FAILURE);
        }
    }
     
    // Close the socket
    close(server_sock);
     
    return 0;
}
 
void *client_handler(void *client_socket)
{
    int sock = *(int*)client_socket;
    char buffer[BUFFER_SIZE];
    int read_size;
     
    // Send welcome message to the client
    char *welcome_message = "Welcome to the server!\r\n";
    write(sock, welcome_message, strlen(welcome_message));
     
    while((read_size = recv(sock, buffer, BUFFER_SIZE, 0)) > 0 )
    {
        buffer[read_size] = '\0';
        printf("Received message from client: %s\n", buffer);
         
        // Send the message back to client
        write(sock, buffer, strlen(buffer));
    }
     
    if(read_size == 0)
    {
        printf("Connection closed by client\n");
    }
    else if(read_size == -1)
    {
        printf("Error while receiving data\n");
    }
         
    // Free the socket pointer
    free(client_socket);
     
    return 0;
}