//FormAI DATASET v1.0 Category: Client Server Application ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <netinet/in.h>

#define PORT 8080

int main(int argc, char const *argv[])
{
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *hello = "Hello from server!";
    char RetroMessage[1024];

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                                                  &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );

    // Binding the socket to the address
    if (bind(server_fd, (struct sockaddr *)&address,
                                 sizeof(address))<0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listening for any incoming requests
    if (listen(server_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    printf("\n\n\n\n");
    printf("*------------------------------*\n");
    printf("| Welcome to Retro Chat Server |\n");
    printf("*------------------------------*\n");

    // Accepting incoming requests and handling each one
    while(1)
    {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                           (socklen_t*)&addrlen))<0)
        {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        valread = read( new_socket , buffer, 1024);
        printf("Client: %s\n", buffer);
        printf("Server: ");
        fgets(RetroMessage, 1024, stdin);     
        RetroMessage[strcspn(RetroMessage, "\n")] = '\0'; // Remove trailing newline character
        
        //Sending message to client
        send(new_socket , RetroMessage , strlen(RetroMessage) , 0 );
        printf("\n");

        // If client sends exit message
        if(strcmp("exit", RetroMessage) == 0)
        {
            printf("*---------------------------------------*");
            printf("\n|Retro Chat Server is shutting down now.|\n");
            printf("*---------------------------------------*\n");
            break;
        }
        memset(buffer,0,strlen(buffer));         
    }
    return 0;
}