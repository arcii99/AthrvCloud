//FormAI DATASET v1.0 Category: Smart home automation ; Style: distributed
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
 
#define SERVER_PORT 5000
#define BUFFER_SIZE 1024
 
int main(int argc, char const *argv[])
{
    int server_socket;
    struct sockaddr_in server_address;
    char buffer[BUFFER_SIZE] = {0};
 
    // Creating server socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("Socket creation error");
        return -1;
    }
 
    // Specifying server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(SERVER_PORT);
 
    // Binding socket to address
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
    {
        perror("Binding failed");
        return -1;
    }
 
    // Listening for client requests
    if (listen(server_socket, 3) < 0)
    {
        perror("Listen failed");
        return -1;
    }
 
    // Connection loop
    while (1)
    {
        int client_socket;
        struct sockaddr_in client_address;
        int address_size = sizeof(client_address);
 
        // Accepting client connection
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_address, (socklen_t *)&address_size)) < 0)
        {
            perror("Accept failed");
            return -1;
        }
 
        // Receiving client message
        int message_size = read(client_socket, buffer, BUFFER_SIZE);
 
        if (message_size < 0)
        {
            perror("Receive failed");
            return -1;
        }
 
        // Printing received message
        printf("Received message: %s\n", buffer);
 
        // Closing client connection
        close(client_socket);
    }
 
    // Closing server socket
    close(server_socket);
 
    return 0;
}