//FormAI DATASET v1.0 Category: Chat server ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 9009

int main()
{
    //declaring variables
    int server_socket, new_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t sin_size = sizeof(struct sockaddr_in);
    char buffer[1024];
    int bytes_received;

    //creating socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    //checking if the socket was created successfully
    if(server_socket < 0)
    {
        printf("Error creating socket");
        return 0;
    }

    //setting server address information
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;
    memset(&(server_addr.sin_zero), '\0', 8);

    //binding the socket to the specified IP address and port number
    if(bind(server_socket, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) == -1)
    {
        printf("Error binding socket");
        return 0;
    }

    //listening for incoming connections
    if(listen(server_socket, 5) == -1)
    {
        printf("Error listening for incoming connections");
        return 0;
    }

    printf("Server is listening on port %d\n", PORT);

    while(1)
    {
        //accepting incoming connection
        new_socket = accept(server_socket, (struct sockaddr *)&client_addr, &sin_size);

        //checking if the connection was accepted successfully
        if(new_socket == -1)
        {
            printf("Error accepting incoming connection");
            return 0;
        }

        printf("Client %s:%d connected\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        //sending welcome message to the client
        char *welcome_message = "Welcome to the chat server!\n";
        send(new_socket, welcome_message, strlen(welcome_message), 0);

        while(1)
        {
            //receiving data from client
            bytes_received = recv(new_socket, buffer, 1024, 0);

            //checking if data was received successfully
            if(bytes_received == -1)
            {
                printf("Error receiving data from client");
                break;
            }

            //checking if client has disconnected
            if(bytes_received == 0)
            {
                printf("Client %s:%d has disconnected\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
                break;
            }

            //printing received message from client
            buffer[bytes_received] = '\0';
            printf("Client %s:%d says: %s", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port), buffer);
        }

        close(new_socket);
    }

    close(server_socket);

    return 0;
}