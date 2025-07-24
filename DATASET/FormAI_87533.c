//FormAI DATASET v1.0 Category: Client Server Application ; Style: Cyberpunk
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<ctype.h>
#include<string.h>

#define PORT 8080

void handle_client(int client_socket)
{
    char message[100], response[100];
    int message_size;

    printf("Client connected successfully!\n\n");

    while(1)
    {
        // Receiving message from client
        bzero(message, sizeof(message));
        printf("Waiting for client message...\n");
        message_size = read(client_socket, message, sizeof(message));
        printf("Client message received: %s\n", message);

        // Converting message to uppercase
        for(int i = 0; i < strlen(message); i++)
        {
            response[i] = toupper(message[i]);
        }

        // Sending converted message back to client
        write(client_socket, response, sizeof(response));
    }
}

int main()
{
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    int address_size = sizeof(server_address);

    // Creating socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(server_socket == -1)
    {
        printf("Could not create socket!\n");
        return -1;
    }
    printf("Socket created successfully!\n");

    // Binding socket to port
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(PORT);

    if(bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) != 0)
    {
        printf("Could not bind socket to port!\n");
        return -1;
    }
    printf("Socket bound successfully to port %d!\n", PORT);

    // Listening for incoming connections
    if(listen(server_socket, 5) != 0)
    {
        printf("Could not listen on socket!\n");
        return -1;
    }
    printf("Server started listening on port %d...\n", PORT);

    while(1)
    {
        // Accepting client connection
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, &address_size);
        if(client_socket < 0)
        {
            printf("Error accepting client connection!\n");
            return -1;
        }

        // Handling client
        handle_client(client_socket);

        // Closing client connection
        close(client_socket);
        printf("Client disconnected from server!\n\n");
    }

    // Closing server socket
    close(server_socket);
    printf("Server closed successfully!\n");

    return 0;
}