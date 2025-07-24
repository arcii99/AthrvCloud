//FormAI DATASET v1.0 Category: Chat server ; Style: Sherlock Holmes
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<arpa/inet.h>

int main()
{
    printf("Listening to clients...\n");
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    
    if( server_socket < 0 ) 
    {
        printf("Error in creating socket.\n");
        return -1;
    }
    
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    server_address.sin_addr.s_addr = INADDR_ANY;
    
    int bind_status = bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));
    
    if( bind_status < 0 ) 
    {
        printf("Error in binding the socket.\n");
        return -1;
    }
    
    listen(server_socket, 5);
    struct sockaddr_in client_address;
    int client_socket = accept(server_socket, (struct sockaddr*) &client_address, sizeof(client_address));
    
    printf("Connected to a client!\n");

    char message[100];
    bzero(message, 100);
    read(client_socket, message, sizeof(message));
    printf("Message from client: %s\n", message);

    close(client_socket);
    close(server_socket);

    return 0;
}