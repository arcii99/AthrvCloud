//FormAI DATASET v1.0 Category: Client Server Application ; Style: imaginative
/* Welcome to the World of Imaginative C Client Server Program! */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 8080
#define MAX_BUFFER_SIZE 1024

int main(int argc, char const *argv[]) 
{
    int server_socket_fd, new_socket_fd, valread;
    struct sockaddr_in server_address;
    int addrlen = sizeof(server_address);
    char buffer[MAX_BUFFER_SIZE] = {0};
    char *message = "Successfully connected!";

    // Creating socket file descriptor
    if ((server_socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
    {
        printf("Could not create socket file descriptor!");
        return -1;
    }

    // Assigning IP and PORT to the server
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Binding the socket with the server address
    if (bind(server_socket_fd, (struct sockaddr *)&server_address, sizeof(server_address))<0) 
    {
        printf("Could not bind the socket with the server address!");
        return -1;
    }

    // Listening for incoming connections
    if (listen(server_socket_fd, 3) < 0) 
    {
        printf("Could not listen for incoming connections!");
        return -1;
    }

    // Accepting incoming connections
    if ((new_socket_fd = accept(server_socket_fd, (struct sockaddr *)&server_address, (socklen_t*)&addrlen))<0) 
    {
        printf("Could not accept the incoming connection!");
        return -1;
    }

    // Sending message to client
    send(new_socket_fd , message , strlen(message) , 0 );
    printf("Message sent to client: %s\n", message);

    // Receiving message from client
    valread = read( new_socket_fd , buffer, MAX_BUFFER_SIZE);
    printf("Message received from client: %s\n",buffer );

    // Closing the connection
    close(new_socket_fd);
    close(server_socket_fd);

    return 0;
}