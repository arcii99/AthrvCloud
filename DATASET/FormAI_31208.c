//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: standalone
// This program demonstrates a TCP/IP client-server connection
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080

int main(int argc, char *argv[])
{
    int listen_socket, accept_socket, addrlen, new_socket, valread;
    struct sockaddr_in server_address, client_address;
    char buffer[1024] = {0};
    char *hello = "Hello from server";
    
    listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    
    if (listen_socket == 0)
    {
        printf("Error: Socket creation failed.\n");
        return -1;
    }
    
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons( PORT );
    
    if (bind(listen_socket, (struct sockaddr *)&server_address, sizeof(server_address))<0)
    {
        printf("Error: Bind failed.\n");
        return -1;
    }
    
    if (listen(listen_socket, 3) < 0)
    {
        printf("Error: Listen failed.\n");
        return -1;
    }
    
    addrlen = sizeof(client_address);
    
    if ((accept_socket = accept(listen_socket, (struct sockaddr *)&client_address, (socklen_t*)&addrlen))<0)
    {
        printf("Error: Accept failed.\n");
        return -1;
    }
    
    // Receive a message from the client
    valread = read( accept_socket , buffer, 1024);
    printf("%s\n",buffer );
    memset(buffer, 0, sizeof(buffer));
    
    // Send a message to the client
    send(accept_socket , hello , strlen(hello) , 0 );
    printf("Hello message sent\n");
    
    // Close the connection
    close(accept_socket);
    close(listen_socket);
    
    return 0;
}