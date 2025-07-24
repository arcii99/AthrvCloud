//FormAI DATASET v1.0 Category: Socket programming ; Style: peaceful
/*
* FILE: peaceful_server.c
* USAGE: ./server
* DESCRIPTION: A socket program to demonstrate server-client communication using TCP protocol.
* AUTHOR: Peaceful Programmer

* NOTE: This code is inspired from a real-world example, however,
* this is not a production code and should not be treated as such.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080

int main()
{
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *hello = "Hello from server";

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Attaching socket to the port 8080,
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                                                  &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );

    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *)&address,
                                 sizeof(address))<0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                       (socklen_t*)&addrlen))<0)
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    // connection established
    printf("Connection established with client\n");

    while(1)
    {
        valread = read( new_socket , buffer, 1024);

        if(valread == 0) {
            printf("Client has disconnected\n");
            break;
        }

        printf("Client: %s\n",buffer );

        if(strcmp(buffer, "quit\n") == 0) {
            break;
        }
        send(new_socket , hello , strlen(hello) , 0 );
        printf("Server: Message sent to client\n");
    }

    // Closing the socket
    close(new_socket);
    close(server_fd);

    return 0;
}