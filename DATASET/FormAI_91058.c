//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main()
{
    int client_socket;
    struct sockaddr_in server_address;
    char buffer[BUFFER_SIZE];
    char message[BUFFER_SIZE];
   
    // create a TCP socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1)
    {
        printf("Oh no! There was an error creating the socket.\n");
        exit(1);
    }
    printf("Socket created.\n");

    // set the server address and port number to connect
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_address.sin_port = htons(8080);

    // connect to the server
    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
    {
        printf("Holy cow! Failed to connect.\n");
        exit(1);
    }
    printf("Connection established with the server.\n\n");

    while(1)
    {
        printf("Client: ");
        fgets(message, BUFFER_SIZE, stdin);

        // send the message to the server
        if (send(client_socket, message, strlen(message), 0) < 0)
        {
            printf("Darn it! Failed to send message.\n");
            exit(1);
        }

        // receive the server's response
        if(recv(client_socket, buffer, BUFFER_SIZE, 0) < 0)
        {
            printf("Yikes! Failed to receive message from server.\n");
            exit(1);
        }
        printf("Server: %s", buffer);

        // clear the buffer
        memset(buffer, 0, BUFFER_SIZE);
    }

    // close the socket
    close(client_socket);

    return 0;
}