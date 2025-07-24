//FormAI DATASET v1.0 Category: Chat server ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>

#define MAX_CLIENTS 100
#define BUFFER_SIZE 1024

int clients[MAX_CLIENTS];

void closeSocket(int socket)
{
    close(socket);
}

int main()
{
    int server_socket, new_socket;
    struct sockaddr_in server, cli;
    char *message = "Hello client, I am Ken Thompson's Chat Server\n";

    //create server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(server_socket == -1)
    {
        perror("Could not create socket");
        return 1;
    }

    //prepare server sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( 8888 );

    //bind
    if( bind(server_socket,(struct sockaddr *)&server , sizeof(server)) < 0)
    {
        perror("Bind failed. Error");
        return 1;
    }

    //listen
    listen(server_socket , 3);

    //accept incoming connections
    puts("Waiting for incoming connections...");
    int c = sizeof(struct sockaddr_in);
    int num_clients = 0;
    char buffer[BUFFER_SIZE];

    while(1)
    {
        //accept connection from incoming client
        new_socket = accept(server_socket, (struct sockaddr *)&cli, (socklen_t*)&c);
        if (new_socket < 0)
        {
            perror("Connection failed");
            return 1;
        }
        printf("Connection accepted from %s:%d\n", inet_ntoa(cli.sin_addr), ntohs(cli.sin_port));

        //send a welcome message to the client
        if( send(new_socket, message, strlen(message), 0) != strlen(message) )
        {
            perror("Send failed");
        }

        //store socket descriptor in clients array
        clients[num_clients++] = new_socket;

        //handle received messages
        int i, received_bytes;
        for(i=0; i < num_clients; i++)
        {
            //clear the buffer
            memset(buffer, 0, BUFFER_SIZE);

            received_bytes = recv(clients[i], buffer, BUFFER_SIZE, 0);

            if( received_bytes > 0 )
            {
                printf("Received message: %s\n", buffer);

                //broadcast the message to all clients
                int j;
                for(j=0; j < num_clients; j++)
                {
                    if(clients[j] != clients[i])
                    {
                        if( send(clients[j], buffer, strlen(buffer), 0) != strlen(buffer) )
                        {
                            perror("Failed to send message");
                        }
                    }
                }
            }
        }
    }

    //close all sockets
    for(int i=0; i < num_clients; i++)
    {
        closeSocket(clients[i]);
    }
    closeSocket(server_socket);  
    return 0;
}