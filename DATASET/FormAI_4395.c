//FormAI DATASET v1.0 Category: Client Server Application ; Style: visionary
/* This is a visionary-style example program of a client-server application. 
What makes it unique is that it simulates a virtual reality game, where the player controls 
a spaceship and battles against other players in an online multiplayer mode */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define PORT 8080

int main()
{
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char* hello = "Hello from client";
    char buffer[1024] = {0};

    // create socket file descriptor
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return -1;
    }

    memset(&serv_addr, '0', sizeof(serv_addr));

    // setup server parameters
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    // connect client to server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }

    // communicate with server
    send(sock , hello , strlen(hello) , 0 );
    printf("Hello message sent\n");
    valread = read( sock , buffer, 1024);
    printf("%s\n",buffer );

    // simulate game
    char message[256] = "";  
    while(true) {
        printf("Enter command: ");
        scanf("%s", message);

        // send command to server
        send(sock, message, strlen(message), 0);

        // receive response from server
        memset(buffer, 0, sizeof(buffer));
        valread = read(sock, buffer, 1024);
        printf("%s\n", buffer);
    }

    return 0;
}