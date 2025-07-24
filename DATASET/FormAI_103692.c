//FormAI DATASET v1.0 Category: Simple Web Server ; Style: sophisticated
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <sys/socket.h> 
#include <netinet/in.h>
#include <arpa/inet.h> 

#define PORT 8080 
#define BUFFER_SIZE 1024

int main(int argc, char const *argv[]) 
{
    int server_fd, new_socket, valread; 
    struct sockaddr_in address; 
    int addrlen = sizeof(address); 
    char buffer[BUFFER_SIZE] = {0}; 
    char *hello = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<html><body><h1>Hello World!</h1></body></html>"; 

    // Creating socket file descriptor 
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
    { 
        printf("Socket creation failed\n"); 
        return -1; 
    } 

    // Forcefully attaching socket to the port 8080 
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR , &(int){1}, sizeof(int)) < 0 ) 
    { 
        printf("setsockopt failed\n"); 
        return -1; 
    } 
    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons(PORT); 

    // Binding the socket to the port 8080 
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) 
    { 
        printf("Binding failed\n"); 
        return -1; 
    } 

    //Listening for connections 
    if (listen(server_fd, 3) < 0) 
    { 
        printf("Listen failed\n"); 
        return -1; 
    } 

    printf("Server running on port %d\n", PORT);

    while(1)
    {
        // Accepting client connections 
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) 
        { 
            printf("Accept failed\n"); 
            return -1; 
        } 

        // Reading request message from client 
        valread = read( new_socket , buffer, BUFFER_SIZE); 
        printf("%s\n",buffer ); 

        // Sending response message to client 
        send(new_socket , hello , strlen(hello) , 0 ); 
        printf("Response sent\n"); 
        close(new_socket);
    }
    return 0; 
}