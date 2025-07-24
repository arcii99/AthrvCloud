//FormAI DATASET v1.0 Category: Socket programming ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>

int main()
{
    printf("Let's start coding with Sockets!\n");
    printf("==================================\n");

    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;

    // Creating a socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if(server_socket == -1)
    {
        printf("Oops! Socket creation failed.\n");
        exit(1);
    }
    else
    {
        printf("Successfully created a socket.\n");
    }

    // Specifying an address for the server socket
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9002);
    server_address.sin_addr.s_addr = INADDR_ANY;

    // Binding the socket to the specified IP and port
    if(bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1)
    {
        printf("Oops! Socket binding failed.\n");
        exit(1);
    }
    else
    {
        printf("Socket binding successful.\n");
    }

    // Listening for incoming connections
    if(listen(server_socket, 5) == -1)
    {
        printf("Oops! Listening failed.\n");
        exit(1);
    }
    else
    {
        printf("Listening for incoming connections...\n");
    }

    socklen_t client_address_size = sizeof(client_address);

    // Accepting incoming connections
    client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_size);

    if(client_socket == -1)
    {
        printf("Oops! Connection failed.\n");
        exit(1);
    }
    else
    {
        printf("Connection successful.\n");
    }

    char message[100] = "Hello Client! This is the Server speaking...\n";
    send(client_socket, message, sizeof(message), 0);

    printf("Message sent to the client.\n");

    close(client_socket);
    close(server_socket);

    printf("Connection closed.\n");
    printf("==================================\n");

    return 0;
}