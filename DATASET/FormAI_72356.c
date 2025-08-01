//FormAI DATASET v1.0 Category: Chat server ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() 
{
    int server_fd, new_socket; 
    struct sockaddr_in address; 
    int addrlen = sizeof(address); 
    char buffer[BUFFER_SIZE] = {0}; 

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed"); 
        exit(EXIT_FAILURE); 
    }

    // Set address information
    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons(PORT); 

    // Bind the socket to a specific address and port
    if (bind(server_fd, (struct sockaddr *)&address,  sizeof(address)) < 0)
    { 
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    } 

    // Listen for incoming client connections
    if (listen(server_fd, 3) < 0)
    { 
        perror("listen failed"); 
        exit(EXIT_FAILURE); 
    } 

    printf("Waiting for client connection...\n");

    // Accept incoming client connection
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address,  
                       (socklen_t*)&addrlen))<0)
    { 
        perror("accept failed"); 
        exit(EXIT_FAILURE); 
    } 

    printf("Client connected!\n");

    while(1) 
    {
        memset(buffer, 0, BUFFER_SIZE);

        // Read client message
        if(read(new_socket , buffer, BUFFER_SIZE) <= 0)
            break;

        printf("Received message: %s\n", buffer);

        // Convert client message to upper case
        for(int i = 0; i < strlen(buffer); i++)
            buffer[i] = toupper(buffer[i]);

        // Send the upper case message back to client
        send(new_socket , buffer , strlen(buffer) , 0 ); 
    }

    printf("Client disconnected...\n");
    close(new_socket);
    close(server_fd);
    return 0; 
}